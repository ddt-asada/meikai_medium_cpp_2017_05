/*演習9-11
 * 抽象クラステンプレートを使用してキュークラス群とその利用例を実装したプログラムを作成。
 * 作成日：2017年6月5日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_VectorQue
#define ___Class_VectorQue

#include "e_09_11_Que.h"
#include <vector>

//配列によるキュークラステンプレート
template <class Type> class VectorQue : public Que<Type>
{
	std::vector<Type> stk;

public:

	//コンストラクタ
	VectorQue()
	{
	}

	//デストラクタ
	~VectorQue()
	{
	}

	//プッシュ
	void push(const Type& x)
	{
		//なんらかのエラーが出たときは例外を送出する。
		try {
			stk.push_back(x);
		}

		catch(...) {
		throw Que<char>::Overflow();
		}
	}

	//キュー
	Type que()
	{
		//スタックにプッシュされている中身を超えてキューしようとしたときに例外を送出する。
		if(stk.empty()) {
			throw Que<char>::Empty();
		}

		Type x = stk.front();		//先頭の値を調べる。
		stk.erase(stk.begin());		//先頭要素を削除。

		//スタックの中身を返す。
		return x;
	}
};

#endif
