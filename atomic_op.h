#ifndef _ATOMIC_OP_H_
#define _ATOMIC_OP_H_

#if defined (_WIN32)

#include <WinSock2.h>
#include <Windows.h>

#endif

class AtomicOps {
public:
#if defined (_WIN32) 

static int Increment(volatile int* i) {
	return ::InterlockedIncrement(reinterpret_cast<volatile LONG*>(i));
}

static int Decrement(volatile int* i) {
	return ::InterlockedDecrement(reinterpret_cast<volatile LONG*>(i));
}

static int AcquireLoad(volatile const int*i) { return *i;}

static void ReleaseStore(volatile int* i, int value) { *i = value; }

static int CompareAndSwap(volatile int* i, int old_value, int new_value) {
	return ::InterlockedCompareExchange(reinterpret_cast<volatile LONG*>(i),new_value,old_value);
}

template <class T>
static T* AcquireLoadPtr(T* volatile* ptr) { return *ptr; }

template <class T>
static T* CompareAndSwapPtr(T* volatile* ptr, T* old_value, T* new_value) {
	return static_cast<T*> ( ::InterlocakedCompareExchange(reinterpret_cast<PVOID volatile* >(ptr), new_value,old_value));
}

#else
static int Increment(volatile int* i) { return __sync_add_and_fetch(i,1);}
static int Decrement(volatile int* i) { return __sync_sub_and_fetch(i,1);}

static int AcquireLoad(volatile int* i) { return __atomic_load_n(i, __ATOMIC_ACQUIRE); }
static void ReleaseStore(volatile int* i, int value) { __atomic_store_n(i,value, __ATOMIC_RELEASE);}

static int CompareAndSwap(volatile int* i, int old_value, int new_value) {
	return __sync_val_compare_and_swap(i,old_value,new_value);	
}

template <class T>
static T* AcquireLoadPtr(T* volatile* ptr) {
	return __atomic_load_n(ptr, __ATOMIC_ACQUIRE);
}

template <class T>
static T* CompareAndSwapPtr(T* volatile * ptr, T* old_value, T* new_value) {
	return __sync_val_compare_and_swap(ptr,old_value,new_value);
}

#endif
};


#endif 
