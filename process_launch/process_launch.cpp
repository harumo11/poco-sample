#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <Poco/Process.h>

using std::cout;
using std::endl;

int main(int argc, char const* argv[])
{

	//uname -a
	const std::string command = "uname";
	std::vector<std::string> args = {"-a"};
	
	Poco::ProcessHandle handle(Poco::Process::launch(command,args));
	cout << "[INFO] ID is = " << handle.id() << endl;
	handle.wait();

	//yarpserver
	const std::string yarpCommand = "yarpserver";
	Poco::Process::Args arg;
	arg.clear();

	Poco::ProcessHandle yarpHandle = Poco::Process::launch(yarpCommand, arg);
	cout << "[INFO] ID is = " << yarpHandle.id() << endl;
	sleep(3);
	Poco::Process::kill(yarpHandle);

	return 0;
}
