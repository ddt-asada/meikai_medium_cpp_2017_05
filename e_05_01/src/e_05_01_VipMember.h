/*演習5-1
 * 会員クラス群に、自己紹介をする仮想関数inroduceを追加する。
 * 作成日；2017年5月29日
 * 作成者：浅田　知嗣
 */

#ifndef ___VipMember
#define ___VipMember

#include <string>
#include "e_05_01_Member.h"

//一般会員クラス。
class VipMember : public Member
{
	std::string privilege;		//得点。

public:
	//コンストラクタ。
	VipMember(const std::string& name, int no, double w, const std::string& prv);

	//特典のゲッタ。
	std::string get_privilege() const
	{
		return privilege;
	}

	//特典のセッタ。
	void set_privilege(const std::string& prv)
	{
		privilege = (prv != " ") ? prv : "未登録。";
	}

	//会員情報表示。
	void print() const;

	//自己紹介の表示。
	void introduce() const;
};

#endif
