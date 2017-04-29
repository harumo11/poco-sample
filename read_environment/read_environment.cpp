#include <iostream>
#include <Poco/Environment.h>

int main(int argc, char const* argv[])
{
	std::cout << "OS Name : " << Poco::Environment::osName() << std::endl;
	std::cout << "OS Version : " << Poco::Environment::osVersion() << std::endl;
	std::cout << "Os Arch : " << Poco::Environment::osArchitecture() << std::endl;
	std::cout << "Node Name : " << Poco::Environment::nodeName() << std::endl;

	Poco::Environment env;
	std::cout << env.get("DESKTOP_SESSION") << std::endl;

	return 0;
}

