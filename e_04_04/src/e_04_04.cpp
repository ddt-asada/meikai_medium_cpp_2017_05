/*演習4-4
 * ポインタのアップキャストが行えるかどうかを確認するプログラム。
 * 作成日：2017年5月29日
 * 作成者：浅田　知嗣
 */

#include <iostream>
#include <string>
#include "e_04_04_Member.h"
#include "e_04_04_ResigningMember.h"

using namespace std;

int main()
{
	//Member型のオブジェクトを生成。
	Member asada("浅田", 10, 55.5);

	//ResigningMember型のオブジェクトを生成。
	ResigningMember kazushi("知嗣", 22, 459);


	//派生クラスから基底クラスへのポインタの生成。
	//ResigningMember* member1 = &asada;

	//表示して確認する。
	//cout	<<"名前："	<<member1 -> name()	<<"\n会員番号："	<<member1 -> no();	<<"\n体重："	<<member1 -> get_weight()	<<'\n';

	return 0;

	//この結果よりアップキャストは行えなかった。
}
