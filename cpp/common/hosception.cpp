/**
 * @author Forrest Jablonski
 */

#include "hosception.h"

std::atomic<hoso::uint32> hoso::Hosception::_s_tagCount(0);

/**
 *
 */
hoso::Hosception::Hosception(void)
   : _Tag {_s_tagCount.fetch_add(1, std::memory_order_relaxed)}
{
}
