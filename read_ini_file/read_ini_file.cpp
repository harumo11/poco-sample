#include <iostream>
#include <string>

//iniファイルを読み込み＆処理するクラスのヘッダー
#include <Poco/Util/IniFileConfiguration.h>
//smart pointerを使うためのヘッダー
#include <Poco/AutoPtr.h>

//この関数だけは名前空間を省略するという宣言.using namespace を使用しても良い．
using std::cout;
using std::endl;
using Poco::AutoPtr;
using Poco::Util::IniFileConfiguration;

int main(int argc, char const* argv[])
{
	
	//iniファイルを読み込み．必ずsmart pointerを使用するように設計されている．非常に安全設計
	AutoPtr<IniFileConfiguration> pConf(new IniFileConfiguration("test.ini"));

	//iniファイルの中の値を文字列として読み込む.
	std::string path = pConf->getString("MyApplication.somePath");
	cout << "A path is " << path << endl;

	int value = pConf->getInt("MyApplication.someValue");
	value = pConf->getInt("myapplication.SomeValue");
	cout << "value is " << value << endl;

	//デフォルトの値も設定可能
	value = pConf->getInt("myapplication.someOtherValue", 456);
	cout << "antother value is " << value << endl;

	return 0;
}
