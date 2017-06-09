/*演習9-8
 * 配列クラステンプレートをインクルードモデルを使用して再現したプログラム
 * 作成日：2017年6月4日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <new>
#include <iostream>
#include "e_09_08_Array.h"
#include "e_09_08_Arraybool.h"
#include "e_09_08_ArrayFixed.h"

using namespace std;

int main()
{
	//配列クラステンプレートから配列を生成。
	Array<int> x2(3, 7);

	for(int i = 0; i < x2.size(); i++) {
		cout	<<"x2["	<<i	<<"] = "	<<x2[i]	<<'\n';
	}

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
	cout	<<'\n';

	cout	<<"y = ";
	print_Array_bool(y);
	cout	<<'\n';

	cout	<<"z = ";
	print_Array_bool(z);
	cout	<<'\n';

	FixedArray<int, 7> a1;

	for(int i= 0; i < a1.size(); i++) {
		a1[i] = i;
	}

	FixedArray<int, 7> a2= a1;

	cout	<<"a1 = ";
	print_FixedArray(a1);
	cout	<<'\n';

	cout	<<"a2 = ";
	print_FixedArray(a2);
	cout	<<'\n';

	return 0;
}
