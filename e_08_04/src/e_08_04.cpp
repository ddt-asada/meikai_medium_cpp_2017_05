#include <iostream>

#include "e_08_04_MathException.h"

using namespace std;

//計算結果が0以上99以下かどうかを判定する関数の宣言。
int check(int value);

//加算する関数の宣言。
int add2(int x, int y);

//減算する関数の宣言。
int sub2(int x, int y);

//乗算する関数の宣言。
int mul2(int x, int y);

//除算する関数の宣言。
int div2(int x, int y);

int main()
{
	int x, y;		//加減乗算する値。

	//範囲外の時は入力を繰りかえす。
	do {
		cout	<<"xの値：";
		cin		>>x;
	} while (x < 0 || x > 99);

	//範囲外の時は入力を繰りかえす。
	do {
		cout	<<"yの値：";
		cin		>>y;
	} while (y < 0 || y > 99);

	//例外補足。
	try {
		//加減乗算する関数に値を渡していき、例外が発生した場合はそこで終了。
		cout	<<"x + y = "	<<add2(x, y)	<<'\n';

		cout	<<"x - y = "	<<sub2(x, y)	<<'\n';

		cout	<<"x * y = "	<<mul2(x, y)	<<'\n';

		cout	<<"x / y = "	<<div2(x, y)	<<'\n';
	}

	//例外補足。
	catch (const MathException& e) {
		cout	<<"MathExceptionを捕捉：\n";
		e.display();
	}

	cout	<<"プログラム終了！！\n";

	return 0;
}

//計算結果が0以上99以下かどうかを判定する関数の定義。
int check(int value)
{
	//範囲外の時は例外クラスを呼び出す。
	if(value < 0) {
		throw Underflow(value);
	}

	//範囲外の時は例外クラスを呼び出す。
	if(value > 99) {
		throw Overflow(value);
	}

	return value;
}

//加算する関数の定義。
int add2(int x, int y)
{
	//計算結果が範囲内かどうか判定する関数を呼び出しもし範囲内であった場合にはその値を返却する。
	return check(x + y);
}

//減算する関数の宣言。
int sub2(int x, int y)
{
	//計算結果が範囲内かどうか判定する関数を呼び出しもし範囲内であった場合にはその値を返却する。
	return check(x - y);
}

//乗算する関数の宣言。
int mul2(int x, int y)
{
	//計算結果が範囲内かどうか判定する関数を呼び出しもし範囲内であった場合にはその値を返却する。
	return check(x * y);
}

//除算する関数の宣言。
int div2(int x, int y)
{
	if(y == 0) {
		throw DividedByZero();
	}
	//計算結果が範囲内かどうか判定する関数を呼び出しもし範囲内であった場合にはその値を返却する。
	return check(x / y);
}
