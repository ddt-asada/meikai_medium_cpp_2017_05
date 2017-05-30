/*演習7-1
 * 多重継承したクラス群のオブジェクトの初期化順を確認するプログラム。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 */

#include <iostream>

using namespace std;

//基底クラスAの定義。
class A
{
public:
	int xx;

	//コンストラクタ。
	A(int a = 0) : xx(a)
	{
		cout	<<"A::xxを"	<<xx	<<"に初期化しました。\n";
	}
};

//基底クラスBの定義。
class B
{
public:
	int xx;

	//コンストラクタ。
	B(int a = 0) : xx(a)
	{
		cout	<<"B::xxを"	<<xx	<<"に初期化しました。\n";
	}
};

//基底クラスA及びBからの派生クラスXの定義。
class X : public A, public B
{
public:
	int yy;

	//コンストラクタ。
	X(int a = 1, int b = 1, int c = 1) : yy(a), A(b), B(c)
	{
		cout	<<"X::yyを"	<<yy	<<"に初期化しました。\n";
	}
};

//基底クラスB及びAからの派生クラスYの定義。
class Y : public B, public A
{
public:
	int yy;

	//コンストラクタ。
	Y(int a = 1, int b = 1, int c = 1) : yy(a), B(b), A(c)
	{
		cout	<<"Y::yyを"	<<yy	<<"に初期化しました。\n";
	}
};

//派生クラスX及びYからの派生クラスZの定義。
class Z : public X, public Y
{
public:
	int zz;

	//コンストラクタ。
	Z(int a, int b, int c) : zz(a), X(b), Y(c)
	{
		cout	<<"Z::zzを"	<<zz	<<"に初期化しました。\n";
	}
};

//初期化の順序を確認するためのメイン部。
int main()
{
	Z test(1, 2, 3);

	return 0;
}
