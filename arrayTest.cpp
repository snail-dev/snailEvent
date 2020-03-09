#include "arraysize.h"
#include <iostream>

int main()
{
	
	char buf[10]="Hello";

	int arr[5] = {1,2,3,4,5};

	std::cout<<arraysize(buf)<<"\n";
	std::cout<<arraysize(arr)<<"\n";

	int* p = arr;
	//std::cout<<arraysize(p)<<"\n";

	
	std::cout<<badarraysize(buf)<<"\n"
			<<badarraysize(arr)<<"\n"
			<<badarraysize(p)<<"\n";

	return 0;
}
