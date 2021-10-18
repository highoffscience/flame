/**
 * @author Forrest Jablonski
 */

#pragma once

#include "Standard.h"

#include <thread>

namespace ym
{

class ThreadPool
{
public:
   explicit ThreadPool(void);
   explicit ThreadPool(uint32 const Size);
   ~ThreadPool(void);

   YM_NO_COPY(  ThreadPool);
   YM_NO_ASSIGN(ThreadPool);

   void stopAllThreads(void);

private:
   uint32 const _Size;
   bool         _isClosing;

   void worker(void);
};

} // ym
