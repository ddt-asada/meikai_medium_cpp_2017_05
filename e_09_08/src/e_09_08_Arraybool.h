/*演習9-8
 * 配列クラステンプレートをインクルードモデルを使用して再現したプログラム
 * 作成日：2017年6月4日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

// 配列クラステンプレートArray（bool型への特殊化）

#ifndef ___Class_Template_Array_Bool
#define ___Class_Template_Array_Bool

#include <limits>
#include "e_09_08_Array.h"

//===== 配列クラステンプレートArray（bool型への特殊化）=====//
template<> class Array<bool> {
	typedef unsigned char BYTE;
	static const int CHAR_BITS = std::numeric_limits<unsigned char>::digits10;

	int nelem;		// bool型配列の要素数
	int velem;		// bool型配列を格納するためのBYTE型配列の要素数
	BYTE* vec;		// BYTE型先頭要素へのポインタ

	// bool型sz個の要素の格納に必要なBYTE型配列の要素数
	static int size_of(int sz);

public:
	//=== ビットベクトル（バイト）中の１ビットへの参照を表すためのクラス ===//
	class BitOfByteRef {
		BYTE& vec;		// 参照先BYTE
		int idx;		// 参照先BYTE中のビット番号

	public:
		BitOfByteRef(BYTE& r, int i);// コンストラクタ

		operator bool() const;		// 真偽を取得

		BitOfByteRef& operator=(bool b);
	};

	//----- 添字範囲エラー -----//
	class IdxRngErr {
		const Array* ident;
		int index;
	public:
		IdxRngErr(const Array* p, int i);

		int Index() const;
	};

	//--- 明示的コンストラクタ ---//
	explicit Array(int sz, bool v = bool());

	//--- コピーコンストラクタ ---//
	Array(const Array& x);

	//--- デストラクタ ---//
   ~Array();

	//--- 要素数を返す ---//
	int size() const;

	//ビットベクトルの配列の要素数を返す ---//
	int get_vsize() const;

	//--- 代入演算子= ---//
	Array& operator=(const Array& x);

	//--- 添字演算子[] ---//
	BitOfByteRef operator[](int i);

	//--- 添字演算子[] ---//
	bool operator[](int i) const;
};

void print_Array_bool(const Array<bool>& a);

#include "e_09_08_ArrayboolImplementation.h"
#endif
