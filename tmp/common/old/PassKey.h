/**
 * @author Forrest Jablonski
 */

#pragma once

#include "Standard.h"

/*
 * The pass key idiom is a lightweight solution to only granting access to functions to a select number of classes.
 * Effectively it makes functions selectively public.
 *
 * Example use:
 *
 * class Example
 * {
 * public:
 *     // should be public
 *     // allows classes Example and Minefield to access class functionName_PK's constructor
 *     YM_PK_MAKE_W1(functionName_PK, Example, Minefield);
 *
 *     // only classes Example and Minefield are able to call this function
 *     void functionName(functionName_PK);
 * };
 *
 */

/**
 * Helper class, do not use outside of this file.
 */
#define YM_PK_MAKE_HELPER(PKClassName, FullyQualifiedTrustees) \
   class PKClassName                                           \
   {                                                           \
   private:                                                    \
      explicit constexpr PKClassName(void) = default;          \
                                                               \
      FullyQualifiedTrustees                                   \
   }

/**
 * Only one class, Trustee, can use the pass key.
 */
#define YM_PK_MAKE_1(ClassName, Trustee) YM_PK_MAKE_HELPER(ClassName, friend class Trustee;)

/**
 * Only one template class (all specializations), Trustee, can use the pass key.
 */
#define YM_PK_MAKE_TEMPLATE_1(ClassName, Trustee) \
   YM_PK_MAKE_HELPER(ClassName, template <typename T> friend class Trustee;)

/**
 * Only two classes, Trustee1 and Trustee2, can use the pass key.
 */
#define YM_PK_MAKE_2(ClassName, Trustee1,                                                     \
                                Trustee2) YM_PK_MAKE_HELPER(ClassName, friend class Trustee1; \
                                                                       friend class Trustee2;)

/**
 * Only two template classes (all specializations), Trustee1 and Trustee2, can use the pass key.
 */
#define YM_PK_MAKE_TEMPLATE_2(ClassName, Trustee1,                           \
                                         Trustee2)                           \
   YM_PK_MAKE_HELPER(ClassName, template <typename T> friend class Trustee1; \
                                template <typename T> friend class Trustee2;)
