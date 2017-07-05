# Applications 
コマンドラインとサーバーアプリケーションを作る

## 概要
- アプリケーション イントロダクション
- アプリケーション　サブシステム
- コマンドライン　アプリケーション
- サーバーアプリケーション
- コマンドライン オプション 処理

## アプリケーションとPOCO

POCOのアプリケーションフレームワークは，ほぼすべてのアプリケーションで必要な機能をサポートします．

- コマンドライン引数処理 
- 設定ファイル
- 初期化と終了処理
- ロギング

POCOは２種類のアプリケーションをサポートします．

- コマンドラインアプリケーション
通常，コマンドラインから呼び出されるアプリケーション．

- サーバーアプリケーション
Windowsサービスやデーモンとして実行されるアプリケーション（もちろん，コマンドラインアプリケーションとしても実行されます）

## アプリケーション　サブシステム

- アプリケーションは異なるサブシステムで構成できます．
- サブシステムはアプリケーションをモジュール方式で拡張します．
- サブシステムは，アプリケーションの初期化とシャットダウンに役立ちます．
- アプリケーションが初期化されると，登録されたサブシステムも全て初期化されます．
- アプリケーションがシャットダウンされると，登録されているすべてのサブシステムもシャットダウンされます．

## サブシステムのクラス
- サブシステムは** Poco::Util::Subsystem**を実装しなければなりません．

| Method | Discription |
|--------|-------------|
|const char* name() const | サブシステムの名前を返します|
|vodi initialize(Application& app)|サブシステムを初期化する|
|void uninitialize(Application& app)|サブシステムをシャットダウンします|
|void reinitialize(Application& app)|サブシステムを再設定します，（任意：実装は** uninitialize()**のあとに** initialize()**を呼び出します．|
|void defineOptions(OptionSet& options)| サブシステムが独自のコマンドラインアプリケーション引数を定義できるようにする.サブシステムが独自のコマンドライン引数を実装したい場合，このメンバ関数を実装する必要があります． オプションを効果的に処理するには，サブシステムはオプションを構成プロパティにバインドするか，おｐションを処理するコールバックを指定する必要があります．それ以外の場合，オプションはアプリケーションのハンドルOption()のメンバー関数に渡されますが，これはおそらく何をするかわかりません．|

## コマンドラインアプリケーション
- コマンドラインアプリケーションは．Poco::Util::Applicationのサブクラスを作成することによって実装されます．
- Poco::Util::ApplicationはPoco::Util::Suvsystemのサブクラスです．
- オーバーライドする仮想メンバ関数がいくつかあります．
-- void initialize(Application& self)
-- void reinitialize()
-- void uninitialize()
-- void defineOption()などです．

- int main(const std::vector<std::string>& args)
 アプリケーションの主なロジックを実装します．args, vectorには，オプションとして処理されていないコマンドライン引数が全て含まれています．main関数はアプリケーションの終了コードを返す必要があります．これはExitCode列挙体の値となります．（たとえば，EXIT_OK, EXIT_USAGE,etc)

## サーバーアプリケーション
- サーバーアプリケーションはPoco::Util::ServerApplicationのサブクラスを作成することによって実装されます．(これはPoco::Util::Applicationのサブクラスです)
- サーバーアプリケーションはコマンドラインからWindowsサービスとして,またはUnixデーモンとして実行できます．
- 通常，サーバアプリケーションはバックグラウンドでその処理を行います．従って**main()**関数はスレッドを起動し，アプリケーションの終了要求を待ちます．(waitForTerminateRequest()を参照)

## 設定ファイル
- デフォルトの２つの構成ごとに作成されます．
-- **writable** Poco::Util::MapConfiguration, PRIO_APPLICATION
-- **readonly** Poco::Util::SystemConfiguration, PRIO_SYSTEM

-  APPという名前のアプリケーションは起動時にAPP(d).{xml,ini,properties}という名前のファイルを検索します．
```c
void MyApplication::initialize(Application& self)
{
	loadConfiguration(); //load default configuration files
    Application::initialize(self);
}
```

## コマンドラインオプション
- アプリケーションはコマンドライン引数を定義して処理することができます．（任意）
- コマンドライン引数は，通常，プラットフォームの典型的な形式で指定されます．
-- /option or /option=value **on Windows**
-- -o -ovalue, --option or --option:value **on Unix**

## オプションの定義
- オプションは，それらをアプリケーションのPoco::Util::OptionSetにPoco::Util::addOption()メンバ関数を使用して追加することで定義されます．
- これは，仮想関数defineOptions()をオーバーライドすることで行われます．

## Optionの解剖学
- オプションは
-- フルネームを持つ
-- 追加のショートネームを持つ（一文字）
-- 説明を持つ（使用方法の説明の表示に使用される）
-- 追加の引数名を持つ
- オプションは任意，もしくは絶対必要のどちらかに設定できる．
- オプションは繰り返し可能です．つまり，コマンドラインで複数回指定することができます．

## オプショングループと検証
- オプションはオプショングループの一部とすることができます．
- 多くの場合，各グループのオプションはコマンドラインで指定できます．
- オプション引数は，検証用オブジェクトを指定することによって自動的に検証されます．

## オプションの処理
- オプションは設定プロパティにバインドできます．
- オプションを扱うためにコールバックメンバ関数を指定することができます．
- オプションアプリケーションのはPoco::Util::handleOption()メンバ関数のなかで扱うこともできます．

## オプション引数の検証
- オプション引数は，オプションのPoco::Uitl::Validatorオブジェクトを指定することによって自動的に検証されます．
- ２つのValidatorの実装が可能です．
-- Poco::Util::intValidatorは引数がある範囲に入っていて，整数かどうかをチェックします．
-- RegExpValidatorは引数が与えられた正規表現に合うかどうかを検証します．
- Validatorの他の種類も実装可能です．

```C++
void defineOptions(OptionSet& options)
{
    Application::defineOptions(options);
    options.addOption(
        Option("help", "h", "display help information")
            .required(false)
            .repeatable(false)
            .callback(OptionCallback<MyApp>(this, &MyApp::handleHelp)));
            
    options.addOption(
        Option("config-file", "f", "load configuration data from a file")
            .required(false)
            .repeatable(true)
            .argument("file")
            .callback(OptionCallback<MyApp>(this, &MyApp::handleConfig)));
            
    options.addOption(
        Option("bind", "b", "bind option value to test.property")
            .required(false)
            .argument("value")
            .validator(new IntValidator(0, 100))
            .binding("test.property"));
}
```

## HELP情報の表示
- Poco::UtilHelpFormatterクラスはコマンドラインオプションのHelp情報を表示するために使用することができます．
- ユーザーがヘルプ情報を要求すると，それ以降のすべてのコマンドライン処理（特に必要なオプションの実行）をキャンセルする必要があります．これは，stopOptionProcessing()を呼び出すことによって行えます．

```C++
void displayHelp()
{
    HelpFormatter helpFormatter(options());
    helpFormatter.setCommand(commandName());
    helpFormatter.setUsage("OPTIONS");
    helpFormatter.setHeader(
        "A sample application that demonstrates some of the features "
        "of the Poco::Util::Application class.");
    helpFormatter.format(std::cout);
}
void handleHelp(const std::string& name, const std::string& value)
{
    _helpRequested = true;
    displayHelp();
    stopOptionsProcessing();
}
```

## Windowsサービス
- Poco::Util::ServerApplicationをベースに作成されたアプリケーションはWindowsのサービスとして実行することができます．
- これを行うには，コマンドラインからアプリケーションを起動し，/registerサービスオプションを指定して，Windowsサービスマネージャーにサービスを登録する必要があります．
- 不要になったサービスは,/unregisterServiceオプションを指定することで登録解除できます．
- サービスのユーザーフレンドリーな表示名は，/displayNameオプションで任意に指定することができます．
- 登録されたサービスは，サービスMMCアプレットを使用するかコマンドラインでNET STARTコマンドとNET STOPコマンドを使用して，開始，または停止できます．
- サービスを認識するために，サービス実行ファイルの名前（ディレクトリとexe拡張子を除く)を使用する必要があります．
- アプリケーションは，application.runAsService設定プロパティの値を取得することによって，サービスとして動作しているかどうかを確認できます．

## Windowsサービスの落とし穴
- サービスとしてのアプリケーションが実行されている作業ディレクトリはWindows system directory(ex:C:\Windows\system32)だということに注意してください．設定ファイルパスや他の場所で相対ファイルシステムのパスを扱うときはこれを考慮してください．
- **subst** cmdによって作成されたパスからサービスを登録しないでください．
- 実行可能ファイルが見つかる場所にすべてのライブラリがあることを確認してください．実行可能ファイルと同じディレクトリが推奨されます．

## Unix デーモン
- Unixプラットフォームでは\--daemonコマンドラインアプリケーションを指定することによってServerApplicationクラスをデーモンとして任意に実行することができます．
- デーモンが起動すると，すぐに実際の作業を行うバックグラウンドプロセスを終了します．バックグラウンドプロセスを起動すると，フォアグランドプロセスが終了します．
- 初期化が完了したあとで，main()関数では，デーモンプロセスの現在の作業ディレクトリがルートディレクトリ("/")に変更されます．これはデーモンプロセスの一般的な方法です．
- アプリケーションは，application.runAsDaemon設定プロパティを調べることによって，デーモンとして実行されているかどうかを判別できます．
- Windowsと同様に，デーモンの現在の作業ディレクトリはルートディレクトリであるため，設定ファイルで相対パスを使用する場合は注意してください．