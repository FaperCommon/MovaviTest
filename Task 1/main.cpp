#include <iostream>
#include <ishape.h>


int main()
{
	try{
		Triangle a(3,4,5);
		std::cout<<a.Area();
	}
	catch(const char * err){
		std::cerr<<err;
		return -1;
	}

    return 0;
}


