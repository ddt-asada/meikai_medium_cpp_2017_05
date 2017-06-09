/*演習4-4
 * ポインタのアップキャストが行えるかどうかを確認するプログラム。
 * 作成日：2017年5月29日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#ifndef ___Member
#define ___Member

#include <string>

//一般会員クラス
class Member
{
	std::string full_name;	//氏名。
	int			number;		//会員番号。
	double		weight;		//体重。

public:
	//コンストラクタ
	Member(const std:: string& name, int no, double w)
	:full_name(name), number(no)
	{
		set_weight(w);
	}

	//full_nameのゲッタ。
	std::string name() const
	{
		return full_name;
	}

	//会員番号のゲッタ。
	int no() const
	{
		return number;
	}

	//体重のゲッタ。
	double get_weight() const
	{
		return weight;
	}

	//体重のセッタ。
	void set_weight(double w)
	{
		weight = (w > 0) ? w : 0;
	}
};

#endif
