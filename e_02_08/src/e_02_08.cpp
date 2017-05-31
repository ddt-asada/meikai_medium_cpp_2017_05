/*演習2-8
 * 要素数が制限されない、集合の下限値と上限値を任意に設定できるビットベクトル集合クラス作成。
 * 作成日：2017年5月26日
 * 作成者：浅田　知嗣
 */

#include <iostream>
#include "e_02_08_Bit.h"

using namespace std;

int main()
{
	//デフォルトコンストラクタより空集合を生成する。
	BitSet b1;

	//10～99の値を要素としてもつビットベクトルを生成。。
	BitSet b2(10, 99);

	//0～32の値を要素として持つビットベクトルを生成。
	BitSet b3(0, 31);

	//集合を表示する。
	cout	<<"集合b1："	<<b1	<<"\nビット：";
	b1.bit_string();
	cout	<<"\nを生成しました。\n";

	//集合を表示する。
	cout	<<"集合b2："	<<b2	<<"\nビット：";
	b2.bit_string();
	cout	<<"\nを生成しました。\n";

	//集合を表示する。
	cout	<<"集合b3："	<<b3	<<"\nビット：";
	b3.bit_string();
	cout	<<"\nを生成しました。\n";

	//積集合を求めて表示する。
	b2 ^= b3;
	cout	<<"集合b2 & b3："	<<b2	<<"\nビット：";
	b2.bit_string();
	cout	<<"\nを生成しました。\n";

	/*
	//和集合を求めて表示する。
	b2 |= b3;
	cout	<<"集合b2 | b3："	<<b2	<<"\nビット：";
	b2.bit_string();
	cout	<<"\nを生成しました。\n";
	 */

	return 0;
}