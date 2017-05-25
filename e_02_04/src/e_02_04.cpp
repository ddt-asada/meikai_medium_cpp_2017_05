/*演習2-4
 * 符号なし整数の第pos～pos+n-1ビットを1にした値を返す関数プログラム。
 * 作成日：2017年5月23日
 * 作成者：浅田　知嗣
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
unsigned set_n(unsigned x, int pos, int n);

//第posビットを0に変更する関数の宣言。
unsigned reset_n(unsigned x, int pos, int n);

//2進数を反転させた値を返す関数の宣言。
unsigned inverse_n(unsigned x, int pos, int n);

int main()
{
	unsigned	a;		//ビット構成を表示したい符号なし整数。
	int			pos;	//挿入したい桁数を入力する整数。
	int			n;		//何桁目までを変更するかの整数。

	//確かめたい整数の入力。
	cout	<<"非負の整数を入力せよ：";
	cin		>>a;

	//挿入先ビットを入力する。
	cout	<<"何桁目から：";
	cin		>>pos;

	//何ビット目まで変更するかを入力する。
	cout	<<"何桁目まで変更しますか：";
	cin		>>n;

	//挿入前のビット構成を表示。
	cout	<<"挿入前：\n";
	print_bits(a);

	//入力された値のnビットに1を挿入して2進数に変換して表示。
	cout	<<"挿入後：\n";
	cout	<<"10進数："	<<set_n(a, pos, n)	<<'\n';

	//入力された値をnビットに0を挿入して2進数に変換して表示。
	cout	<<"挿入後：\n";
	cout	<<"10進数："	<<reset_n(a, pos, n)	<<'\n';

	//入力された値の全ビットを反転させた値を2進数に変換して表示。
	cout	<<"反転後：\n";
	cout	<<"10進数："	<<inverse_n(a, pos, n)	<<'\n';

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
unsigned set_n(unsigned x, int pos, int n)
{
	for(int i = pos - 1; i < n; i++) {
		//元のビットの第pos～n－１ビット目までに1を挿入させていく。
		//対象のビットに1があった場合はそのまま、0だった場合は1を＋つまり1を挿入する。
		if((x >> i) & 1U) {
		} else {
			x += (1 << i);
		}
	}
	//全ビット構成を表示して確認する。
	print_bits(x);

	return x;
}

//第posビットを0に変更する関数の定義。
unsigned reset_n(unsigned x, int pos, int n)
{
	for(int i = pos - 1; i < n; i++) {
		//元のビットの第pos～n－１ビット目までに1を挿入させていく。
		//対象のビットに0があった場合はそのまま、1だった場合は1を‐つまり0を挿入する。
		if((x >> i) & 1U) {
			x -= (1 << i);
		}
	}

	//全ビット構成を表示して確認する。
	print_bits(x);

	return x;
}

//2進数を反転させた値を返す関数の定義。
unsigned inverse_n(unsigned x, int pos, int n)
{
	//反転させた全ビット攻勢を表示して確認する。
	print_bits(~x);

	return ~x;
}
