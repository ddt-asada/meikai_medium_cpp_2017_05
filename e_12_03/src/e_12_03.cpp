/*演習12-3
 * 現在の日付・時刻の取得をDateクラスから行い、ファイルに出力するプログラム。
 * 作成日：2017年6月6日
 * 作成者：浅田　知嗣
 */

#include <fstream>
#include <iostream>
#include "e_12_03_Date.h"

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

		//オープンしたファイルより時刻情報を取得する。
		fis	>>y	>>m	>>d;

		//前回の日付を表示する。
		Date x(y, m, d);

		cout	<<x;
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

		//現在の日付をファイルに出力。
		fos	<<today.year()	<<' '	<<today.month()	<<' '	<<today.day()	<<'\n';
	}
}
