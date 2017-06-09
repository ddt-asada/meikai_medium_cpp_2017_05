/*演習5-2
 * 会員クラス群に、参照渡しによるdynamiccastの動作を確認するプログラム。
 * 作成日；2017年5月29日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#ifndef ___SeniorMember
#define ___SeniorMember

#include <string>
#include "e_05_02_Member.h"

//長寿会員クラス。
class SeniorMember : public Member
{
	int care_level;		//要介護レベル。

public:
	~SeniorMember();

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
