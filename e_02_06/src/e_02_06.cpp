/*演習2-6
 * 三つの型変換が確認できるプログラムを作成する。
 * 作成日：2017年5月23日
 * 作成者：浅田　知嗣
 */

#include <climits>
#include <iostream>

using namespace std;

//整数x中の1であるビット数を求める関数の宣言。
int count_bits(unsigned x);

//int型／unsigned型のビット数を求める関数の宣言。
int int_bits();

//unsigned型のビット構成を表示する関数の宣言。
void print_bits(unsigned x);

//short型のビット構成を表示する関数の宣言。
void print_sbits(short x);

//long型のビット構成を表示する関数の宣言。
void print_lbits(long x);

int main()
{
	int in = INT_MAX;		//符号付きintの最大値。同一ビットへの変換に利用する。

	//変換前のビットを表示する。
	cout	<<"同一ビットへの変換を行います。\n";
	cout	<<"変換前：";
	print_bits(in);

	//同一である符号なしintへの変換を行う。
	cout	<<"\n変換後：";
	print_bits(static_cast<unsigned>(in));

	//変換前のビットを表示する。
	cout	<<"\n長いビットへの変換を行います。\n";
	cout	<<"変換前：";
	print_bits(in);
	//より長いビットを持つlongへの変換を行う。
	cout	<<"\n変換後：";
	print_lbits(static_cast<long>(in));

	//変換前のビットを表示する。
	cout	<<"\n短いビットへの変換を行います。\n";
	cout	<<"変換前：";
	print_bits(in);
	//より短いビットへを持つshor型への変換を行う。
	cout	<<"\n変換後：";
	print_sbits(static_cast<short>(in));
}

//整数x中の1であるビット数を求める関数の定義。
int count_bits(unsigned x)
{
	//求めた値を入力する型。
	int bits = 0;

	while(x) {
		if(x & 1U) {
			bits++;
		}

		x >>= 1;
	}

	return bits;
}

//int型／unsigned型のビット数を求める関数の定義。
int int_bits()
{
	return count_bits(~0U);
}

//unsigned型のビット構成を表示する関数の定義。
void print_bits(unsigned x)
{
	for(int i = 31; i >= 0; i--) {
		cout	<<((x>> i) & 1U ? '1' : '0');
	}
}

//int型のビット構成を表示する関数の定義。
void print_sbits(short x)
{
	for(int i =  15; i >= 0; i--) {
		cout	<<((x>> i) & 1U ? '1' : '0');
	}
}

//unsigned型のビット構成を表示する関数の定義。
void print_lbits(long x)
{
	for(int i = 63; i >= 0; i--) {
		cout	<<((x>> i) & 1U ? '1' : '0');
	}
}
