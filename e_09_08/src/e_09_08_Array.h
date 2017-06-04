/*演習9-8
 * 配列クラステンプレートをインクルードモデルを使用して再現したプログラム
 * 作成日：2017年6月4日
 * 作成者：浅田　知嗣
 */

#ifndef ___ClassTemplate_Array
#define ___ClassTemplate_Array

//配列のクラステンプレート
template <class Type> class Array
{
	int		nelem;		//配列の要素数。要素数のためintで固定。
	Type*	vec;		//配列の先頭要素へのポインタ。

	//添字が妥当かどうかを判定。この判定によって返却先で例外を送出する。
	bool is_valid_index(int idx);

public:
	//添字範囲エラーを送出するためのクラス。
	class IdxRngErr
	{
		const Array* ident;		//配列のクラステンプレートへのポインタ。
		int idx;				//エラーが出た配列の要素。
	public:
		//コンストラクタ
		IdxRngErr(const Array* p, int i);

		//エラーが出た場所を返す関数。
		int Index() const;
	};

	//明示的コンストラクタ
	explicit Array(int size, const Type& v = Type());

	//コピーコンストラクタ
	Array(const Array<Type>& x);

	//デストラクタ
	~Array();

	//要素数を返す。
	int size() const;

	//代入演算子。
	Type& operator=(const Array<Type>& x);

	//添字演算子[]
	Type& operator[](int i);

	/*
	//const版添字演算子[]
	const Type& operator[](int i) const;
	*/
};

#include "e_09_08_ArrayImplementation.h"
#endif
