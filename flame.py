##
# @file    flame.py
# @version 1.0.0
# @author  Forrest Jablonski
#

import argparse
import os
import subprocess as sp
import sys

def runCmd(cmd: str, cwd: str=".", per_line_action_func=None, quiet=False):
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

def main():
   """
   @brief Main function.
   """
   parser = argparse.ArgumentParser()
   parser.add_argument("--sa", help="strangor",    default="heighway_dragon", type=str)
   parser.add_argument("--vb", help="varblend",    default="identity",        type=str)
   parser.add_argument("--cs", help="colorscheme", default="bispectrum",      type=str)
   args = parser.parse_args()

   with open("./src/scripts/strangor/index.script", "w") as f:
      f.write("///                                            \n")
      f.write("/// @file index.script                         \n")
      f.write("///                                            \n")
      f.write("/// @note AUTO-GENERATED                       \n")
      f.write("///                                            \n")
      f.write("                                               \n")
      f.write(f"#include \"scripts/strangor/{args.sa}.script\"\n")

   with open("./src/scripts/varblend/index.script", "w") as f:
      f.write("///                                            \n")
      f.write("/// @file index.script                         \n")
      f.write("///                                            \n")
      f.write("/// @note AUTO-GENERATED                       \n")
      f.write("///                                            \n")
      f.write("                                               \n")
      f.write(f"#include \"scripts/varblend/{args.vb}.script\"\n")

   with open("./src/scripts/colorscheme/index.script", "w") as f:
      f.write("///                                               \n")
      f.write("/// @file index.script                            \n")
      f.write("///                                               \n")
      f.write("/// @note AUTO-GENERATED                          \n")
      f.write("///                                               \n")
      f.write("                                                  \n")
      f.write(f"#include \"scripts/colorscheme/{args.cs}.script\"\n")

   runCmd("cmake --build build/", per_line_action_func=lambda line: print(line, end=""))

# kick-off
if __name__ == "__main__":
   main()
else:
   print("Meant to run stand-alone - not to be imported")
   sys.exit(1)
