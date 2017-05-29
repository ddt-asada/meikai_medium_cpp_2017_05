/*演習4-4
 * ポインタのアップキャストが行えるかどうかを確認するプログラム。
 * 作成日：2017年5月29日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_ResigningMember
#define ___Class_resigningMember

#include <string>
#include <iostream>
#include "e_04_04_Member.h"

//退会済み会員クラス。
class ResigningMember : private Member
{

public:
	//コンストラクタ
	ResigningMember(const std::string& name, int number, double w)
	: Member(name, number, w) { }

	//体重設定。
	double get_weight()
	{
		std::cout	<<"退会した会員の体重は取得できません。\n";
		return 0;
	}

	//メンバ関数noのアクセス権の調整。
	using Member::no;
};

#endif
