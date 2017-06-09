/*演習9-5
 * ビットベクトルの要素数を取得するゲッタを追加。
 * 作成日：2017年6月2日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <iostream>

#include "e_09_05_Array.h"
#include "e_09_05_BoolArray.h"

using namespace std;

//bool型の配列をビットベクトルとして表示する関数の宣言。
void print_Array_bool(const Array<bool>& a);

int main()
{
	Array<bool> x(10);	//10個の要素をもつbool型の配列を生成。

	//TRUEorFALSEで表示することを明示。
	cout	<<boolalpha;

	//配列の全要素を表示
	for(int i = 0; i < x.size();i++) {
		cout	<<"x["	<<i		<<"] = "	<<x[i]	<<'\n';
	}

	//配列をコピーする。
	Array<bool> y(x);

	Array<bool> z(5);
	z = y;

	y[3] = true;
	y[6] = true;
	z[5] = true;
	z[7] = true;

	//ビットベクトルとして配列を表示。
	cout	<<"x = ";
	print_Array_bool(x);
	cout	<<"\n要素数："	<<x.get_vsize()	<<'\n';

	cout	<<"y = ";
	print_Array_bool(y);
	cout	<<"\n要素数："	<<y.get_vsize()	<<'\n';

	cout	<<"z = ";
	print_Array_bool(z);
	cout	<<"\n要素数："	<<z.get_vsize()	<<'\n';

	return 0;
}

void print_Array_bool(const Array<bool>& a)
{
	for(int i = 0; i <a.size(); i++) {
		cout	<<(a[i] ? '1' : '0');
	}
}
