/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"

#include <chrono>

namespace hoso
{

typedef std::chrono::steady_clock Clock_T;
typedef Clock_T::time_point       Time_T;
typedef int64                     TimeRep_T;

/*
 * Convenience functions.
 * -------------------------------------------------------------------------- */

template <typename TimeUnit_T>
inline TimeRep_T hosoGetGlobalTime(void);

template <typename TimeUnit_T>
inline TimeRep_T hosoGetElapsedTime(Time_T const StartTime);

/* -------------------------------------------------------------------------- */

/**
 *
 */
class Timer
{
public:
   HOSO_NO_DEFAULT(Timer);

   template <typename TimeUnit_T>
   friend TimeRep_T hosoGetGlobalTime(void);

private:
   static Time_T const _s_GlobalStartTime;
};

/**
 * TimeUnit_T is std::milli, for example
 */
template <typename TimeUnit_T>
inline TimeRep_T hosoGetElapsedTime(Time_T const StartTime)
{
   return std::chrono::duration_cast<std::chrono::duration<TimeRep_T, TimeUnit_T>>(Clock_T::now() - StartTime).count();
}

/**
 * TimeUnit_T is std::milli, for example
 */
template <typename TimeUnit_T>
inline TimeRep_T hosoGetGlobalTime(void)
{
   return ymGetElapsedTime<TimeUnit_T>(Timer::_s_GlobalStartTime);
}

} // hoso
