/*演習9-9
 * スタッククラステンプレートにメンバ関数を追加。
 * 作成日：2017年6月5日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#ifndef ___Class_SimpleStackImplementation
#define ___Class_SimpleStackImplementation

//スタッククラステンプレートのインクルードモデル
//明示的コンストラクタ
template<class Type>
SimpleStack<Type>::SimpleStack(int sz) : size(sz), ptr(0)
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

//ポップ
template<class Type>
Type SimpleStack<Type>::pop()
{
	//空のスタックからポップしようとしたときに例外を送出する。
	if(ptr <= 0) {
		throw Empty();
	}

	//スタックの中身を減らす。
	return stk[--ptr];
}

//頂上のデータを変更することなくそのまま返す。
template<class Type>
Type& SimpleStack<Type>::peek() const
{
	return stk[ptr];
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
