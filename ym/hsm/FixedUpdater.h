/**
 * @author Forrest Jablonski
 */

#pragma once

#include "Standard.h"

#include "Updater.h"

namespace ym::hsm
{

class FixedUpdater : public Updater
{
public:
   explicit FixedUpdater(char const * const Name_Ptr,
                         uint32       const BlackboxSize_sec,
                         uint32       const InitHerz);

private:
   void taskLoop(void);
};

} // ym::hsm
