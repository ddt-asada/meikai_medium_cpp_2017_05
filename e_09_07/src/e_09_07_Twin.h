/*演習9-7
 * クラステンプレートTwinをインクルードモデルを使用して実現。
 * 作成日：2017年6月4日
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
	Twin(const Type& f = Type(), const Type& s = Type());

	//コピーコンストラクタ
	Twin(const Twin<Type>& t);

	//第1値のゲッタ
	Type first() const;

	//第1値のゲッタ兼セッタ
	Type& first();

	//第2値のゲッタ
	Type second() const;

	//第2値のゲッタ兼セッタ
	Type& second();

	//2値のセッタ。
	void set(const Type& f, const Type& s);

	//小さい方の値。
	Type min() const;

	//第1値の方が小さいか。
	bool ascending() const;

	//ソート。
	void sort();
};


#include "e_09_07_TwinImplementation.h"
#endif
