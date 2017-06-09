/*演習9-5
 * ビットベクトルの要素数を取得するゲッタを追加。
 * 作成日：2017年6月2日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

// 配列クラステンプレートArray（bool型への特殊化）

#ifndef ___Class_Template_Array_Bool
#define ___Class_Template_Array_Bool

#include <limits>
#include "e_09_05_Array.h"

//===== 配列クラステンプレートArray（bool型への特殊化）=====//
template<> class Array<bool> {
	typedef unsigned char BYTE;
	static const int CHAR_BITS = std::numeric_limits<unsigned char>::digits10;

	int nelem;		// bool型配列の要素数
	int velem;		// bool型配列を格納するためのBYTE型配列の要素数
	BYTE* vec;		// BYTE型先頭要素へのポインタ

	// bool型sz個の要素の格納に必要なBYTE型配列の要素数
	static int size_of(int sz) { return (sz + CHAR_BITS - 1) / CHAR_BITS; }

public:
	//=== ビットベクトル（バイト）中の１ビットへの参照を表すためのクラス ===//
	class BitOfByteRef {
		BYTE& vec;		// 参照先BYTE
		int idx;		// 参照先BYTE中のビット番号

	public:
		BitOfByteRef(BYTE& r, int i) : vec(r), idx(i) { }		// コンストラクタ

		operator bool() const { return (vec >> idx) & 1U; }		// 真偽を取得

		BitOfByteRef& operator=(bool b) {						// 真偽を設定
			if (b)
				vec |= 1U << idx;
			else
				vec &= ~(1U << idx);
			return *this;
		}
	};

	//----- 添字範囲エラー -----//
	class IdxRngErr {
		const Array* ident;
		int index;
	public:
		IdxRngErr(const Array* p, int i) : ident(p), index(i) { }
		int Index() const { return index; }
	};

	//--- 明示的コンストラクタ ---//
	explicit Array(int sz, bool v = bool()) : nelem(sz), velem(size_of(sz)) {
		vec = new BYTE[velem];
		for (int i = 0; i < velem; i++)		// 全要素を初期化
			vec[i] = v;
	}

	//--- コピーコンストラクタ ---//
	Array(const Array& x) {
		if (&x == this) {						// 初期化子が自分自身であれば…
			nelem = 0;
			vec = 0;
		} else {
			nelem = x.nelem;					// 要素数をxと同じにする
			velem = x.velem;					// 要素数をxと同じにする
			vec = new BYTE[velem];				// 配列本体を確保
			for (int i = 0; i < velem; i++)		// 全要素をコピー
				vec[i] = x.vec[i];
		}
	}

	//--- デストラクタ ---//
   ~Array() { delete[] vec; }

	//--- 要素数を返す ---//
	int size() const { return nelem; }

	//ビットベクトルの配列の要素数を返す ---//
	int get_vsize() const
		{
			int n = size();		//計算に使う配列の要素数。

			return (n + CHAR_BITS - 1) / CHAR_BITS;
		}
	//--- 代入演算子= ---//
	Array& operator=(const Array& x) {
		if (&x != this) {					// 代入元が自分自身でなければ…
			if (velem != x.velem) {			// 代入前後の要素数が異なれば…
				delete[] vec;				// もともと確保していた領域を解放
				velem = x.velem;			// 新しい要素数
				vec = new BYTE[velem];		// 新たに領域を確保
			}
			nelem = x.nelem;				// 新しい要素数
			for (int i = 0; i < velem; i++)	// 全要素をコピー
				vec[i] = x.vec[i];
		}
		return *this;
	}

	//--- 添字演算子[] ---//
	BitOfByteRef operator[](int i) {
		if (i < 0 || i >= nelem)
			throw IdxRngErr(this, i);				// 添字範囲エラー送出
		return BitOfByteRef(vec[i / CHAR_BITS], (i & (CHAR_BITS - 1)));
	}

	//--- 添字演算子[] ---//
	bool operator[](int i) const {
		if (i < 0 || i >= nelem)
			throw IdxRngErr(this, i);				// 添字範囲エラー送出
		return (vec[i / CHAR_BITS] >> (i & (CHAR_BITS - 1)) & 1U) == 1;
	}
};

#endif
