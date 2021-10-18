/**
 * @author Forrest Jablonski
 */

#include "ThreadPool.h"

/**
 *
 */
ym::ThreadPool::ThreadPool(void)
   : ThreadPool(std::thread::hardware_concurrency() > 0u ?
                std::thread::hardware_concurrency()     :
                8u)
{
}

/**
 *
 */
ym::ThreadPool::ThreadPool(uint32 const Size)
   : _Size      {Size },
     _isClosing {false}
{
}

/**
 *
 */
ym::ThreadPool::~ThreadPool(void)
{
   stopAllThreads();
}

/**
 *
 */
void ym::ThreadPool::stopAllThreads(void)
{
   _isClosing = true;
}

/**
 *
 */
void ym::ThreadPool::worker(void)
{

}
