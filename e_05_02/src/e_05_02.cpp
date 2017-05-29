/*演習5-2
 * 会員クラス群に、参照渡しによるdynamiccastの動作を確認するプログラム。
 * 作成日；2017年5月29日
 * 作成者：浅田　知嗣
 */

#include <iostream>
#include <typeinfo>
#include "e_05_02_Member.h"
#include "e_05_02_VipMember.h"
#include "e_05_02_SeniorMember.h"

using namespace std;

//参照渡しの結果により情報を表示する関数。
void senior_print(Member& p);

int main()
{
	//一般会員クラスのオブジェクトを生成。
	Member				asada("浅田", 15, 75.2);
	//特別会員クラスのオブジェクトを生成。
	VipMember			kazushi("知嗣", 17, 321, "会員費全額免除");
	//老人会員クラスのオブジェクトを生成。
	SeniorMember		senior("浅田知嗣", 43, 66.5, 3);

	//一般会員の情報を表示。
	senior_print(asada);

	//特別会員の情報を表示。
	senior_print(kazushi);

	//老人会員の情報を表示。
	senior_print(senior);

	return 0;
}

//参照渡しの結果により情報を表示する関数。
void senior_print(Member& p)
{
	//例外送出。
	try {
		Member& d = dynamic_cast<SeniorMember&>(p);

		d.print();

	//キャストに失敗した時。
	} catch (bad_cast&) {
		cout	<<"キャストに失敗しました。\n";

	}
}
