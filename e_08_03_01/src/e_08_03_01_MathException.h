/*演習8-3
 * 例外ハンドラをクラス階層化したプログラム。
 * 作成日：2017年5月31日
 * 作成者：浅田　知嗣
 */

#ifndef ___Math_Exception
#define ___Math_Exception

//数値演算による例外。
class MathException {};

//0による徐算の例外。
class DividedByZero : public MathException
{
};

//オーバーフロー
class Overflow : public MathException
{
	int v;

public:
	Overflow(int val) : v(val) {}

	int value() const
	{
		return v;
	}
};

//アンダーフロー
class Underflow : public MathException
{
	int v;

public:
	Underflow(int val) : v(val) {}

	int value() const
	{
		return v;
	}
};

#endif
