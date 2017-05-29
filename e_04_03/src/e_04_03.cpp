/*演習4-3
 * アップキャストとダウンキャストを試みるプログラム。
 * 作成日：2017年5月29日
 * 作成者：浅田　知嗣
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
	//cout	<<"aとbの値："	<<base1 -> func()		<<'\n';

	//基底クラスへのポインタが派生クラス型のオブジェクトを指す。
	Base* base2 = &d;
	//cout	<<"aとbの値："	<<base2 -> func()		<<'\n';
	//cout	<<"xの値："		<<base2 -> method()		<<'\n';

	//派生クラスへのおインタが基底クラス型のオブジェクトを指す。
	//Derived* derived1 = &b;
	//cout	<<"aとbの値："		<<derived1 -> func()	>>'\n';

	//派生クラスへのポインタが派生クラス型のオブジェクトを指す。
	//Derived* derived1 = &d;
//	cout	<<"aとbのx値："	<<derived1 -> method()	<<'\n';

	return 0;
}
