/*演習5-1
 * 会員クラス群に、自己紹介をする仮想関数inroduceを追加する。
 * 作成日；2017年5月29日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <string>
#include <iostream>
#include "e_05_01_Member.h"

using namespace std;

//デストラクタの定義。
Member::~Member()
{
}

//コンストラクタの定義。
Member::Member(const string& name, int no, double w) : full_name(name), number(no)
{
	set_weight(w);
}

//会員情報の表示。
void Member::print()const
{
	cout	<<"No."	<<number	<<"："	<<full_name	<<"（"	<<weight	<<"kg）\n";
}

//自己紹介の表示。
void Member::introduce() const
{
	cout	<<"私の名前は"	<<full_name	<<"で体重は"	<<weight	<<"で会員番号は"	<<number	<<"です。\n";
}
