/**
 * @author Forrest Jablonski
 */

#include "Hsm.h"

#include "Event.h"
#include "HsmEvents.h"
#include "TextLogger.h"
#include "Topic.h"
#include "Ymception.h"

/*
 *                                    Hsm
 * -------------------------------------------------------------------------- */

/**
 *
 */
ym::hsm::Hsm::Hsm(SStr_T  const Name,
                  State * const root_Ptr)
   : CNameable_NV     {Name    },
     SmartLink        {        },
     _root_Ptr        {root_Ptr},
     _curr_ptr        {nullptr },
     _goal_ptr        {root_Ptr}, // we will transition here when init() is called
     _ancestorsOfGoal {        },
     _isTransitioning {false   }
{
   _ancestorsOfGoal.reserve(8);
}

/**
 *
 */
void ym::hsm::Hsm::init(void)
{
   if (!isInitialized())
   {
      EntryEvent entryEvent;
      propagateThroughInitialStates(&entryEvent);
   }
}

/**
 *
 */
void ym::hsm::Hsm::publish(Topic * const topic_Ptr)
{
   for (auto * const smartLink_Ptr : topic_Ptr->getDependents())
   {
      static_cast<Hsm *>(smartLink_Ptr)->dispatch(topic_Ptr->getEventPtr());
   }
}

/**
 *
 */
bool ym::hsm::Hsm::dispatch_Helper(Event * const e_Ptr)
{
   ymAssertDbg(*e_Ptr != Event::getClassSignal<EntryEvent>() &&
               *e_Ptr != Event::getClassSignal<ExitEvent >(),
               "Hsm %s - dispatch() cannot be used for entry or exit events!",
               getName());

   ymAssert(!_isTransitioning,
            "Hsm %s - dispatch() cannot be called in entry or exit events!",
            getName());

   init();

   auto * tempCurr_ptr = _curr_ptr;
   
   do
   {
      tempCurr_ptr->dispatch(this, e_Ptr);
   
      if (_goal_ptr != nullptr)
      { // transition requested
         transitionToGoalState();
         e_Ptr->consume();
      }
      else
      { // mom! dad!
         tempCurr_ptr = tempCurr_ptr->getParentPtr();
      }
   
   } while (!e_Ptr->isConsumed() &&   // stop if event was consumed
            tempCurr_ptr != nullptr); // stop if we polled root
   
   return e_Ptr->isConsumed();
}

/**
 *
 */
void ym::hsm::Hsm::transitionToGoalState(void)
{ 
   auto * goal_ptr = _goal_ptr;
   _goal_ptr       = nullptr;

   ExitEvent exitEvent;
   
   while (_curr_ptr->getDepth() > goal_ptr->getDepth())
   {
      transitionExitSequence(&exitEvent); // modifies _currState_ptr
   }

   _ancestorsOfGoal.clear();
   
   while (goal_ptr->getDepth() > _curr_ptr->getDepth())
   {
      _ancestorsOfGoal.emplace_back(goal_ptr);
      goal_ptr = goal_ptr->getParentPtr();
   }
   
   ymAssertDbg(_curr_ptr->getDepth() == goal_ptr->getDepth(),
               "Hsm %s - Nodes should have equal depth! curr-depth = %lu, goal-depth = %lu.",
               getName(),
               _curr_ptr->getDepth(),
               goal_ptr->getDepth());
   
   while (_curr_ptr != goal_ptr)
   {
      transitionExitSequence(&exitEvent); // modifies _currState_ptr

      _ancestorsOfGoal.emplace_back(goal_ptr);
      goal_ptr = goal_ptr->getParentPtr();
   }
   
   { // enter
      EntryEvent entryEvent;

      for (uint32 i = 1; i <= _ancestorsOfGoal.size(); ++i)
      {
         _goal_ptr = nullptr;
         _curr_ptr = _ancestorsOfGoal[_ancestorsOfGoal.size() - i];
         dispatch(&entryEvent);
      }

      propagateThroughInitialStates(&entryEvent);
   } // enter
}

/**
 *
 */
void ym::hsm::Hsm::transitionExitSequence(ExitEvent * const e_Ptr)
{
   dispatch(e_Ptr);
   _curr_ptr = _curr_ptr->getParentPtr();
   
   ymAssert(_goal_ptr == nullptr,
            "Hsm %s - State transition not allowed during exit event!",
            getName());
}

/**
 *
 */
void ym::hsm::Hsm::propagateThroughInitialStates(EntryEvent * const e_Ptr)
{
   while (_goal_ptr != nullptr)
   {
      ymAssert(_goal_ptr->getParentPtr() == _curr_ptr,
               "Hsm %s - Initial state must be a direct descendent of the current state!",
               getName());
   
      _curr_ptr = _goal_ptr; // we will be in current state after the call is made
      _goal_ptr = nullptr;
   
      dispatch(e_Ptr);
   }
   
   EntryActionEvent entryActionEvent;
   dispatch(&entryActionEvent);
}

/**
 *
 */
void ym::hsm::Hsm::transTo(State * const goal_Ptr)
{
   ymAssert(_goal_ptr == nullptr,
            "Hsm %s - Trying to transition more than once during same event!",
             getName());
   
   _goal_ptr = goal_Ptr;
}

/*
 *                                    State
 * -------------------------------------------------------------------------- */

/**
 *
 */
ym::hsm::Hsm::State::State(SStr_T      const Name,
                           StateFunc_T const StateFunc,
                           State *     const parent_Ptr)
   : CNameable_NV {Name                },
     _parent_Ptr  {parent_Ptr          },
     _StateFunc   {StateFunc           },
     _Depth       {getDepth(parent_Ptr)}
{
}

/**
 *
 */
auto ym::hsm::Hsm::State::getDepth(State const * State_ptr) -> uint32
{
   uint32 depth = 0;

   while (State_ptr != nullptr)
   {
      State_ptr = State_ptr->getParentPtr();
      depth++;
   }

   return depth;
}
