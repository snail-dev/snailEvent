#ifndef _RTC_BASE_ARRAY_SIZE_H_
#define _RTC_BASE_ARRAY_SIZE_H_

#include <stddef.h>

template <typename T, size_t N>
char (&arraysize_fake_fn (T(&array)[N])) [N];

#define arraysize(array) sizeof(arraysize_fake_fn(array))

#define badarraysize(array) sizeof(array)/sizeof(array[0])


#endif
