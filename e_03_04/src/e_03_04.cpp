/*演習3-4
 * 台形公式によって積分した値を返却する関数を作成。
 * 作成日：2017年5月31日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <iostream>

using namespace std;

//積分する対象となる関数の宣言。
double f(double x);

//積分の台形公式の関数の宣言。
double daikei(double x1, double x2, int n, double fp(double));

int main()
{
	double	a = 0;		//積分を求めたい区間の小さい方の値。
	double	b = 0;		//積分を求めたい区間の大きい方の値。

	int		n = 0;		//積分区間を何分割するかの値。この数値を大きくするほど積分の精度が上がっていく。

	//積分を求めることを明示する。
	cout	<<"関数f(x) = x^2 の積分をもとめます。\n";
	cout	<<"どの区間で求めますか\n";

	//積分区間の小さい方の値の入力を促す。
	cout	<<"下限値：";
	cin		>>a;

	//積分区間の大きい方の値の入力を促す。
	cout	<<"上限値：";
	cin		>>b;

	//何分割するかの入力を促す。
	cout	<<"分割数：";
	cin		>>n;

	//台形公式により積分を求める関数を呼び出し、その結果を出力。
	cout	<<"区間 [ "	<<a	<<"～"	<<b	<<" ] の間で"	<<n	<<"分割して積分をもとめました。\n";
	cout	<<"結果は："	<<daikei(a, b, n, f)	<<"です。\n";

	return 0;
}

//積分する対象となる関数の定義。
double f(double x)
{
	//今回は仮に、与えられた整数の2乗を返す関数とする。
	return x * x;
}

//積分の台形公式の関数の定義。
double daikei(double x1, double x2, int n, double fp(double))
{
	double	integral = 0;		//求めた積分を代入する型。

	double	h = (x2 - x1) / n;	//台形公式を利用する際に必要となる求めたい区間の一つ当たりの幅。

	//積分の台形公式。
	for(int i = 0; i < n; i++) {
		//台形公式を適用し計算結果を代入する型に加算していく。
		integral += (fp(x1 + (i - 1) * h) + fp(x1 + i * h)) / 2;
	}

	//求めた区間x1～x2の積分を返す。
	return integral;
}
