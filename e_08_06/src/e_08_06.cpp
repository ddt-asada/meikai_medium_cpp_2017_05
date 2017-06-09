/*演習8-6
 * 例外ハンドラをconst exception&型で受け取るようにしたプログラム。
 * 作成日：2017年5月31日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <iostream>
#include <exception>
#include <cstdlib>

using namespace std;

//加算する関数の宣言。
int add(int v1, int v2);

int main()
{
	int x, y;		//加算する値。

	//値の入力を促す。
	cout	<<"xの値（0～99）";
	cin		>>x;

	//値の入力を促す。
	cout	<<"yの値（0～99）";
	cin		>>y;

	//例外補足。
	try {
		cout	<<"加算した値は"	<<add(x, y)	<<"です。\n";

	//例外を捕捉した場合。
	} catch (const exception& e) {
		cerr	<<"論理エラー発生："	<<e.what()	<<'\n';
	}
}

//加算する関数の定義。
int add(int v1, int v2)
{
	//範囲外の場合例外を送出する。
	if(v1 < 0 || v1 > 99) {
		throw out_of_range("v1の値が不正。");
	}

	//範囲外の場合例外を送出する。
	if(v2 < 0 || v2 > 99) {
		throw out_of_range("v2の値が不正。");
	}

	//加算した値を返す。
	return v1 + v2;
}
