/**
 * @author Forrest Jablonski
 */

#include <iostream>
#include <array>
#include <vector>
#include <random>

int main(void)
{
   //const std::vector<double> v{1.2, 3.6, 2.7, 2.4};
   //const std::array<double, 4> v{1.2, 3.6, 2.7, 2.4};
   const double v[] = {1.2, 3.6, 2.7, 2.4};
   //double* v = new double[4];
   //v[0] = 1.2;
   //v[1] = 3.6;
   //v[2] = 2.7;
   //v[3] = 2.4;

   //std::default_random_engine randGen;
   //std::discrete_distribution<int> dist = {1, 2, 2, 5};

   //std::vector<int> v(1000000000);

   double elapsed_time = clock();

   double sum = 0.0;
   
   for (int i = 0; i < 1000000000; ++i)
   //for (const auto& c : v)
   {
      sum += v[i%4];
      //sum += c;

      if (i%113 == 0)
      {
         sum += 2.0 * v[(i+3)%4];
      }
   }

   elapsed_time = (clock()-elapsed_time) / CLOCKS_PER_SEC;

   std::cout << "Sum of " << sum << " took " << elapsed_time << "(s)" << std::endl;

   return 0;
}
