#include <iostream>
#include <string>
#include <Poco/Path.h>

int main(int argc, char const* argv[])
{
	std::cout << 
		"Current path is\t"
		<< Poco::Path::current() 
		<< std::endl;

	std::cout << 
		"Home path is\t"
		<< Poco::Path::home()
		<< std::endl;
	
	Poco::Path path("/usr/local/include/");
	std::cout << 
		"The node name\t"
		<< path.getNode()
		<< std::endl;
	return 0;
}

