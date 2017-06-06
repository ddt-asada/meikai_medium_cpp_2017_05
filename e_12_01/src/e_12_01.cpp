/*演習12-1
 * ファイルのオープンに成功したかどうかを判定するプログラム。
 * 動作の確認用に"e_12_01.txt"という名前のファイルを用意してあります。
 * 作成日：2017年6月6日
 * 作成者：浅田　知嗣
 */

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//ファイルが存在するかどうかを確認する関数の宣言。
bool file_exist(const char* filename);

int main()
{
	string filename;		//確認したいファイル名を入力する。

	//存在を確認したいファイル名を入力する。
	cout	<<"存在を確認したいファイルの名前：";
	cin		>>filename;

	//存在するかどうかの判定を行い結果を表示。
	cout	<<"そのファイルは存在";
	cout	<<(file_exist(filename.c_str()) ? "します。\n" : "しません。\n");
}

//ファイルが存在するかどうかを確認する関数の定義。
bool file_exist(const char* filename)
{
	//成功したかどうかの判定を入れる型。
	bool judge = 0;

	//入力されたファイル名を入力ストリームとしてオープン。
	ifstream fis(filename);

	//ファイルのオープンに成功した時の分岐。
	if(!fis.fail()) {
		judge = 1;

	//失敗した時の分岐。
	} else if (fis) {
		judge = 0;
	}

	//判定を返す。
	return judge;
}
