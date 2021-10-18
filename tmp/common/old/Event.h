/**
 * @author Forrest Jablonski
 */

#pragma once

#include "Standard.h"

#include "Nameable.h"
#include "TimerDefs.h"

/**
 *
 */
#define YM_EVT_DECL_EMPTY(Name)                       \
   class Name : public Event                          \
   {                                                  \
   public:                                            \
      explicit inline Name(void)                      \
         : Event {#Name, this}                        \
      {}                                              \
                                                      \
      explicit inline Name(TimeRep_T const TimeStamp) \
         : Event {#Name, TimeStamp, this}             \
      {}                                              \
   } /* force semi-colon */

namespace ym::hsm
{

/**
 * Base class for all hsm event objects.
 */
class Event : public CNameable_NV
{
public:
   typedef uint32 Signal_T; // must decay to uint32

   inline auto getSignal   (void) const { return _Signal;     }
   inline auto getTimeStamp(void) const { return _TimeStamp;  }
   inline auto isConsumed  (void) const { return _isConsumed; }

   inline operator Signal_T (void) const { return getSignal(); }

   inline void consume(void) { _isConsumed = true; }

   template <typename Derived_T>
   static Signal_T getClassSignal(void);

   template <typename DerivedTarget_T>
   inline bool is(void) const;

   template <typename DerivedTarget_T>
   inline DerivedTarget_T const * cast(void) const;

   template <typename DerivedTarget_T>
   DerivedTarget_T const * safeCast(void) const;

   template <typename DerivedTarget_T>
   inline bool cast(DerivedTarget_T const * & Msg_ptr_ref) const;

protected:
   template <typename Derived_T>
   explicit inline Event(SStr_T            const Name,
                         Derived_T const * const Dummy_Ptr); // TODO dummy variable name?

   template <typename Derived_T>
   explicit Event(SStr_T            const Name,
                  TimeRep_T         const TimeStamp,
                  Derived_T const * const /* dummy */);

private:
   static std::atomic<Signal_T> s_signalCounter;

   // TODO order members from greatest size to least size
   Signal_T  const _Signal;
   TimeRep_T const _TimeStamp;
   bool            _isConsumed;
};

/**
 *
 */
template <typename Derived_T>
inline Event::Event(SStr_T            const Name,
                    Derived_T const * const Dummy_Ptr)
   : Event {Name,
            ymGetGlobalTime<std::micro>(),
            Dummy_Ptr}
{
}

/**
 *
 */
template <typename Derived_T>
Event::Event(SStr_T            const Name,
             TimeRep_T         const TimeStamp,
             Derived_T const * const /* dummy */)
   : CNameable_NV {Name                       },
     _Signal      {getClassSignal<Derived_T>()},
     _TimeStamp   {TimeStamp                  },
     _isConsumed  {false                      }
{
}

/**
 *
 */
template <typename Derived_T>
auto Event::getClassSignal(void) -> Signal_T
{
   static Signal_T s_classSignal = 0;

   if (s_classSignal == 0)
   {
      s_classSignal = ++s_signalCounter;
   }

   return s_classSignal;
}

/**
 *
 */
template <typename DerivedTarget_T>
inline bool Event::is(void) const
{
   return getSignal() == DerivedTarget_T::getClassSignal();
}

/**
 * Functionally a dynamic down cast.
 * 
 * if (E->cast<ButtonPush>()) ...
 * 
 * if (auto const V = E->cast<ButtonPush>()) ...
 */
template <typename DerivedTarget_T>
inline DerivedTarget_T const * Event::cast(void) const
{
   return is<DerivedTarget_T>()                      ?
          static_cast<DerivedTarget_T const *>(this) :
          nullptr;
}

/**
 * Functionally a dynamic down cast.
 */
template <typename DerivedTarget_T>
DerivedTarget_T const * Event::safeCast(void) const
{
   auto const Target = cast<DerivedTarget_T>();

   ymAssert(Target != nullptr,
            "Casting to an incompatible event! Instance name/signal = %s/%lu, target class signal = %lu.",
            getName(), getSignal(), DerivedTarget_T::getClassSignal());

   return Target;
}

/**
 * Functionally a dynamic down cast.
 */
template <typename DerivedTarget_T>
inline bool Event::cast(DerivedTarget_T const * & Msg_ptr_ref) const
{
   Msg_ptr_ref = cast<DerivedTarget_T>();

   return Msg_ptr_ref != nullptr;
}

} // ym::hsm
