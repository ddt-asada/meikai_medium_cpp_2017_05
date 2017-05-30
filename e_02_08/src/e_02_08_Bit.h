/*演習2-8
 * 要素数が制限されない、集合の下限値と上限値を任意に設定できるビットベクトル集合クラス作成。
 * 作成日：2017年5月26日
 * 作成者：浅田　知嗣
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

	int bitmin;					//生成する範囲の下限値。

	int bitmax;					//生成する範囲の上限値。

	int n = bitmax / LONG_BIT + 1;	//配列の数。32以下の時に0とならないように1を+。

	unsigned long* setbit;		//ビットベクトルを格納する配列のポインタ。

	unsigned long bits;		//集合。

	//--- vは要素として妥当な値（0以上LONG_BIT未満）か？ ---//
	static bool is_valid(int v) {
		return v >= 0 && v <= LONG_BIT;
	}

	//--- eだけで構成される集合{e}のビットベクトルを生成 ---//
	static unsigned long set_of(int e) {
		return 1UL << e;
	}

public:
	//--- デフォルトコンストラクタ ---//
	BitSet() : bitmin(0), bitmax(0), setbit(&bits), bits(0UL) { }		// 空集合を生成

	//--- コンストラクタ ---//
	BitSet(int min, int max) : bitmin(min), bitmax(max){
		//nの要素をもつ配列を生成。
		setbit = new unsigned long[n];

		//集合の生成につかう仮の動的な配列。このコンストラクタを抜けるときに削除する。
		int* ad = new int[bitmax - bitmin + 2];

		//集合を生成する繰り返し。
		//32ビット生成するごとに集合の格納先を切り返す。
		for(int i = 1; i <= n; i++) {
			setbit[i] &= 0UL;	//集合を格納する配列を初期化。
			bits &= 0UL;		//集合を格納する配列を初期化。わかりやすいようにあえてここで初期化。

			//32ビットまたは生成の上限値になるまで繰り返す。
			for (int j = 1 ; (j <= bitmax - bitmin - LONG_BIT * (i - 1) + 1) && (j <= LONG_BIT); j++) {
				ad[j] = j - 1;
				add(ad[j]);
			}
			//出来た集合を配列に格納。
			setbit[i] = bits;
		}

		//集合を生成するのにつかった配列を削除。
		delete[] ad;
	}

	//--- 集合に要素eを追加 ---//
	void add(int e) {
		if (is_valid(e))
			bits |= set_of(e);
	}

	//--- 集合rとの積集合に更新する ---//
	BitSet& operator&=(const BitSet& r) {
		//上の配列からビットを削除することによりビットの桁数を大きい方に合わせる。
		r.setbit[r.n] >>= (bitmin - r.bitmin);

		//積集合を求めていく。
		for(int i = 1; i <= n; i++) {
			//お互いに要素がある間はお互いの積集合を求める。
			if(i <= r.n) {
				setbit[i] &= r.setbit[i];

			//要素がなくなったら0との積集合をもとめていく。
			} else {
				setbit[i] &= 0UL;
			}
		}

		//小さい方の上限値を新たな上限値として採用。
		bitmax = r.bitmax;

		return *this;
	}

	//--- 集合rとの和集合に更新する ---//
	BitSet& operator|=(BitSet& r) {
		//和集合として小さい方の下限値と大きい方の上限値を採用した新たな集合を生成し、返す。
		BitSet x(r.bitmin, bitmax);

		*this = x;

		return *this;
	}

	//--- 集合rとの差集合に更新する ---//
	BitSet& operator^=(const BitSet& r) {
	//上の配列からビットを削除することによりビットの桁数を大きい方に合わせる。
	r.setbit[r.n] >>= (bitmin - r.bitmin);

	//差集合を求めていく。
	for(int i = 1; i <= n; i++) {
		//お互いに要素がある間はお互いの差集合を求める。
		if(i <= r.n) {
			setbit[i] ^= r.setbit[i];

		//要素がなくなったら0との積集合をもとめていく。
		} else {
			setbit[i] ^= 0UL;
		}
	}

	//小さい方の上限値を新たな上限値として採用。
	bitmin = r.bitmin;

	return *this;
	}

	//--- 文字列表現"{a, b, c}"を返却（要素をコンマで区切って{}で囲む）---//
	std::string to_string() const;

	//--- ビットベクトルの文字列表現"010…10"を返却---//
	void bit_string() const;
};

//--- 挿入子 ---//
std::ostream& operator<<(std::ostream& os, const BitSet& x);

#endif
