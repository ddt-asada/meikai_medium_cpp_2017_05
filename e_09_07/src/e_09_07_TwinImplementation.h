/*演習9-7
 * クラステンプレートTwinをインクルードモデルを使用して実現。
 * 作成日：2017年6月4日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#ifndef ___Class_TwinImplmentation
#define ___Class_TwinImplmentation

#include <utility>
#include <algorithm>
#include <string>


//コンストラクタ
template<class Type>
Twin<Type>::Twin(const Type& f, const Type& s) : v1(f), v2(s)
{
}

//コピーコンストラクタ
template<class Type>
Twin<Type>::Twin(const Twin<Type>& t) : v1(t.first()), v2(t.second())
{
}

//第1値のゲッタ
template<class Type>
Type Twin<Type>::first() const
{
	return v1;
}

//第1値のゲッタ兼セッタ
template<class Type>
Type& Twin<Type>::first()
{
	return v1;
}

//第2値のゲッタ
template<class Type>
Type Twin<Type>::second() const
{
	return v2;
}

//第2値のゲッタ兼セッタ
template<class Type>
Type& Twin<Type>::second()
{
	return v2;
}

//2値のセッタ。
template<class Type>
void Twin<Type>::set(const Type& f, const Type& s)
{
	Type::v1 = f;
	Type::v2 = s;
}

//小さい方の値。
template<class Type>
Type Twin<Type>::min() const
{
	return (Type::v1 < Type::v2 ? Type::v1 : Type::v2);
}

//第1値の方が小さいか。
template<class Type>
bool Twin<Type>::ascending() const
{
	return v1 < v2;
}

//ソート。
template<class Type>
void Twin<Type>::sort()
{
	if(!(v1 < v2)) {
		std::swap(v1, v2);
	}
}

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
