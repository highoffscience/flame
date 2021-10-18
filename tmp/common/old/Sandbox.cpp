/**
 * @author Forrest Jablonski
 */

#include "Standard.h"

#include "DataLogger.h"
#include "Event.h"
#include "Hsm.h"
#include "Random.h"
#include "SmartLink.h"
#include "TextLogger.h"
#include "TimerDefs.h"

#include <iostream>

class EntryEvent : public ym::hsm::Event
{
public:
   explicit EntryEvent(void)
      : Event {"EntryEvent", this}
   {}
};

int main_helper(void);
void sand(void);

/**
 * 
 */
int main(void)
{
   using namespace ym;

   ymLog(0, "Start of log. Global time is %lld (us).", ymGetGlobalTime<std::micro>());

   int returnCode = 0; // until told otherwise

   sand();

   // EntryEvent e;
   // ymLog(0, "Sig %lu", e.getSignal());
   // 
   // int returnCode = 1; // until told otherwise
   // 
   // try
   // {
   //    returnCode = main_helper();
   // }
   // catch (Ymception const & E)
   // {
   //    ymLog(0, "Ymception - %s", E.what());
   // }
   // catch (std::exception const & E)
   // {
   //    ymLog(0, "Exception - %s", E.what());
   // }

   return returnCode;
}

void sand(void)
{
   
}

/**
 * 
 */
int main_helper(void)
{
   using namespace ym;

   ymLog(0, "Start!");

   //Random<float32, std::uniform_real_distribution> rand(0.f, 10.f);

   DataLogger logger;

   uint32 frequency = 0;
   uint32 amplitude = 0;
   uint32 phase     = 0;
   bool   isCrit    = false;

   auto const Frequency_key = logger.add<decltype(frequency)>("Frequency", 20);
   auto const Amplitude_key = logger.add<decltype(amplitude)>("Amplitude", 20);
   auto const Phase_key     = logger.add<decltype(phase    )>("Phase",     20);
   auto const IsCrit_key    = logger.add<decltype(isCrit   )>("Critical",  20);

   for (uint32 i = 0; i < 100; ++i)
   {
      logger.store(Frequency_key, i *  7 /*rand.get()*/);
      logger.store(Amplitude_key, i * 11 /*rand.get()*/);
      logger.store(Phase_key,     i * 13 /*rand.get()*/);
      logger.store(IsCrit_key,    i %  2 == 0          );
   }

   logger.dump("data.csv");

   return 0;
}
