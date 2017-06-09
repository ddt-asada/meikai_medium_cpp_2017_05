/*演習9-8
 * 配列クラステンプレートをインクルードモデルを使用して再現したプログラム
 * 作成日：2017年6月4日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

// 配列クラステンプレートArray（bool型への特殊化）

#ifndef ___Class_Template_Array_BoolImplementation
#define ___Class_Template_Array_BoolImplementation

#include <limits>

// bool型sz個の要素の格納に必要なBYTE型配列の要素数
int Array<bool>::size_of(int sz)
{
	return (sz + CHAR_BITS - 1) / CHAR_BITS;
}

//コンストラクタ
Array<bool>::BitOfByteRef::BitOfByteRef(BYTE& r, int i) : vec(r), idx(i)
{
}
//真または偽に変換する。
Array<bool>::BitOfByteRef::operator bool() const
{
	return (vec >> idx) & 1U;
}

Array<bool>::BitOfByteRef& Array<bool>::BitOfByteRef::operator=(bool b)
{
	if (b) {
		vec |= 1U << idx;
	} else {
		vec &= ~(1U << idx);
	}

	return *this;
}

Array<bool>::IdxRngErr::IdxRngErr(const Array* p, int i) : ident(p), index(i)
{
}

int Array<bool>::IdxRngErr::Index() const
{
	return index;
}

//--- 明示的コンストラクタ ---//
Array<bool>::Array(int sz, bool v) : nelem(sz), velem(size_of(sz))
{
	vec = new BYTE[velem];
	for (int i = 0; i < velem; i++) {// 全要素を初期化
	vec[i] = v;
	}
}

//--- コピーコンストラクタ ---//
Array<bool>::Array(const Array& x)
{
	if (&x == this) {						// 初期化子が自分自身であれば…
		nelem = 0;
		vec = 0;
	} else {
		nelem = x.nelem;					// 要素数をxと同じにする
		velem = x.velem;					// 要素数をxと同じにする
		vec = new BYTE[velem];				// 配列本体を確保
		for (int i = 0; i < velem; i++) {	// 全要素をコピー
				vec[i] = x.vec[i];
		}
	}
}

//--- デストラクタ ---//
Array<bool>::~Array()
{
	delete[] vec;
}

//--- 要素数を返す ---//
int Array<bool>::size() const
{
	return nelem;
}

//ビットベクトルの配列の要素数を返す ---//
int Array<bool>::get_vsize() const
{
	int n = size();		//計算に使う配列の要素数。

	return (n + CHAR_BITS - 1) / CHAR_BITS;
}

//--- 代入演算子= ---//
Array<bool>& Array<bool>::operator=(const Array& x)
{
	if (&x != this) {					// 代入元が自分自身でなければ…
		if (velem != x.velem) {			// 代入前後の要素数が異なれば…
			delete[] vec;				// もともと確保していた領域を解放
			velem = x.velem;			// 新しい要素数
			vec = new BYTE[velem];		// 新たに領域を確保
		}
		nelem = x.nelem;				// 新しい要素数
		for (int i = 0; i < velem; i++) {	// 全要素をコピー
			vec[i] = x.vec[i];

		}
	}
	return *this;
}

//--- 添字演算子[] ---//

Array<bool>::BitOfByteRef  Array<bool>::operator[](int i)
{
	if (i < 0 || i >= nelem) {
		throw IdxRngErr(this, i);				// 添字範囲エラー送出
	}

	return BitOfByteRef(vec[i / CHAR_BITS], (i & (CHAR_BITS - 1)));
}

	//--- 添字演算子[] ---//
bool Array<bool>::operator[](int i) const
{
	if (i < 0 || i >= nelem) {
		throw IdxRngErr(this, i);				// 添字範囲エラー送出
	}

	return (vec[i / CHAR_BITS] >> (i & (CHAR_BITS - 1)) & 1U) == 1;
}

void print_Array_bool(const Array<bool>& a)
{
	for(int i = 0; i < a.size(); i++) {
		std::cout	<<(a[i] ? '1' : '0');
	}
}

#endif
