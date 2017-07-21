# The File System

ファイルとディレクトリの操作

# 概要
- pathの操作
- 通常のファイル操作
- ディレクトリ操作
- ファイル名のパターンマッチング(glob)によるファイルの発見
- 一時ファイル

# Path
- 異なるOSはファイルやディレクトリの場所(いわゆるparh)を指定するために異なる記法を使います．
- これによって異なるOSでファイルやディレクトリを操作することは難しくなっています．
- POCOはこの違いを抽象化し，共通の概念に商店を当てて，様々な記法で使用できるクラスを提供します．
- POCOは以下の記法をサポートしています．
 - Windows
 - Unix
 - OpenVMS

# POCOにおける
- POCOにおけるpathは以下の要素から構成されています．
 - 追加のノードの名前
   - Windowsにおいて，これは，コンピュータのUNC Pathの名前です．
   - OpenVMSにおいて，これは，クラスターシステムにおけるノードの名前です．
   - Unixにおいては，　これは使用されません．

 - 追加のデバイスの名前
   - Windowsにおいては，これはドライブの名前です．(C: or D:)
   - OpenVMSにおいては，これはストレージデバイスの名前です．
   - Unixにおいては，これは使用されません．

 - ディレクトリの名前のリスト
 - ファイルの名前(拡張子を含む)とバージョン(OpenVMSのみ)

-----

 - POCOは２つの種類のパスをサポートしています
   - 絶対パス
     - ファイルシステムのルートから始まるリソースまでのpathの記述
   - 相対パス
     - あるディレクトリから始まるリソースまでのpathの記述(通常．あるディレクトリは現在のワークディレクトリです)
        - 相対パス絶対パスに変換できます．（その逆はできません）
   - パスはディレクトリもしくはファイルを指し示します．ディレクトリを指し示すファイルの場合，ファイル名の部分は空です．

# Pathの例

|Name  |Description  |
|:----:|:-----------:|
|Path  |C:\Windows\system32\cmd.exe|
|Style |Windows|
|Kind  |absolute, to file|
|Node Name | - |
|Device Name | C |
|Directory Line|Windows, system32|
|File Name| cmd.exe|
|Rile Version| -|

----

|Name  |Description  |
|:----:|:-----------:|
|Path  |Poco\Foundation\|
|Style |Windows|
|Kind  |relative, to file|
|Node Name | - |
|Device Name | - |
|Directory Line|Poco, Foundation|
|File Name| - |
|Rile Version| -|

----

|Name  |Description  |
|:----:|:-----------:|
|Path  |\\www\site\index.html|
|Style |Windows|
|Kind  |absolute, to file|
|Node Name | www |
|Device Name| - |
|Device List| site |
|File Name| - |
|Rile Version| -|

---

|Name  |Description  |
|:----:|:-----------:|
|Path  |/usr/local/include/Poco/Foundation.h|
|Style |Unix|
|Kind  |absolute, to file|
|Node Name | - |
|Device Name | - |
|Directory Line|usr,local,include,Poco|
|File Name| index.html|
|Rile Version| -|

---

|Name |Desctiption |
|:---:|:-----------:|
|Path |../bin/|
|Style|Unix|
|Kind| - |
|Node Name| - |
|Device Name| - |
|Directory List|..,bin|
|File Name| - |
|File Version -|

---

|Name |Desctiption |
|:---:|:-----------:|
|Path|VNS001::DSK001:[POCO.INCLUDE.POCO]POCO.H;2|
|Style|OpenVMS|
|Kind|absolute, to file|
|Node Name|VMS001|
|Device Name|DSK001|
|Directory List|POCO, INCLUDE, POCO|
|File Name|POCO.H|
|File Version| 2|

# The Path Class
- ** Poco::Path**はPOCOにおけるpathを表します．
- ** #include "Poco/Path.h**
- ** Poco::Path**