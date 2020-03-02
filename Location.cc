#include "Location.h"
#include <stdio.h>

namespace rtc {

Location::Location():function_name_("Unknown")
					 , file_and_line_("Unknown"){}

Location::Location(const char* function_name, const char* file_and_line){
	this->function_name_ = function_name;
	this->file_and_line_ = file_and_line;
}

Location::Location( const Location& other) {
	function_name_ = other.function_name_;
	file_and_line_ = other.file_and_line_;
}

Location& Location::operator=(const Location& other) {
	this->function_name_ = other.function_name_;
	this->file_and_line_ = other.file_and_line_;

	return *this;
}

const char* Location::function_name() const {
	return function_name_;
}
const char* Location::file_and_line() const {
	return file_and_line_;
}


std::string Location::toString() {
	char buf[256];
	snprintf(buf,sizeof(buf),"%s@%s",function_name_,file_and_line_);

	return buf;
}

}
