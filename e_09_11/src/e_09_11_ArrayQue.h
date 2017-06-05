/*演習9-11
 * 抽象クラステンプレートを使用してキュークラス群とその利用例を実装したプログラムを作成。
 * 作成日：2017年6月5日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_ArrayQue
#define ___Class_ArrayQue

#include "e_09_11_Que.h"

//配列によるキュークラステンプレート
template<class Type> class ArrayQue : public Que<Type>
{
	static const int size = 20;			//スタックの容量。
	int ptr;			//スタックのポインタ。
	int q;				//スタックからキューするための変数。
	Type* stk;			//スタックの本体の先頭要素へのポインタ。

public:
	//スタックが満タンの時にプッシュされたときに送出される例外クラス。

	//コンストラクタ
	ArrayQue() :ptr(0), q(0)
	{
		//スタックの容量を確保する。
		stk = new Type[size];
	}

	//デストラクタ
	~ArrayQue()
	{
		//スタックを削除する。
		delete[] stk;
	}

	//プッシュ
	void push(const Type& x)
	{
		//スタックの容量を超えてプッシュしようとしたときに例外を送出する。
		if(ptr >= size) {
			throw Que<char>::Overflow();
		}
		stk[ptr++] = x;
	}

	//キュー
	Type que()
	{
		//スタックにプッシュされている中身を超えてキューしようとしたときに例外を送出する。
		if(q >= ptr) {
			throw Que<char>::Empty();
		}

		//スタックの中身を減らす。
		return stk[q++];
	}
};

#endif
