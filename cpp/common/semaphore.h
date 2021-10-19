/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"

#include <atomic>
#include <condition_variable>
#include <mutex>

namespace hoso
{

/**
 *
 */
class Semaphore
{
public:
   explicit Semaphore(int32 const MaxCount);

   HOSO_NO_COPY  (Semaphore);
   HOSO_NO_ASSIGN(Semaphore);

   inline auto getInitCount(void) const { return _InitCount; }

   inline auto getCount(void) const { return _count.load(std::memory_order_relaxed); }

   bool post(void);
   bool wait(void);

private:
   // TODO reorder variables
   std::mutex              _debtCountGuard;
   std::condition_variable _cv;
   std::atomic<int32>      _count;
   int32                   _debtCount;
   int32 const             _InitCount;
};

} // hoso
