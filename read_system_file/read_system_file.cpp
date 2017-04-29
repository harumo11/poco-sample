#include <iostream>
#include <string>
#include <Poco/AutoPtr.h>
#include <Poco/Util/SystemConfiguration.h>

using namespace std;
using Poco::AutoPtr;
using Poco::Util::SystemConfiguration;

int main(int argc, char const* argv[])
{
	AutoPtr<SystemConfiguration> pConf = new SystemConfiguration;

	cout << "the operating system name\t " << pConf->getString("system.osName") << endl;
	cout << "the operating system version\t " << pConf->getString("system.osVersion") << endl;
	cout << "the operating system architecture\t " << pConf->getString("system.osArchitecture") << endl;
	cout << "the node or host name\t" << pConf->getString("system.nodeName") << endl;
	//cout << "system ID, based on the Ethernet address of the first Ethernet adapter found on the system\t" << pConf->getString("system.nodeId") << endl;
	cout << "the currnt working directory\t" << pConf->getString("system.currentDir") << endl;
	cout << "the user's home direcotory\t" << pConf->getString("system.homeDir") << endl;
	cout << "the system's temporary direcotory\t" << pConf->getString("system.tempDir") << endl;
	cout << "the current UTC date and time, formatted in ISO 8601 format\t" << pConf->getString("system.dateTime") << endl;
	cout << "the cuurent process ID\t" << pConf->getString("system.pid") << endl;
	cout << "the environment variable with the given <NAME>\t" << pConf->getString("system.env.SHELL") << endl;

	return 0;
}
