/*演習4-2
 * デコンストラクタの呼び出し順を確認するプログラム。
 * 作成日：2017年5月29日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <iostream>

using namespace std;

//基底クラスを定義。
class Base
{
	int x;

public:
	//デフォルトコンストラクタの定義。
	Base(int a = 0) : x(a)
	{
		cout	<<"Base::xを"	<<x	<<"で初期化。\n";
	}

	//デコンストラクタの定義。
	~Base()
	{
		cout	<<"Base::xを"	<<x	<<"削除。\n";
	}
};

//べつのクラスを定義。
class Memb
{
	int x;

public:
	//デフォルトコンストラクタの定義。
	Memb(int a = 0) : x(a)
	{
		cout	<<"Memb::xを"	<<x	<<"で初期化。\n";
	}

	//デコンストラクタの定義。
	~Memb()
	{
		cout	<<"Memb::xを"	<<x	<<"削除。\n";
	}
};

//派生クラスを定義。
class Derived : public Base
{
	int y;		//コンストラクタの関数に渡す変数。
	Memb m1;	//べつのクラスを呼び出す。
	Memb m2;	//別のクラスを呼び出す。
	void say()
	{
		y = 0;
		cout	<<"Derived::yを"	<<y	<<"で初期化。\n";
	}

public:
	//デフォルトコンストラクタの定義。
	Derived()
	{
		say();
	}

	//コンストラクタの定義。
	Derived(int a, int b, int c) :Base(c), m1(a), m2(b)
	{
		say();
	}

	//デコンストラクタの定義。
	~Derived()
	{
		cout	<<"Derived::y"	<<y	<<"を削除。\n";
	}
};

int main()
{
	//クラスを呼び出して削除順を確認。。
	Derived d1;

	cout	<<'\n';

	//削除順を確認。。
	Derived d2(1, 2, 3);

	return 0;
}
