/*演習12-4
 * 現在の気分の入力もできるようにし、ファイルに出力するプログラム。
 * 作成日：2017年6月6日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <fstream>
#include <iostream>
#include <string>

#include "e_12_04_Date.h"

using namespace std;

char fname[] = "lasttime.txt";	//ファイル名。

//前回の日付・時刻を取得・表示する関数の宣言。
void get_data();

//今回の日付・時刻を書き込む関数の宣言。
void put_data();

int main()
{
	//前回の日付を取得・表示。
	get_data();

	//今回の日付を取得・表示。
	put_data();

	return 0;
}

//前回の日付・時刻を取得・表示する関数の定義。
void get_data()
{
	ifstream fis(fname);	//前回の日付・時刻が格納されたファイルを開く。

	//オープンに失敗した時。
	if(fis.fail()) {
		cout	<<"本プログラムを実行するのは初めてですね。\n";

	//オープンに成功した時。
	} else {
		int y;	//年。
		int m;	//月
		int d;	//日
		string condition = "0";	//現在の気分を入力する型。

		//オープンしたファイルより時刻情報を取得する。
		fis	>>y	>>m	>>d	>>condition;

		//前回の日付を表示する。
		Date x(y, m, d);

		cout	<<x;

		//現在の気分が入力されていた場合は気分を表示する。
		if(condition != "0") {
			cout	<<"で現在の気分は："	<<condition	<<'\n';
		}
	}
}

//今回の日付・時刻を書き込む関数の宣言。
void put_data()
{
	//ファイルをオープンする。
	ofstream fos(fname);

	//オープンできなかったとき。
	if(fos.fail()) {
		cout	<<"ファイルをオープンできません。\n";

	//オープンに成功した時。
	} else {
		//現在の日付クラスを生成。
		Date today;

		string condition = "0";	//現在の気分を入力する型。

		//現在の気分の入力を促す。
		cout	<<"現在の気分は：";
		cin		>>condition;


		//現在の日付と気分をファイルに出力。
		fos	<<today.year()	<<' '	<<today.month()	<<' '	<<today.day()	<<' '	<<condition	<<'\n';
	}
}
