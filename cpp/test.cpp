struct Point
{
   constexpr Point(void) : Point(0, 0) {}
   constexpr Point(int const x_, int const y_) : x{x_}, y{y_} {}

   constexpr Point mns(Point const & P) const
   {
      return {x-P.x, y-P.y};
   }

   int x;
   int y;
};

#include <iostream>

int main(void)
{
   constexpr Point a(3, 4);
   constexpr Point b(7, 9);
   constexpr Point p(a.mns(b));
   static_assert(p.x==-4);
   return 0;
}
