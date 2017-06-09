/*演習8-4
 * 例外クラスに仮想関数を追加したものの動作を確認するプログラム。
 * 作成日：2017年5月31日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#ifndef ___Math_Exception
#define ___Math_Exception

//数値演算による例外。
class MathException
{
public:
	virtual~MathException()
	{
	}

	virtual void display() const
	{
		std::cout	<<"数値演算例外\n";
	}
};

//0による徐算の例外。
class DividedByZero : public MathException
{
public:
	void display() const
	{
		std::cout	<<"0による除算\n";
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

	void display() const
	{
		std::cout	<<"オーバーフロー（値は"	<<v	<<"）\n";
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

	void display() const
	{
		std::cout	<<"アンダーフロー（値は"	<<v	<<"）\n";
	}
};

#endif
