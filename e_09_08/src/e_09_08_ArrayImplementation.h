/*演習9-8
 * 配列クラステンプレートをインクルードモデルを使用して再現したプログラム
 * 作成日：2017年6月4日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#ifndef ___ClassTemplate_ArrayImplementation
#define ___ClassTemplate_ArrayImplementation

template<class Type>
bool Array<Type>::is_valid_index(int idx)
{
	return (idx >= 0 && idx < nelem);
}

template<class Type>
Array<Type>::IdxRngErr::IdxRngErr(const Array* p, int i) : ident(p), idx(i) { }

//エラーが出た場所を返す関数。
template<class Type>
int Array<Type>::IdxRngErr::Index() const
{
	return idx;
}


//明示的コンストラクタ
template<class Type>
Array<Type>::Array(int size, const Type& v) : nelem(size)
	{
		//配列を生成。
		vec = new Type[nelem];

		//配列の要素としてType型のデフォルトコンストラクタを代入する。
		for(int i = 0; i < nelem; i++) {
			vec[i] = v;
		}
	}

//コピーコンストラクタ
template<class Type>
Array<Type>::Array(const Array<Type>& x)
{
	//自己初期化に対応する。自己初期化の場合は空の配列とする。
	if(&x == this) {
		nelem = 0;
		vec = 0;

	} else {
		nelem = x.nelem;		//要素数のコピー
		vec = new Type[nelem];	//配列の本体を確保。

		//配列のコピー。
		for(int i = 0; i < nelem; i++) {
			vec[i] = x.vec[i];
		}
	}
}

//デストラクタ
template<class Type>
Array<Type>::~Array()
{
	delete[] vec;
}

//要素数を返す。
template<class Type>
int Array<Type>::size() const
{
	return nelem;
}

//代入演算子。
template<class Type>
Type& Array<Type>::operator=(const Array<Type>& x)
{
	//代入元が自分以外の時。
	if(&x != this) {
		//要素数が異なる場合。
		if(nelem != x.nelem) {
			delete[] vec;					//元の配列を削除。
			nelem	= x.nelem;				//要素数をコピー
			vec		= new Type[nelem];		//代入元の配列と要素数を合わせる。
		}

		//配列の全要素をコピー
		for(int i = 0; i < nelem; i++) {
			vec[i] = x.vec[i];
		}
	}

	//代入し終わった配列を返す。
	return *this;
}

//添字演算子[]
template<class Type>
Type& Array<Type>::operator[](int i)
{
	//添字を妥当性を確かめる関数に渡しもし、妥当でないという判定が返ってきた場合は例外を送出。
	if(!is_valid_index(i)) {
	//添字範囲のエラーのクラスを呼び出し、要素数と配列の情報を取得し、それを例外として送出する。
		throw IdxRngErr(this, i);
	}

	return vec[i];
}

/*
//const版添字演算子[]
template<class Type>
const Type& operator[](int i) const
{
	//添字を妥当性を確かめる関数に渡しもし、妥当でないという判定が返ってきた場合は例外を送出。
	if(! is_valid_index(i)) {
		//添字範囲のエラーのクラスを呼び出し、要素数と配列の情報を取得し、それを例外として送出する。
		throw IdxRngErr(this, i);
	}

	return vec[i];
}
*/

#endif
