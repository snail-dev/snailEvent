#include <iostream>
#include <vector>
#include "stringize.h"
#include "stringize_advance.h"

#include "Location.h"


#define A FOO
#define B(x) myObj->FunctionCall(x)


rtc::Location f() {
	rtc::Location post_from = RTC_FROM_HERE;
	return post_from;
}


int main() {

	std::cout<<STRINGIZE_NO_EXPANSION(A)<<"\n"
			<<STRINGIZE_NO_EXPANSION(B(y))<<"\n"
			<<STRINGIZE(A)<<"\n"
			<<STRINGIZE(B(y))<<"\n";

	std::cout<<f().toString()<<"\n";

	return 0;
}
