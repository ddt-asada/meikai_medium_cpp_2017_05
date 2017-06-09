/*演習9-8
 * 配列クラステンプレートをインクルードモデルを使用して再現したプログラム
 * 作成日：2017年6月4日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#ifndef ___Class_FixedArrayImplementetion
#define ___Class_FixedArrayImplementetion


//添字範囲エラーを送出するクラス。
template<class Type, int N>
FixedArray<Type, N>::IdxRngErr::IdxRngErr(const FixedArray* p, int i) : ident(p), index(i)
{
}

template<class Type, int N>
int FixedArray<Type, N>::IdxRngErr::Index() const
{
	return index;
}

//明示的コンストラクタ。
template<class Type, int N>
FixedArray<Type, N>::FixedArray(const Type& v)
{
	for(int i = 0; i < N; i++) {
		vec[i] = v;
	}
}

//コピーコンストラクタ。
template<class Type, int N>
FixedArray<Type, N>::FixedArray(const FixedArray& x)
{
	if(&x != this) {
		for(int i = 0; i < N; i++) {
			vec[i] = x.vec[i];
		}
	}
}

//要素数のゲッタ。
template<class Type, int N>
int FixedArray<Type, N>::size() const
{
	return N;
}

//代入演算子=
template<class Type, int N>
FixedArray<Type, N>& FixedArray<Type, N>::operator=(const FixedArray& x)
{
	for(int i = 0; i < N; i++) {
		vec[i] = x.vec[i];
	}
}

//添字演算子[]
template<class Type, int N>
Type& FixedArray<Type, N>::operator[](int i)
{
	if(i < 0 || i >= N) {
		throw IdxRngErr(this, i);
	}

	return vec[i];
}

//添字演算子[]のconst版
template<class Type, int N>
const Type& FixedArray<Type, N>::operator[](int i) const
{
	if(i < 0 || i >= N) {
		throw IdxRngErr(this, i);
	}

	return vec[i];
}

template<class Type, int N>
void print_FixedArray(const FixedArray<Type, N>& a)
{
	std::cout	<<"{ ";

	for(int i = 0; i < a.size(); i++) {
		std::cout	<<a[i]	<<' ';
	}

	std::cout	<<"}";
}

#endif
