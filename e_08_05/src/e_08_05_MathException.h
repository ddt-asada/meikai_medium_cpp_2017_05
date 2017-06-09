/*演習8-5
 * 例外クラスのエラー内容をstring型で返却するように変更したプログラム。
 * 作成日：2017年5月31日
 * 作成者：浅田　知嗣
 */

#ifndef ___Math_Exception
#define ___Math_Exception

#include <string>

//数値演算による例外。
class MathException
{
public:
	virtual~MathException()
	{
	}

	virtual std::string what() const
	{
		std::string er ="数値演算例外\n";

		return er;
	}
};

//0による徐算の例外。
class DividedByZero : public MathException
{
public:
	std::string what() const
	{
		std::string er ="0による除算\n";

		return er;
	}
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

	std::string what() const
	{
		std::string er ="オーバーフロー\n";

		return er;
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

	std::string what() const
	{
		std::string er = "アンダーフロー\n";

		return er;
	}
};

#endif
