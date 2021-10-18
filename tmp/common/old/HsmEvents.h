/**
 * @author Forrest Jablonski
 */

#pragma once

#include "Standard.h"

#include "Event.h"

namespace ym::hsm
{
   YM_EVT_DECL_EMPTY(EntryEvent      );
   YM_EVT_DECL_EMPTY(ExitEvent       );
   YM_EVT_DECL_EMPTY(EntryActionEvent);
} // ym::hsm
