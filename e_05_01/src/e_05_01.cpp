/*演習5-1
 * 会員クラス群に、自己紹介をする仮想関数inroduceを追加する。
 * 作成日；2017年5月29日
 * 作成者：浅田　知嗣
 */

#include <iostream>
#include <typeinfo>
#include "e_05_01_Member.h"
#include "e_05_01_VipMember.h"
#include "e_05_01_SeniorMember.h"

using namespace std;

int main()
{
	//一般会員クラスのオブジェクトを生成。
	Member				asada("浅田", 15, 75.2);
	//特別会員クラスのオブジェクトを生成。
	VipMember			kazushi("知嗣", 17, 321, "会員費全額免除");
	//老人会員クラスのオブジェクトを生成。
	SeniorMember		senior("浅田知嗣", 43, 66.5, 3);

	//一般会員の情報を表示。
	asada.print();
	//自己紹介の表示。
	asada.introduce();

	//特別会員の情報を表示。
	kazushi.print();
	//自己紹介の表示。
	kazushi.introduce();

	//老人会員の情報を表示。
	senior.print();
	//自己紹介の表示。
	senior.introduce();
}
