#include <iostream>
#include <string>
#include <Poco/AutoPtr.h>
#include <Poco/Util/PropertyFileConfiguration.h>

using Poco::AutoPtr;
using Poco::Util::PropertyFileConfiguration;

int main(int argc, char const* argv[])
{
	AutoPtr<PropertyFileConfiguration> pConf;
	pConf = new PropertyFileConfiguration("test.properties");

	std::string key1 = pConf->getString("key1");
	int value = pConf->getInt("key2");
	std::string longVal = pConf->getString("key3.longValue");
	std::string path = pConf->getString("path", "/usr/local/include");
	std::string anotherPath = pConf->getString("anotherPath", "/usr/local/include");

	std::cout << "key1 " << key1 << std::endl;
	std::cout << "value " << value << std::endl;
	std::cout << "longVal " << longVal << std::endl;
	std::cout << "path " << path << std::endl;
	std::cout << "anotherPath " << anotherPath << std::endl;

	return 0;
}

