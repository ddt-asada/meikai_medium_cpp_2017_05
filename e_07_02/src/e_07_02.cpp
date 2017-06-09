/*演習7-1
 * 多重継承したクラス群に関数を追加したプログラム。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <iostream>

using namespace std;

//基底クラスBase1の定義。
class Base1
{
public:
	int x;

	//コンストラクタ。
	Base1(int a = 0) : x(a)
	{
		cout	<<"Base1::xを"	<<x	<<"に初期化しました。\n";
	}

	//文字列を表示する関数。
	void print()
	{
		cout	<<"Base1クラスです: x = "<<x	<<'\n';
	}
};

//基底クラスBase2の定義。
class Base2
{
public:
	int x;

	//コンストラクタ。
	Base2(int a = 0) : x(a)
	{
		cout	<<"Base2::xを"	<<x	<<"に初期化しました。\n";
	}

	//文字列を表示する関数。
	void print()
	{
		cout	<<"Base2クラスです: x = "<<x	<<'\n';
	}
};

//基底クラスBase1及びBase2からの派生クラスXの定義。
class Derived : public Base1, public Base2
{
public:
	int y;

	//コンストラクタ。
	Derived(int a, int b, int c) : Base1(a), Base2(b), y(c)
	{
		cout	<<"Derived::yを"	<<y	<<"に初期化しました。\n";
	}
	//文字列を表示する関数。
	void print()
	{
		Base1::print();
		Base2::print();
		cout	<<"Derivedクラスです: y = "<<y	<<'\n';
	}
};
int main()
{
	//表示を確認する。
	Derived z(1, 2, 3);

	z.print();

	return 0;
}
