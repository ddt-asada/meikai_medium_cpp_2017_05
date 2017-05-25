/*演習2-2
 * 符号なし整数を左右にnビット開店した値を返すプログラム。
 * 作成日：2017年5月22日
 * 作成者：浅田　知嗣
 * 更新日：2017年5月23日
 * 更新者：浅田　知嗣
 */

#include <iostream>

using namespace std;

//整数x中の1であるビット数を求める関数の宣言。
int count_bits(unsigned x);

//int型／unsigned型のビット数を求める関数の宣言。
int int_bits();

//全ビット構成を表示させる関数の宣言。
void print_bits(unsigned x);

//右回転させる関数の宣言。
unsigned rrotate(unsigned x, int n);

//左回転させる関数の定義。
unsigned lrotate(unsigned x, int n);

int main()
{
	unsigned	a;		//ビット構成を表示したい符号なし整数。
	int			n;		//シフトしたい桁数を入力する整数。

	//確かめたい整数の入力。
	cout	<<"非負の整数を入力せよ：";
	cin		>>a;

	//何桁シフトするかを入力する。
	cout	<<"何桁シフトしますか：";
	cin		>>n;

	//回転前のビット構成を表示。
	cout	<<"回転前：\n";
	print_bits(a);

	//入力された値を右回転して2進数に変換して表示。
	cout	<<"右回転後：\n";
	cout	<<"10進数："	<<rrotate(a, n)	<<'\n';

	//入力された値を左回転して2進数に変換して表示。
	cout	<<"左回転後：\n";
	cout	<<"10進数："	<<lrotate(a, n)	<<'\n';

	return 0;
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

//全ビット構成を表示させる関数の定義。
void print_bits(unsigned x)
{
	cout	<<"2進数：";

	for(int i = int_bits() - 1; i >= 0; i--) {
			cout	<<((x >> i) & 1U ? '1' : '0');
		}

	cout	<<'\n';
}

//右回転させる関数の定義。
unsigned rrotate(unsigned x, int n)
{
	//回転させる。
	//nビット右にシフトして追い出したものと全ビット-n分だけ左にシフトして追い出した後の値を加算して求める。
	x = ((x >> n) + (x << (int_bits() - n )));

	//回転後の全ビットを表示して確認する。
	print_bits(x);

	return x;
}


//左回転させる関数の定義。
unsigned lrotate(unsigned x, int n)
{
	//回転させる。
	//nビット左にシフトして追い出したものと全ビット-n分だけ右にシフトして追い出した後の値を加算して求める。
	x = ((x << n) + (x >> (int_bits() - n )));

	print_bits(x);

	return x;
}
