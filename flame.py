##
# @file    flame.py
# @version 1.0.0
# @author  Forrest Jablonski
#

import argparse
import json
import os
import subprocess as sp
import sys

def runCmd(cmd: str, cwd: str=".", per_line_action_func=None, quiet: bool=False):
   """
   @brief Runs command and optionally runs an action function on every line of the output.
   """
   output = None
   with sp.Popen(cmd.split(), stdout=sp.PIPE, stderr=sp.STDOUT, text=True, cwd=cwd) as p:
      if per_line_action_func:
         for line in iter(p.stdout.readline, ""):
            per_line_action_func(line)
      else:
         output, _ = p.communicate()
      if not quiet:
         print(f"Command '{cmd}' exited with code {p.poll()}")
   return output

def write_cs_scripts(cfg):
   """
   @brief Pixel::dim_t const Clr -> Pixel
   """
   def write_monochrome(cfg):
      r, g, b = float(cfg["clr"][0]), \
                float(cfg["clr"][1]), \
                float(cfg["clr"][2])
      return f"""
         constexpr Pixel PxlColor({r}, {g}, {b});\n
         return PxlColor * Clr;                  \n
      """
   def write_bichrome(cfg):
      r1, g1, b1 = float(cfg["c1"][0]), \
                   float(cfg["c1"][1]), \
                   float(cfg["c1"][2])
      r2, g2, b2 = float(cfg["c2"][0]), \
                   float(cfg["c2"][1]), \
                   float(cfg["c2"][2])
      return f"""
         text += f'constexpr Pixel C1({r1}, {g1}, {b1});\n'
         text += f'constexpr Pixel C2({r2}, {g2}, {b2});\n'
         text += f'constexpr auto Alpha(C2 - C1);       \n'
         text += f'return (Alpha * Clr) + Begin;        \n'
      """
   
   handlers = {
      "monochrome": write_monochrome,
      "bichrome"  : write_bichrome
   }
   
   active_cs = cfg["active"]
   text = handlers[active_cs](cfg[active_cs])
   with open("./src/scripts/colorscheme.script", "w") as f:
      f.write("/// @file colorscheme.script\n")
      f.write("///                         \n")
      f.write("/// @note AUTO-GENERATED    \n")
      f.write("///                         \n")
      f.write(text)

def write_vb_scripts(cfg, nXforms):
   """
   @brief (ym::uint32 const Transform_idx, Point const P) -> Point
   """
   def write_identity(cfg):
      return f"return P;\n"
   
   handlers = {
      "identity": write_identity
   }

   active_sa      = cfg["strangor"]["active"]
   active_vbs     = cfg["strangor"][active_sa]["varblends"]
   active_weights = cfg["strangor"][active_sa]["weights"]

   if nXforms != len(active_weights):
      print(f"nXforms {nXforms} must equal len(active_weights) {len(active_weights)}!")
      sys.exit(1)

   with open("./src/scripts/varblend.script", "w") as f:
      f.write(f"/// @file varblend.script                             \n")
      f.write(f"///                                                   \n")
      f.write(f"/// @note AUTO-GENERATED                              \n")
      f.write(f"///                                                   \n")
      f.write(f"constexpr ym::uint32 NTransforms = {nXforms}u         \n")
      f.write(f"constexpr ym::uint32 NVars       = {len(active_vbs)}u \n")
      f.write(f"                                                      \n")
      f.write( "constexpr Point::dim_t Weights[NTransforms][NVars] = {\n")
      for xFormWeights in active_weights:
         if len(active_vbs) != len(xFormWeights):
            print(f"len(active_vbs) {len(active_vbs)} must equal len(xFormWeights) {len(xFormWeights)}!")
         f.write("{")
         for weight in xFormWeights:
            f.write(f"{weight},")
         f.write("},\n")
      f.write("};\n")

def write_sa_scripts(cfg):
   """
   @brief TODO.
   """
   def write_heighway_dragon(cfg):
      text = """
         {.A =  0.5, .B = -0.5, .C = 0.5, .D =  0.5, .E = 0.0, .F = 0.0, .Clr = 0.0, .Prob = 0.5},
         {.A = -0.5, .B = -0.5, .C = 0.5, .D = -0.5, .E = 1.0, .F = 0.0, .Clr = 1.0, .Prob = 0.5}
      """
      return (2, text)
   def write_maple_leaf(cfg):
      text = """
         {.A = 0.14, .B =  0.01, .C =  0.0 , .D = 0.51, .E = -0.08, .F = -1.31, .Clr = 0.0/3.0, .Prob = 0.25},
         {.A = 0.43, .B =  0.52, .C = -0.45, .D = 0.5 , .E =  1.49, .F = -0.75, .Clr = 1.0/3.0, .Prob = 0.25},
         {.A = 0.45, .B = -0.49, .C =  0.47, .D = 0.47, .E = -1.62, .F = -0.74, .Clr = 2.0/3.0, .Prob = 0.25},
         {.A = 0.49, .B =  0.0 , .C =  0.0 , .D = 0.51, .E =  0.02, .F =  1.62, .Clr = 3.0/3.0, .Prob = 0.25}
      """
      return (4, text)
   
   handlers = {
      "heighway_dragon": write_heighway_dragon,
      "maple_leaf"     : write_maple_leaf
   }

   active_sa = cfg["strangor"]["active"]
   (nXforms, text) = handlers[active_sa](cfg["strangor"][active_sa])
   with open("./src/strangor.script", "w") as f:
      f.write("/// @file strangor.script\n")
      f.write("///                      \n")
      f.write("/// @note AUTO-GENERATED \n")
      f.write("///                      \n")
      f.write(text)

   write_vb_scripts(cfg, nXforms)

def parse_json(args):
   cfg = json.loads(args.config)
   write_cs_scripts(cfg["colorscheme"])
   write_sa_scripts(cfg)

def main():
   """
   @brief Main function.
   """
   parser = argparse.ArgumentParser()
   parser.add_argument("--sa", help="strangor",    default="heighway_dragon", type=str)
   parser.add_argument("--vb", help="varblend",    default="identity",        type=str)
   parser.add_argument("--cs", help="colorscheme", default="bispectrum",      type=str)
   args = parser.parse_args()

   # TODO

   runCmd("cmake --build build/", per_line_action_func=lambda line: print(line, end=""))

# kick-off
if __name__ == "__main__":
   main()
else:
   print("Meant to run stand-alone - not to be imported")
   sys.exit(1)
