#include <iostream>
#include <string>
#include <Poco/File.h>
#include <Poco/Path.h>

int main(int argc, char const* argv[])
{

	Poco::Path path(Poco::Path::current());
	path.pushDirectory("PocoFileSample");
	std::cout << "This is homePath " << path.toString() << std::endl;

	Poco::File tmp(path);
	if (tmp.createDirectory() ) {
		
		std::cout << "make a directory" << std::endl;
	}
	else {
		std::cout << "can not make dirctory" << std::endl;
	}

	return 0;
}
