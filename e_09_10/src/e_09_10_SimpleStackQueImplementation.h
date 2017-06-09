/*演習9-10
 * キューを実現するクラステンプレートの作成。
 * 作成日：2017年6月5日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#ifndef ___Class_SimpleStackQueImplementation
#define ___Class_SimpleStackQueImplementation

//スタッククラステンプレートのインクルードモデル
//明示的コンストラクタ
template<class Type>
Queue<Type>::Queue(int sz) : size(sz), count(0), ptr(0)
{
	//スタックの容量を確保する。
	stk = new Type[size];
}

//デストラクタ
template<class Type>
Queue<Type>::~Queue()
{
	//スタックを削除する。
	delete[] stk;
}

//プッシュ
template<class Type>
Type& Queue<Type>::push(const Type& x)
{
	//スタックの容量を超えてプッシュしようとしたときに例外を送出する。
	if(count >= size) {
		throw Queue<char>::Overflow();
	}

	//スタックに格納された要素数をカウントする。
	count++;

	//スタックにプッシュされたものを格納する
	return stk[ptr++ % size] = x;
}

//キュー
template<class Type>
Type Queue<Type>::pop()
{
	//スタックにプッシュされている中身を超えてキューしようとしたときに例外を送出する。
	if(0 >= count) {
		throw Queue<char>::Empty();
	}
	//保管していたスタックの中身を返す。
	return stk[(ptr - count--) % size];
}

//スタックの容量のゲッタ。
template<class Type>
int Queue<Type>::capacity() const
{
	return size;
}

//スタックが満杯かどうかを返す。
template<class Type>
bool Queue<Type>::is_full() const
{
	return (size <= count ? 1 : 0);
}

//スタックが空であるかどうかを返す。
template<class Type>
bool Queue<Type>::is_empty() const
{
	return (count == 0 ? 1 : 0);
}


#endif
