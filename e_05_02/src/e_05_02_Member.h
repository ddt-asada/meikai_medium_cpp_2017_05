/*演習5-2
 * 会員クラス群に、参照渡しによるdynamiccastの動作を確認するプログラム。
 * 作成日；2017年5月29日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#ifndef ___Member
#define ___Member

#include <string>

//一般会員クラス。
class Member
{
	std::string full_name;		//氏名。
	int			number;			//会員番号。
	double		weight;			//体重。

public:
	virtual ~Member();

	//コンストラクタ。
	Member(const std::string& name, int no, double w);

	//氏名のゲッタ。
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

	//体重設定のセッタ。
	void set_weight(double w)
	{
		weight = (w > 0) ? w : 0;
	}

	//会員情報表示。
	virtual void print() const;

	//自己紹介。
	virtual void introduce() const;
};

#endif
