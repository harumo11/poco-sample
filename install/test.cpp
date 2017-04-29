#include <iostream>
#include <string>
#include <Poco/File.h>
#include <Poco/Path.h>

int main(int argc, char const* argv[])
{

	//Poco::Path tmpPath(Poco::Path::home());
	Poco::Path tmpPath(Poco::Path::current());
	tmpPath.pushDirectory("PocoFileSample");
	std::cout << "This is homePath " << tmpPath.toString() << std::endl;

	Poco::File tmp(tmpPath);
	if (tmp.createDirectory() ) {
		
		std::cout << "make a directory" << std::endl;
	}
	else {
		std::cout << "can not make dirctory" << std::endl;
	}

	return 0;
}
