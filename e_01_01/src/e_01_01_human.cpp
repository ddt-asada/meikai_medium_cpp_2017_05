/*演習1-1
 * データメンバの初期化がクラス定義のデータメンバの宣言順に行われていることを確認するプログラム。
 * 作成日：2017年5月20日
 * 作成者：浅田　知嗣
 */

#include <string>
#include <iostream>
#include "e_01_01_human.h"

using namespace std;

//コンストラクタの定義。
Human::Human(const string& name, int h, int w)
:full_name(name), height(h), weight(w)
{}

//氏名のゲッタの定義。
string Human::name() const
{
	return full_name;
}

//身長のゲッタの定義。
int Human::get_height() const
{
	return height;
}

//体重のゲッタの定義。
int Human::get_weight() const
{
	return weight;
}

//体重のセッタの定義。
void Human::grow_fat(int dw)
{
	weight += dw;
}

//体重のセッタの定義。
void Human::slim_off(int dw)
{
	weight -= dw;
}
