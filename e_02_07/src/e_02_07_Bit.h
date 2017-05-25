/*演習2-7
 * ビットベクトル集合クラスに対してメンバ関数を追加したものを作成。
 * 作成日：2017年5月24日
 * 作成者：浅田　知嗣
 * 更新日：2017年5月25日
 * 更新者；浅田　知嗣
 */

#ifndef ___Class_BitSet
#define ___Class_BitSet

#include <limits>
#include <string>
#include <iostream>

//===== ビットベクトルによる集合クラス =====//
class BitSet {
	// unsigned long型のビット数
	static const int LONG_BIT = std::numeric_limits<unsigned long>::digits;

	// 集合
	unsigned long bits;

	//--- vは要素として妥当な値（0以上LONG_BIT未満）か？ ---//
	static bool is_valid(int v) {
		return v >= 0 && v < LONG_BIT;
	}

	//--- eだけで構成される集合{e}のビットベクトルを生成 ---//
	static unsigned long set_of(int e) {
		return 1UL << e;
	}

public:
	//--- クラスBitSetで扱える要素の最大値と最小値を返却する静的メンバ関数 ---//
	static int max_element() { return LONG_BIT - 1; }
	static int min_element() { return 0; }

	//--- コンストラクタ ---//
	BitSet() : bits(0UL) { }					// 空集合を生成

	//--- コンストラクタ ---//
	BitSet(const int e[], int n) : bits(0UL) {	// int型配列から集合を生成
		for (int i = 0; i < n; i++)
			add(e[i]);
	}

	//--- 集合にeは含まれるか？ ---//
	bool contains(int e) const {
		return is_valid(e) && (bits & set_of(e));
	}
	//--- 集合に要素eを追加 ---//
	void add(int e) {
		if (is_valid(e))
			bits |= set_of(e);
	}

	//--- 集合から要素eを削除 ---//
	void remove(int e) {
		if (is_valid(e))
			bits &= ~set_of(e);
	}

	//--- 集合は空集合か？ ---//
	bool empty() const {
		return !bits;
	}

	//--- 集合に含まれる要素数を求める ---//
	int size() const {
		int count = 0;
		unsigned long x = bits;
		while (x) {
			x &= x - 1;
			count++;
		}
		return count;
	}

	//--- 集合rとの積集合に更新する ---//
	BitSet& operator&=(const BitSet& r) {
		bits &= r.bits;
		return *this;
	}

	//--- 集合rとの和集合に更新する ---//
	BitSet& operator|=(const BitSet& r) {
		bits |= r.bits;
		return *this;
	}

	//--- 集合rとの差集合に更新する ---//
	BitSet& operator^=(const BitSet& r) {
		bits ^= r.bits;
		return *this;
	}

	//--- 集合rと等しいか？ ---//
	bool operator==(const BitSet& r) const {
		return bits == r.bits;
	}

	//--- 集合rと等しくないか？ ---//
	bool operator!=(const BitSet& r) const {
		return bits != r.bits;
	}

	//-------------------------------------------------------------------
	//この下からが演習問題で追加したメンバ関数です。

	//集合の最小要素の値を返却する関数の宣言。
	int min() const;

	//集合の最大要素の値を返却する関数の宣言。
	int max() const;

	//集合の全要素を削除して空集合化する関数の宣言。
	void clear();

	//集合を集合rと交換する関数の宣言。
	void swap(BitSet&r);

	//集合s1とs2の対象差を求めて返却する関数。
	BitSet symmetric_difference(const BitSet& s1, const BitSet& s2);

	//集合s1とs2の積集合を求めて返却する演算子関数の宣言。
	//BitSet operator&(const BitSet& s1, const BitSet& s2);

	//集合s1とs2の和集合を求めて返却する演算子関数の宣言。
	//BitSet operator|(const BitSet& s1, const BitSet& s2);

	//集合s1とs2の差集合を求めて返却する演算子関数の宣言。
	//BitSet operator^(const BitSet& s1, const BitSet& s2);

	//集合がsの部分集合であるかどうかを判定する関数の宣言。
	bool is_subset_of(const BitSet& s);

	//集合がsの真部分集合であるかどうかを判定する関数の宣言。
	bool is_proper_subset_of(const BitSet& a);

	//ここまでが演習問題で追加したメンバ関数です。
	//--------------------------------------------------------------------

	//--- 文字列表現"{a, b, c}"を返却（要素をコンマで区切って{}で囲む）---//
	std::string to_string() const;

	//--- ビットベクトルの文字列表現"010…10"を返却---//
	std::string bit_string() const;
};

//--- 挿入子 ---//
std::ostream& operator<<(std::ostream& os, const BitSet& x);

#endif
