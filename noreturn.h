#ifndef _NO_RETURN_H_
#define _NO_RETURN_H_

#if defined (_MSC_VER)
#define NORETURN __declspec(noreturn)
#elif defined (__GNUC__)
#define NORETURN __attribute__ ((__noreturn__))
#else
#define NORETURN
#endif


#endif
