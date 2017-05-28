/*演習3-13
 * 年・月・日を当てさせるプログラム。
 * 作成日：2017年5月28日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_SimpleDate
#define ___Class_SimpleDate

//日付クラス。
class SimpleDate
{
	int y;	//年
	int m;	//月
	int d;	//日

public:
	//コンストラクタ
	SimpleDate(int yy = 1, int mm = 1, int dd = 1)
	:y(yy), m(mm), d(dd) {}

	//年のゲッタ
	int year() const
	{
		return y;
	}

	//月のゲッタ。
	int month() const
	{
		return m;
	}

	//日のゲッタ
	int day() const
	{
		return d;
	}

	//年を減じた値を返却する関数。
	int comp_y(int yy) const
	{
		return yy - y;
	}

	//月を減じた値を返却する関数。
	int comp_m(int mm) const
	{
		return mm - m;
	}

	//日を減じた値を返却する関数。
	int comp_d(int dd) const
	{
		return dd - d;
	}
};

#endif
