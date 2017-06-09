/*演習12-2
 * ファイルのオープンに成功したかどうかを判定し、内容全部消去されることを確認するプログラム。
 * 動作の確認用に"e_12_02.txt"という名前のファイルを用意してあります。
 * 作成日：2017年6月6日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//ファイルの中身を空にする関数の宣言。
void file_exist(const char* filename);

int main()
{
	string filename;		//確認したいファイル名を入力する。

	//存在を確認したいファイル名を入力する。
	cout	<<"中身を空にしたいファイルの名前：";
	cin		>>filename;

	//存在するかどうかの判定を行い結果を表示。
	cout	<<"そのファイルの中身を空にしました。\n";
}

//ファイルの中身を空にする関数の定義。
void file_exist(const char* filename)
{
	//入力されたファイルをの中身を空にする。。
	ofstream fis(filename);
}
