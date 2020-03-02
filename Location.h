#ifndef RTC_LOCALATION_H_
#define RTC_LOCALATION_H_

#include <string>

#include "stringize.h"

namespace rtc {
	
class Location {
public:
	Location();
	Location(const char* function_name, const char* file_and_line);
	Location( const Location& other);
	Location& operator= (const Location&);
	
	const char* function_name() const;
	const char* file_and_line() const;

	std::string toString();

private:
	const char* function_name_;
	const char* file_and_line_;
};
	

#define RTC_FROM_HERE RTC_FROM_HERE_WITH_FUNCTION(__FUNCTION__)

#define RTC_FROM_HERE_WITH_FUNCTION(function_name) \
	rtc::Location(function_name, __FILE__ ":" STRINGIZE(__LINE__)) 

};


#endif
