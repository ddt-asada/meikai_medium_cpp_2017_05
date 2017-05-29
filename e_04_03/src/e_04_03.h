/*演習4-3
 * アップキャストとダウンキャストを試みるプログラム。
 * 作成日：2017年5月29日
 * 作成者：浅田　知嗣
 */

#ifndef ___Member
#define ___Member

#include <iostream>

//基底クラス
class Base
{
	int a;
	int b;

public:
	//コンストラクタの定義。
	Base(int aa, int bb)
	:a(aa), b(bb){ }

	void func() const
	{
		std::cout	<<"a = "	<<a	<<'\n';
		std::cout	<<"b = "	<<b	<<'\n';
	}
};

//派生クラス。
class Derived : public Base
{
	int x;

public:
	//コンストラクタの定義。
	Derived(int aa, int bb, int xx)
	//基底クラスのコンストラクタを呼び出す。
	:Base(aa, bb), x(xx) { }

	void method() const
	{
		func();
		std::cout	<<"x = "	<<x	<<'\n';
	}
};

#endif
