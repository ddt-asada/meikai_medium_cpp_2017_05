/*演習5-1
 * 会員クラス群に、自己紹介をする仮想関数inroduceを追加する。
 * 作成日；2017年5月29日
 * 作成者：浅田　知嗣
 */

#ifndef ___SeniorMember
#define ___SeniorMember

#include <string>
#include "e_05_01_Member.h"

//長寿会員クラス。
class SeniorMember : public Member
{
	int care_level;		//要介護レベル。

public:
	//コンストラクタ。
	SeniorMember(const std::string& name, int no, double w, int level = 0);

	//要介護度ののゲッタ。
	int get_care_level() const
	{
		return care_level;
	}

	//要介護度のセッタ。
	void set_care_level(int level)
	{
		care_level = (level >= 1 && level <= 5) ? level : 0;
	}

	//会員情報表示。
	void print() const;

	//自己紹介の表示。
	void introduce() const;
};

#endif
