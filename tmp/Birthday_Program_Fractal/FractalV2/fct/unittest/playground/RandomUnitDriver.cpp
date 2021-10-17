/**
 * @author Forrest Jablonski
 */

#include <iostream>
#include <random>
#include <ctime>
#include <boost/random.hpp>

/**
 *
 */
class Random
{

private:

   boost::random::mt19937 _randGen;
   const double _randMax; // doubles are faster than floats (discovered during unittesting)

public:

   /**
    *
    */
   inline explicit Random()
     : _randGen{(uint)std::time(0)},
       _randMax(_randGen.max())
   { }

   /**
    * Generates 0..1 inclusive
    *  ie. [0..1]
    */
   inline double genUniformReal() { return _randGen() / _randMax; }

}; // Random

int main(void)
{
   //std::mt19937 randGen = std::mt19937(19);
   //std::mt19937 randGen = std::mt19937((std::random_device())());
   //std::time_t now = std::time(0);
   //boost::random::mt19937 randGen{(unsigned int)std::time(0)};
   //const double M = randGen.max();
   //boost::random::mt19937 rng(43);
   //boost::random::uniform_01<boost::random::mt19937> randGen(rng);

   //std::cout << randGen.min() << ", " << randGen.max() << std::endl;

   //std::default_random_engine randGen;
   //std::discrete_distribution<char> dist = {0.25, 0.5, 0.25};
   //boost::random::uniform_int_distribution<> dist{1, 100};

   Random randGen = Random();

   double elapsed_time = clock();

   double sum = 0.0;
   //double sum[] = {0.0, 0.0, 0.0};
   for (int i = 0; i < 1000000000; ++i)
   {
      //double r = std::generate_canonical<double, 32>(randGen);
      //double r = randGen() / M;
      //double r = xorshf96();
      //sum += r;
      //double r = randGen();
      double r = randGen.genUniformReal();
      sum += r;
      //int j = dist(randGen);
      //++sum[j];
   }

   elapsed_time = (clock()-elapsed_time) / CLOCKS_PER_SEC;

   std::cout << "Sum of " << sum << " took " << elapsed_time << "(s)" << std::endl;
   //std::cout << "Sum of " << sum[0] << ", " << sum[1] << ", " << sum[2] << " took " << elapsed_time << "(s)" << std::endl;

   return 0;
}
