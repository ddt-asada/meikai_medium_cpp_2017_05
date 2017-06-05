/*演習9-9
 * スタッククラステンプレートにメンバ関数を追加。
 * 作成日：2017年6月5日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_SimpleStackQueImplementation
#define ___Class_SimpleStackQueImplementation

//スタッククラステンプレートのインクルードモデル
//明示的コンストラクタ
template<class Type>
SimpleStack<Type>::SimpleStack(int sz) : size(sz), ptr(0), q(0)
{
	//スタックの容量を確保する。
	stk = new Type[size];
}

//デストラクタ
template<class Type>
SimpleStack<Type>::~SimpleStack()
{
	//スタックを削除する。
	delete[] stk;
}

//プッシュ
template<class Type>
Type& SimpleStack<Type>::push(const Type& x)
{
	//スタックの容量を超えてプッシュしようとしたときに例外を送出する。
	if(ptr >= size) {
		throw Overflow();
	}

	//スタックにプッシュされたものを格納する
	return stk[ptr++] = x;
}

//キュー
template<class Type>
Type SimpleStack<Type>::que()
{
	//スタックにプッシュされている中身を超えてキューしようとしたときに例外を送出する。
	if(q > ptr) {
		throw Empty();
	}

	//スタックの中身を減らす。
	return stk[q++];
}

//スタックの容量のゲッタ。
template<class Type>
int SimpleStack<Type>::capacity() const
{
	return size;
}

//スタックが満杯かどうかを返す。
template<class Type>
bool SimpleStack<Type>::is_full() const
{
	return (size <= ptr ? 1 : 0);
}

//スタックが空であるかどうかを返す。
template<class Type>
bool SimpleStack<Type>::is_empty() const
{
	return (ptr == 0 ? 1 : 0);
}


#endif
