/**
 * @author Forrest Jablonski
 */

/*
 * These are global because the signal handler expects a global function
 */

#ifndef _FCT_UNITTEST_SIGNALHANDLER_H_
#define _FCT_UNITTEST_SIGNALHANDLER_H_

enum class SignalTower_T
{
   Default,
   AssertWithSigAbort
};

extern volatile SignalTower_T gSignalTower;

static void signalHandler(int signum);

void registerSignalHandler(); // should be called in main()

#endif // _FCT_UNITTEST_SIGNALHANDLER_H_
