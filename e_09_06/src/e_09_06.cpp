/*演習9-6
 * 対話的に処理を行うプログラムを作成。
 * 作成日：2017年6月2日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <iostream>

#include "e_09_06_Array.h"
#include "e_09_06_BoolArray.h"

using namespace std;

//bool型の配列をビットベクトルとして表示する関数の宣言。
void print_Array_bool(const Array<bool>& a);

//bool型の配列ビットベクトルの要素数を表示する関数の宣言。
void print_Array_vsize(const Array<bool>& a);

//bool型の配列の要素数を表示する関数の宣言。
void print_Array_size(const Array<bool>& a);

//bool型の配列の要素を表示する関数の宣言。
void print_Array(const Array<bool>& a);

//bool型の配列の要素を変更する関数の宣言。
void change_Array(Array<bool>& a);

int main()
{
	Array<bool> x(10);	//10個の要素をもつbool型の配列を生成。

	int select = 1;		//配列の操作方法を選択する。

	//TRUEorFALSEで表示することを明示。
	cout	<<boolalpha;

	//終了が選択されるまで無限ループ。
	for( ; select != 0; ) {
		cout	<<"[1]配列の要素数を表示。 [2]配列の全要素を表示。 [3]配列をビットベクトルとして表示。 [4]ビットベクトル配列の要素数を表示。 [5]配列の要素を変更。 [0]終了\n";
		cin		>>select;

		//選択に応じて配列を操作。
		switch(select) {
		case 1:	print_Array_size(x);	break;
		case 2:	print_Array(x);			break;
		case 3:	print_Array_bool(x);	break;
		case 4:	print_Array_vsize(x);	break;
		case 5:	change_Array(x);		break;
		}
	}

	return 0;
}

//bool型の配列をビットベクトルとして表示する関数の定義。
void print_Array_bool(const Array<bool>& a)
{
	cout	<<"配列をビットベクトルとして表示します。\n";

	//配列をビットベクトルとして表示。
	for(int i = 0; i <a.size(); i++) {
		cout	<<(a[i] ? '1' : '0');
	}
	cout	<<'\n';
}

//bool型の配列ビットベクトルの要素数を表示する関数の定義。
void print_Array_vsize(const Array<bool>& a)
{
	//ビットベクトルの要素数を表示する。
	cout	<<"ビットベクトル配列の要素数は"	<<a.get_vsize()	<<"です。\n";
}

//bool型の配列の要素数を表示する関数の定義。
void print_Array_size(const Array<bool>& a)
{
	//配列の要素数を表示する。
	cout	<<"配列の要素数は"	<<a.size()	<<"です。\n";
}

//bool型の配列の要素を表示する関数の定義。
void print_Array(const Array<bool>& a)
{
	cout	<<"配列の要素を表示します。\n";

	//配列の全要素を表示。
	for(int i = 0; i < a.size(); i++) {
		cout	<<"x["	<<i	<<"] = "	<<a[i]	<<'\n';
	}
}

//bool型の配列の要素を変更する関数の定義。
void change_Array(Array<bool>& a)
{
	int	no = 0;		//配列の要素を変更したい場所の添字;
	bool x;		//新たに配列に代入するbool型の変数。

	cout	<<"配列の要素を変更します。";

	//範囲内以外の添字が入力されたらループ。
	do {
		cout	<<"配列の変更したい添字を入力してください：";
		cin		>>no;
	} while (no < 0 || no > 9);

	cout	<<"代入する値[1]true [0]false：";
	cin		>>x;

	//値を代入。
	a[no] = x;
	cout	<<"値を代入しました。\n";
}
