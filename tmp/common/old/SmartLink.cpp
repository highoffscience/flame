/**
 * @author Forrest Jablonski
 */

#include "SmartLink.h"

/**
 *
 */
ym::SmartLink::SmartLink(void)
   : _dependents { }
{
}

/**
 *
 */
ym::SmartLink::SmartLink(uint32 const NExpectedDependents)
   : _dependents { }
{
   _dependents.reserve(NExpectedDependents);
}

/**
 *
 */
ym::SmartLink::~SmartLink(void)
{
   for (auto * dependent_Ptr : _dependents)
   {
      dependent_Ptr->unlink(this);
   }
}

/**
 *
 */
void ym::SmartLink::link(SmartLink * const dependent_Ptr)
{
   bool stillNeedToAdd = true; // until told otherwise

   for (uint32 i = 0; i < _dependents.size(); ++i)
   {
      if (_dependents[i] == nullptr)
      {
         _dependents[i] = dependent_Ptr;
         stillNeedToAdd = false;
         break;
      }
   }

   if (stillNeedToAdd)
   {
      _dependents.emplace_back(dependent_Ptr);
   }

   stillNeedToAdd = true; // until told otherwise

   for (uint32 i = 0; i < dependent_Ptr->_dependents.size(); ++i)
   {
      if (dependent_Ptr->_dependents[i] == nullptr)
      {
         dependent_Ptr->_dependents[i] = this;
         stillNeedToAdd = false;
         break;
      }
   }

   if (stillNeedToAdd)
   {
      dependent_Ptr->_dependents.emplace_back(this);
   }
}

/**
 *
 */
void ym::SmartLink::unlink(SmartLink * const dependent_Ptr)
{
   for (uint32 i = 0; i < _dependents.size(); ++i)
   {
      if (_dependents[i] == dependent_Ptr)
      {
         _dependents[i] = nullptr;
         break;
      }
   }

   for (uint32 i = 0; i < dependent_Ptr->_dependents.size(); ++i)
   {
      if (dependent_Ptr->_dependents[i] == this)
      {
         dependent_Ptr->_dependents[i] = nullptr;
         break;
      }
   }
}
