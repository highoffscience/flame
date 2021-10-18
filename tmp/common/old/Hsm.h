/**
 * @author Forrest Jablonski
 */

#pragma once

#include "Standard.h"

#include "HsmEvents.h"
#include "Nameable.h"
#include "SmartLink.h"

#include <vector>

/**
 *
 */
#define YM_HSM_DECL_STATE(HsmClassName,                                           \
                          StateName,                                              \
                          parent_Ptr)                                             \
   void StateName(Event * const e_Ptr);                                           \
   State const _##StateName = State(#StateName,                                   \
                              static_cast<StateFunc_T>(&HsmClassName::StateName), \
                              parent_Ptr) /* force semi-colon */

namespace ym::hsm
{

class Topic;

/**
 * Hierarchical State Machine
 */
class Hsm : public CNameable_NV,
            public SmartLink
{
/*
 *                                    State
 * -------------------------------------------------------------------------- */

protected:
   typedef void (Hsm::*StateFunc_T)(Event * const e_Ptr);

   /**
    *
    */
   class State : public CNameable_NV
   {
   public:
      explicit State(SStr_T      const Name,
                     StateFunc_T const StateFunc,
                     State *     const parent_Ptr);

      inline void dispatch(Hsm   * const hsm_Ptr,
                           Event * const e_Ptr) const;

      inline auto getParentPtr(void) const { return _parent_Ptr; }
      inline auto getDepth    (void) const { return _Depth;      }

   private:
      static uint32 getDepth(State const * State_ptr);

      State *     const _parent_Ptr;
      StateFunc_T const _StateFunc;
      uint32      const _Depth;
   };

/*
 *                                    Hsm
 * -------------------------------------------------------------------------- */

public:
   explicit Hsm(SStr_T  const Name,
                State * const root_Ptr);

   virtual ~Hsm(void) = default;

   virtual void init(void);

   inline auto isInitialized(void) const { return _curr_ptr != nullptr; }

   template <typename Event_T>
   inline bool dispatch(Event_T * const e_Ptr);

protected:
   void transTo(State * const goal_Ptr);

private:
   State * const        _root_Ptr;
   State *              _curr_ptr;
   State *              _goal_ptr;
   std::vector<State *> _ancestorsOfGoal;
   bool                 _isTransitioning;

   void publish(Topic * const topic_Ptr);

   bool dispatch_Helper(Event * const e_Ptr);

   template <> inline bool dispatch(EntryEvent * const e_Ptr);
   template <> inline bool dispatch(ExitEvent  * const e_Ptr);
   
   void transitionToGoalState        (void);
   void transitionExitSequence       (ExitEvent  * const e_Ptr);
   void propagateThroughInitialStates(EntryEvent * const e_Ptr);
};

/*
 *                                    State
 * -------------------------------------------------------------------------- */

/**
 *
 */
inline void Hsm::State::dispatch(Hsm   * const hsm_Ptr,
                                 Event * const e_Ptr) const
{
   (hsm_Ptr->*_StateFunc)(e_Ptr);
}

/*
 *                                    Hsm
 * -------------------------------------------------------------------------- */

/**
 *
 */
template <typename Event_T>
inline bool Hsm::dispatch(Event_T * const e_Ptr)
{
   return dispatch_Helper(e_Ptr);
}

/**
 *
 */
template <>
inline bool Hsm::dispatch(EntryEvent * const e_Ptr)
{
   _isTransitioning = true;
   _curr_ptr->dispatch(this, e_Ptr);
   _isTransitioning = false;
   return true;
}

/**
 *
 */
template <>
inline bool Hsm::dispatch(ExitEvent * const e_Ptr)
{
   _isTransitioning = true;
   _curr_ptr->dispatch(this, e_Ptr);
   _isTransitioning = false;
   return true;
}

} // ym::hsm
