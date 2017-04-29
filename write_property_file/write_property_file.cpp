#include <iostream>
#include <Poco/AutoPtr.h>
#include <Poco/Util/PropertyFileConfiguration.h>

using Poco::AutoPtr;
using Poco::Util::PropertyFileConfiguration;

int main(int argc, char const* argv[])
{
	AutoPtr<PropertyFileConfiguration> pConf;
	pConf = new PropertyFileConfiguration();
	pConf->setString("key1", "harumosasatake");
	pConf->setString("key2", "yesterday");

	std::cout << pConf->getString("key2") << std::endl;
	pConf->save("test.properties");

	return 0;
}


