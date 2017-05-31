/*演習9-1
 * char型に特殊化した挿入子を作成する。
 * 作成日：2017年5月31日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_Twin
#define ___Class_Twin

#include <utility>
#include <algorithm>
#include <string>

//2値のクラステンプレート
template <class Type>class Twin
{
	Type v1;	//第1値
	Type v2;	//第2値

public:
	//コンストラクタ
	Twin(const Type& f = Type(), const Type& s = Type()) : v1(f), v2(s)
	{
	}

	//コピーコンストラクタ
	Twin(const Twin<Type>& t) : v1(t.first()), v2(t.second())
	{
	}

	//第1値のゲッタ
	Type first() const
	{
		return v1;
	}

	//第1値のゲッタ兼セッタ
	Type& first()
	{
		return v1;
	}

	//第2値のゲッタ
	Type second() const
	{
		return v2;
	}

	//第2値のゲッタ兼セッタ
	Type& second()
	{
		return v2;
	}

	//2値のセッタ。
	void set(const Type& f, const Type& s)
	{
		v1 = f;
		v2 = s;
	}

	//小さい方の値。
	Type min() const
	{
		return v1 < v2 ? v1 : v2;
	}

	//第1値の方が小さいか。
	bool ascending() const
	{
		return v1 < v2;
	}

	//ソート。
	void sort()
	{
		if(!(v1 < v2)) {
			std::swap(v1, v2);
		}
	}
};

//挿入子
template <class Type> inline std::ostream& operator<<(std::ostream& os, const Twin<Type>& t)
{
	return os << "["	<<t.first()	<<", "	<<t.second()	<<"]";
}

//string型へ特殊化した挿入子
template <> inline std::ostream& operator<<(std::ostream& os, const Twin<std::string>& st)
{
	return os	<<"[\""	<<st.first()	<<"\", \""	<<st.second()	<<"\"]";
}

//char型へ特殊化した挿入子
template <> inline std::ostream& operator<<(std::ostream& os, const Twin<char>& ct)
{
	return os	<<"[\'"	<<ct.first()	<<"\', \'"	<<ct.second()	<<"\']";
}

#endif
