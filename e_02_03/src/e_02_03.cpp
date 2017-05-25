/*演習2-3
 * 符号なし整数の第posビットを1にした値を返す関数プログラム。
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

//第posビットを1に変更する関数の宣言。
unsigned set(unsigned x, int pos);

//第posビットを0に変更する関数の宣言。
unsigned reset(unsigned x, int pos);

//2進数を反転させた値を返す関数の宣言。
unsigned inverse(unsigned x, int pos);

int main()
{
	unsigned	a;		//ビット構成を表示したい符号なし整数。
	int			pos;		//挿入したい桁数を入力する整数。

	//確かめたい整数の入力。
	cout	<<"非負の整数を入力せよ：";
	cin		>>a;

	//挿入シフトするかを入力する。
	cout	<<"何桁目に挿入しますか：";
	cin		>>pos;


	//挿入前のビット構成を表示。
	cout	<<"挿入前：\n";
	print_bits(a);

	//入力された値のnビットに1を挿入して2進数に変換して表示。
	cout	<<"挿入後：\n";
	cout	<<"10進数："	<<set(a, pos)	<<'\n';

	//入力された値をnビットに0を挿入して2進数に変換して表示。
	cout	<<"挿入後：\n";
	cout	<<"10進数："	<<reset(a, pos)	<<'\n';

	//入力された値の全ビットを反転させた値を2進数に変換して表示。
	cout	<<"反転後：\n";
	cout	<<"10進数："	<<inverse(a, pos)	<<'\n';

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

//第posビットを1に変更する関数の定義。
unsigned set(unsigned x, int pos)
{
	//対象のビットに1を挿入する。
	//もし対象ビットに1が入っていた場合はそのまま。
	if((x >> (pos - 1)) & 1U) {
	//もし0が入っていた場合は1を加算。つまり、1を挿入する。
	} else {
		x += (1 << (pos - 1));
	}

	//全ビット構成を表示して確認する。
	print_bits(x);

	return x;
}

//第posビットを0に変更する関数の定義。
unsigned reset(unsigned x, int pos)
{
	//対象のビットに0を挿入する。
	//もし対象ビットに0が入っていた場合はそのまま。
	//もし1が入っていたら1を減算する。つまり、0を挿入する。
	if((x >> (pos - 1)) & 1U) {
		x -= (1 << (pos - 1));
	}

	//全ビット構成を表示して確認する。
	print_bits(x);

	return x;
}

//2進数を反転させた値を返す関数の定義。
unsigned inverse(unsigned x, int pos)
{
	//反転させた全ビット構成を表示して確認する。
	print_bits(~x);

	return ~x;
}
