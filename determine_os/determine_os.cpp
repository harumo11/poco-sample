#include <iostream>
#include <Poco/Environment.h>

int main(int argc, char const* argv[])
{
#if POCO_OS == POCO_OS_WINDOWS_NT
	std::cout << "This is Windows. " << std::endl;
#elif POCO_OS == POCO_OS_LINUX
	std::cout << "This is Linux." << std::endl;
#elif POCO_OS == POCO_OS_AIX
	std::cout << "This is AIX." << std::endl;
#elif POCO_OS == POCO_OS_QNX
	std::cout << "This is QNX." << std::endl;
#elif POCO_OS == POCO_OS_FREE_BSD
	std::cout << "This is FreeBSD." << std::endl;
#elif POCO_OS == POCO_OS_MAC_OS_X
	std::cout << "This is MAX." << std::endl;
#endif

#if defined(POCO_OS_FAMILY_WINDOWS)
	std::cout << "This is Windows family os" << std::endl;
#elif defined(POCO_OS_FAMILY_UNIX)
	std::cout << "This is Linux family os" << std::endl;
#endif

	return 0;
}

