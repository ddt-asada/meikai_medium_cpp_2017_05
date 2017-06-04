/*演習9-8
 * 配列クラステンプレートをインクルードモデルを使用して再現したプログラム
 * 作成日：2017年6月4日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_FixedArray
#define ___Class_FixedArray

//固定長配列クラステンプレート
template<class Type, int N> class FixedArray
{
	Type vec[N];		//Type型の要素数Nの配列。

public:
	//添字範囲エラーを送出するクラス。
	class IdxRngErr
	{
		const FixedArray* ident;
		int index;

	public:
		IdxRngErr(const FixedArray* p, int i);

		int Index() const;
	};

	//明示的コンストラクタ。
	explicit FixedArray(const Type& v = Type());

	//コピーコンストラクタ。
	FixedArray(const FixedArray& x);

	//要素数のゲッタ。
	int size() const;

	//代入演算子=
	FixedArray& operator=(const FixedArray& x);

	//添字演算子[]
	Type& operator[](int i);

	//添字演算子[]のconst版
	const Type& operator[](int i)const;


	void print_FixedArray(const FixedArray<Type, N>& a);
};



#include "e_09_08_ArrayFixedImplementation.h"
#endif
