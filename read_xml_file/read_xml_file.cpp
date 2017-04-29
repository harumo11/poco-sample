#include <iostream>
#include <string>
#include <sstream>
#include </usr/local/include/Poco/AutoPtr.h>
#include </usr/local/include/Poco/Util/XMLConfiguration.h>

using Poco::AutoPtr;
using Poco::Util::XMLConfiguration;

int main(int argc, char const* argv[])
{
	AutoPtr<XMLConfiguration> pConf(new XMLConfiguration("test.xml"));

	std::string prop1 = pConf->getString("prop1");
	std::cout << "prop1 =  " << prop1 << std::endl;

	pConf->setString("prop2", "ThisIsProp2");
	pConf->save("test.xml");
	//int prop2 = pConf->getInt("prop2");
	//std::cout << "prop2 " << prop2 << std::endl;


	//std::string prop3 = pConf->getString("prop3");
	//std::cout << "prop3 " << prop3 << std::endl;

	//std::string prop4 = pConf->getString("prop3.prop4");
	//std::cout << "prop4 " << prop4 << std::endl;

	//prop4 = pConf->getString("prop3.prop4[@attr]");//value3
	//std::cout << "prop3.prop4[0][@attr] " << prop4 << std::endl;

	//prop4 = pConf->getString("prop3.prop4[1][@attr]");//value4
	//std::cout << "prop3.prop4[1][@attr] " << prop4 << std::endl;

	pConf->setString("prop5", "input");
	pConf->save("test.xml");
	return 0;
}
