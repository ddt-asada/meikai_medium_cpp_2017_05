/*演習4-3
 * アップキャストとダウンキャストを試みるプログラム。
 * 作成日：2017年5月29日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <string>
#include <iostream>
#include "e_04_03.h"

using namespace std;

int main()
{
	//オブジェクトの生成。
	Base b(1, 2);
	Derived d(3, 4, 5);

	//基底クラスへのポインタが基底クラス型のオブジェクトを指す。
	Base* base1 = &b;
	//キャストではないためそのまま表示される。
	base1 -> func();
	cout	<<'\n';

	//基底クラスへのポインタが派生クラス型のオブジェクトを指す。
	Base* base2 = &d;
	//アップキャストのためそのまま表示される。
	base2 -> func();
	cout	<<'\n';

	//ダウンキャストのため表示不可なのでコメントアウト。
	//base2 -> method();
	//cout	<<'\n';


	//ダウンキャストのため実行不可なのでコメントアウト。
	//派生クラスへのポインタが基底クラス型のオブジェクトを指す。
	//Derived* derived1 = &b;
	//derived1 -> func();
	//cout	<<'\n';

	//派生クラスへのポインタが派生クラス型のオブジェクトを指す。
	Derived* derived1 = &d;
	derived1 -> method();
	cout	<<'\n';

	return 0;
}
