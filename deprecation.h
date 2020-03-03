#ifndef DEPRECATION_H_
#define DEPRECATION_H_

#ifdef _MSC_VER_
#define RTC_DEPRECATED __declspec(deprecated)
#elif defined (__GUNC__)
#define RTC_DEPRECATED __attribute__((__deprecated__))
#else
#define RT_DEPRECATED
#endif


#endif
