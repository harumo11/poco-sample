#include <iostream>
#include <Poco/Environment.h>

int main(int argc, char const* argv[])
{
#if POCO_ARCH == POCO_ARCH_IA32
	std::cout << "This architecture is 32bit" << std::endl;
#elif POCO_ARCH == POCO_ARCH_ARM
	std::cout << "This architecture is arm " << std::endl;
#elif POCO_ARCH == POCO_ARCH_AMD64
	std::cout << "This architecture is 64bit" << std::endl;
#endif

	return 0;
}

