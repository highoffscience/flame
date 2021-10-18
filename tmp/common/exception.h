/**
 * @author Forrest Jablonski
 */

#include "standard.h"

#include <exception>

namespace hoso
{

/**
 *
 */
class Exception : public std::exception
{
public:
   explicit inline Exception(str const Msg);
   virtual inline ~Excpetion(void) = default;
};

} // hoso
