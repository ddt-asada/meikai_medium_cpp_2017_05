/*演習2-5
 * 符号なし整数の全ビットを文字列に変換して表示する。
 * 作成日：2017年5月23日
 * 作成者：浅田　知嗣
 */

#include<iostream>

using namespace std;

//整数x中の1であるビット数を求める関数の宣言。
int count_bits(unsigned x);

//int型／unsigned型のビット数を求める関数の宣言。
int int_bits();

//全ビット数をナル文字を含めた文字列に変換する関数の宣言。
const char* bits_of(unsigned x);

//unsigned型のビット構成を表示する関数の宣言。
void print_bits(unsigned x);

char bit[32];

int main()
{
	unsigned a, b;		//2進数の文字列に変換したい整数。

	cout	<<"非負の整数を二つ入力せよ。\n";

	//整数値の入力を促す。
	cout	<<"a：";
	cin		>>a;

	cout	<<"b：";
	cin		>>b;

	//様々な条件で2進数に変換できるかを確認する。
	cout	<<"aの";
	print_bits(a);
	cout	<<'\n';

	cout	<<"bの";
	print_bits(b);
	cout	<<'\n';

	cout	<<"a & bの";
	print_bits(a & b);
	cout	<<'\n';
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

//全ビット数をナル文字を含めた文字列に変換する関数の宣言。
const char* bits_of(unsigned x)
{
	const char* a = ((x >>0) & 1U ? "1" : "0");//返却用の先頭文字を格納した文字列。

	//整数を2進数の文字列に変換する。
		for(int i = 0; i < int_bits() ; i++) {
			//2進数に変換していく。
			//1文字ずつ見ていき、1ならそのまま文字列に1を代入。
			if((x >> i) & 1U) {
				bit[i] = '1';
			//0ならそのまま文字列に0を代入。
			} else {
				bit[i] = '0';
			}
		}

	//文字列の最後にナル文字を挿入する。
	bit[int_bits()]  = '\0';

	//文字列の先頭文字を返す。
	return a;
}

//unsigned型のビット構成を表示する関数の定義。
void print_bits(unsigned x)
{
	//わたした数字を2進数表記の文字列へと変換したうえで、その先頭文字を返す関数を呼び出す。
	cout	<<"先頭文字は："	<<bits_of(x)	<<"です。\n";

	//さきほどの関数によって求めた文字列は静的なのでこちらでもそのまま使える。
	for(int i = int_bits() - 1; i >= 0; i--) {
		cout	<<bit[i];
	}
}
