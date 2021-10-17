/**
 * @author Forrest Jablonski
 */

#include "SignalHandler.h"

#include <csignal>

volatile SignalTower_T gSignalTower = SignalTower_T::Default;

/**
 * Only registered to catch SIGABRT
 */
void signalHandler(int signum)
{
   gSignalTower = SignalTower_T::Default;

   if (signum == SIGABRT)
   {
      gSignalTower = SignalTower_T::AssertWithSigAbort;
   }
}

/**
 *
 */
void registerSignalHandler()
{
   std::signal(SIGABRT, signalHandler);
}
