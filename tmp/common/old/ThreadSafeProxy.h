/**
 * @author Forrest Jablonski
 */

#pragma once

#include "Standard.h"

#include "PassKey.h"
#include "Ymception.h"

#include <memory>
#include <mutex>

namespace ym
{

/**
 *
 */
template <typename UnderlyingObj_T>
class ThreadSafeProxy
{
private:
   /**
    *
    */
   class Proxy
   {
   public:
      explicit inline Proxy(std::mutex      * const mtx_Ptr,
                            UnderlyingObj_T * const obj_Ptr);

      inline auto operator -> (void) const { return _obj_Ptr; }

   private:
      std::unique_lock<std::mutex> _lock;
      UnderlyingObj_T * const      _obj_Ptr;
   };

public:
   explicit ThreadSafeProxy(std::shared_ptr<UnderlyingObj_T> const & ObjSharedPtr);

   YM_PK_MAKE_TEMPLATE_1(Tsp_PK, ThreadSafeProxy);

   template <typename Target_T>
   explicit inline ThreadSafeProxy(std::shared_ptr<std::mutex> const & MtxSharedPtr,
                                   std::shared_ptr<Target_T>   const & ObjSharedPtr,
                                   Tsp_PK);

   template <typename Target_T>
   ThreadSafeProxy<Target_T> cast(void);

   Proxy operator -> (void);

private:
   std::shared_ptr<std::mutex>    _mtxSharedPtr;
   std::weak_ptr<UnderlyingObj_T> _objWeakPtr;
};

/**
 *
 */
template <typename UnderlyingObj_T>
inline ThreadSafeProxy<UnderlyingObj_T>::Proxy::Proxy(std::mutex      * const mtx_Ptr,
                                                      UnderlyingObj_T * const obj_Ptr)
   : _lock    {*mtx_Ptr},
     _obj_Ptr { obj_Ptr}
{
}

/**
 *
 */
template <typename UnderlyingObj_T>
ThreadSafeProxy<UnderlyingObj_T>::ThreadSafeProxy(std::shared_ptr<UnderlyingObj_T> const & ObjSharedPtr)
   : _mtxSharedPtr {std::make_shared<std::mutex>()},
     _objWeakPtr   {ObjSharedPtr                  }
{
}

/**
 *
 */
template <typename UnderlyingObj_T>
template <typename Target_T>
inline ThreadSafeProxy<UnderlyingObj_T>::ThreadSafeProxy(
                                            std::shared_ptr<std::mutex> const & MtxSharedPtr,
                                            std::shared_ptr<Target_T>   const & ObjSharedPtr,
                                            Tsp_PK)
   : _mtxSharedPtr {MtxSharedPtr},
     _objWeakPtr   {ObjSharedPtr}
{
}

/**
 *
 */
template <typename UnderlyingObj_T>
template <typename Target_T>
ThreadSafeProxy<Target_T> ThreadSafeProxy<UnderlyingObj_T>::cast(void)
{
   return ThreadSafeProxy<TargetType_T>(_mtxSharedPtr,
                                        std::static_pointer_cast<Target_T>(_objWeakPtr.lock()),
                                        ThreadSafeProxy<Target_T>::Tsp_PK());
}

/**
 *
 */
template <typename UnderlyingObj_T>
auto ThreadSafeProxy<UnderlyingObj_T>::operator -> (void) -> Proxy
{
   auto objSharedPtr = _objWeakPtr.lock();

   ymAssert(bool(objSharedPtr), "Proxy is no longer valid! No obj.");

   return Proxy(_mtxSharedPtr.get(), objSharedPtr.get());
}

} // ym
