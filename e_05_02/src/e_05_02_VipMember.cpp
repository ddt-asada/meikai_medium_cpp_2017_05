/*演習5-2
 * 会員クラス群に、参照渡しによるdynamiccastの動作を確認するプログラム。
 * 作成日；2017年5月29日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <string>
#include<iostream>
#include "e_05_02_VipMember.h"
#include "e_05_02_Member.h"

using namespace std;
VipMember::~VipMember()
{
}

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
