/*演習4-1
 * 基底クラスのデフォルトコンストラクタが暗黙裏に呼び出されることを確認するプログラ。
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
	Base(int xx= 99) : x(xx)
	{
		cout	<<"Base::xを"	<<x	<<"で初期化。\n";
	}

	//xのゲッタ。
	int get_x() const
	{
		return x;
	}
};

//派生クラスを定義。
class Derived : public Base
{
	//コンストラクタを定義せずに暗黙裏に基底クラスのデフォルトコンストラクタが呼び出されるかを確認する。
};

int main()
{
	//引数を渡さずに基底クラスを呼び出す。
	Derived d;

	//引数を渡さずに派生クラスを呼び出す。
	Base b;

	return 0;
}
