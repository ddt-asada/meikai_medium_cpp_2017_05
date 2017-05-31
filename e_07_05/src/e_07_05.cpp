/*演習7-5
 * 仮想基底クラス群にデストラクタを追加し、呼び出し順を確認するプログラム。
 * 作成日：2017年5月31日
 * 作成者：浅田　知嗣
 */

#include <iostream>

using namespace std;

//基底クラスを宣言。
class V1
{
public:
	//コンストラクタ
	V1()
	{
		cout	<<"V1を初期化。\n";
	}

	//デコンストラクタ
	~V1()
	{
		cout	<<"V1を削除。\n";
	}
};

//基底クラスを宣言。
class V2
{
public:
	//コンストラクタ
	V2()
	{
		cout	<<"V2を初期化。\n";
	}

	//デコンストラクタ
	~V2()
	{
		cout	<<"V2を削除。\n";
	}
};

//仮想派生クラス
class X : virtual public V1, virtual public V2
{
public:
	//コンストラクタ
	X()
	{
		cout	<<"Xを初期化。\n";
	}

	//デコンストラクタ
	~X()
	{
		cout	<<"Xを削除。\n";
	}
};

//仮想派生クラス
class Y : virtual public V2, virtual public V1
{
public:
	//コンストラクタ
	Y()
	{
		cout	<<"Yを初期化。\n";
	}

	//デコンストラクタ
	~Y()
	{
		cout	<<"Yを削除。\n";
	}
};

//派生クラス
class Z : virtual public X, virtual public Y
{
public:
	//コンストラクタ
	Z()
	{
		cout	<<"Zを初期化。\n";
	}

	//デコンストラクタ
	~Z()
	{
		cout	<<"Zを削除。\n";
	}
};

int main()
{
	//派生クラスZを呼び出して初期化及び削除順を調べる。
	Z test;

	return 0;
}
