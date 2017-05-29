/*演習5-1
 * 会員クラス群に、自己紹介をする仮想関数inroduceを追加する。
 * 作成日；2017年5月29日
 * 作成者：浅田　知嗣
 */

#include <string>
#include<iostream>
#include "e_05_01_VipMember.h"
#include "e_05_01_Member.h"

using namespace std;

//コンストラクタの定義。
VipMember::VipMember(const string& name, int no, double w, const string& prv) : Member(name, no, w)
{
	set_privilege(prv);
}

//会員情報表示。
void VipMember::print()const
{
	cout	<<"No."	<<no()	<<"："	<<name()	<<"（"	<<get_weight()	<<"kg）\n"	<<"特典＝"	<<privilege	<<'\n';
}

//自己紹介の表示。
void VipMember::introduce() const
{
	cout	<<"私の名前は"	<<name()	<<"で体重は"	<<get_weight()	<<"で会員番号は"	<<no()	<<"で"	<<"今は"	<<privilege	<<"をもらってます。\n";
}
