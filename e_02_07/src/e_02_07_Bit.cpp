/*演習2-7
 * ビットベクトル集合クラスに対してメンバ関数を追加したものを作成。
 * 作成日：2017年5月24日
 * 作成者：浅田　知嗣
 * 更新日：2017年5月25日
 * 更新者；浅田　知嗣
 */

#include <limits>
#include <string>
#include <sstream>
#include <iostream>
#include "e_02_07_Bit.h"

using namespace std;

//--- 文字列表現"{a, b, c}"を返却（要素をコンマで区切って{}で囲む）---//
string BitSet::to_string() const
{
	ostringstream s;
	int set[LONG_BIT];			// 含まれる要素
	int count = 0;				// 要素数

	for (int i = 0; i < LONG_BIT; i++)
		if (bits & set_of(i)) set[count++] = i;

	s << "{";
	if (count) {
		for (int i = 0; i < count - 1; i++)
			s << set[i] << ", ";
		s << set[count - 1];
	}
	s << "}";

	return s.str();
}

//--- ビットベクトルの文字列表現"010…10"を返却 ---//
string BitSet::bit_string() const
{
	char bp[LONG_BIT + 1];		// 含まれる要素

	for (int i = LONG_BIT - 1; i >= 0; i--)
		bp[LONG_BIT - i - 1] = (set_of(i) & bits) ? '1' : '0';
	bp[LONG_BIT] = '\0';

	return string(bp);
}

//-------------------------------------------------------------------
//この下からが演習問題で追加したメンバ関数です。

//集合の最小要素の値を返却する関数の定義。
int BitSet::min() const
{
	int min = -1;	//見つけた要素の値を代入する変数。もし値が見つからなかった場合は-1を返したいので-1で初期化しておく。

	//集合の全要素を右に１ずつシフトしていき、もし1が見つかった場合それを返す関数。
	for(int i = 0; i < LONG_BIT; i++) {
		//もし右にシフトしてる最中に最下位になったビットとの論理積が帰ってきたら、そこを最小値とする。
		if((bits >> i) & 1UL) {
			min = i;		//要素の値を代入。
			break;
		}
	}

	//求めた最小の値を返す。
	return min;
}

//集合の最大要素の値を返却する関数の定義。
int BitSet::max() const
{
	int max = -1;	//見つけた要素の値を代入する変数。もし値が見つからなかった場合は-1を返したいので-1で初期化しておく。

	//集合の全要素を右に全てシフトした状態から左にシフトしていき、もし1が見つかった場合それを返す関数。
	for(int i = LONG_BIT - 1; i >= 0; i--) {
		//もし左にシフトしてる最中に最下位になったビットとの論理積が帰ってきたら、そこを最小値とする。
		if((bits >> i) & 1UL) {
			max = i;		//要素の値を代入。
			break;
		}
	}

	//求めた最小の値を返す。
	return max;
}

//集合の全要素を削除して空集合化する関数の定義。
void BitSet::clear()
{
	//集合の中身がなくなるまで繰り返す。
	for( ; bits ; ) {
		//1を引いた論理積に更新していく。
		bits &= bits - 1;
	}
}

//集合を集合rと交換する関数の宣言。
void BitSet::swap(BitSet& r)
{
	BitSet swap;	//デフォルトコンストラクタよりから行列を生成。ここを交換するときの仮の置き場とする

	//交換していく
	swap.bits = bits;
	bits = r.bits;
	r.bits = swap.bits;
}

//集合s1とs2の対象差を求めて返却する関数。
BitSet BitSet::symmetric_difference(const BitSet& s1, const BitSet& s2)
{
	BitSet d1;		//計算するための空集合を生成。
	BitSet d2;		//計算するための空集合を生成。

	d1.bits = s1.bits ^ s2.bits;	//s1とs2の差を求める。
	d2.bits = s2.bits ^ s1.bits;	//s2とs1の差を求める。
	d1 &= d2;
	return d1;
}
/*
//集合s1とs2の積集合を求めて返却する演算子関数の定義。
BitSet operator&(const BitSet& s1, const BitSet& s2)
{
	return (s1.bits & s2.bits);
}

//集合s1とs2の和集合を求めて返却する演算子関数の定義。
BitSet operator|(const BitSet& s1, const BitSet& s2)
{
	return (s1.bits | s2.bits);
}

//集合s1とs2の差集合を求めて返却する演算子関数の定義。
BitSet operator^(const BitSet& s1, const BitSet& s2)
{
	return (s1.bits ^ s2.bits);
}
*/
//集合がsの部分集合かどうかを判定する関数の定義。
bool BitSet::is_subset_of(const BitSet& s)
{
	bool jugde = 0;		//bool型の判定を見る変数を宣言。もし見つからなかった場合は偽としてそのまま返したいので0で初期化。
	//集合の全要素をしらべる。
	for(int i = 0; i < LONG_BIT; i++){
		//集合をiビットずつ右にシフトしていき、その時に1が見つかったとき、つまり集合の要素を見つけたとき。
		if((bits >> i) & 1UL) {
			//その時の要素と集合sを渡した要素が対象の集合に含まれるかどうか調べる関数に渡す。
			jugde = s.contains(i);
		}
	}

	//最終的に判定がどうなったかを返す。
	return jugde;
}

//集合がsの真部分集合かどうかを判定する関数の定義。
bool BitSet::is_proper_subset_of(const BitSet& s)
{
	bool jugde = 0;		//bool型の判定を見る変数を宣言。もし見つからなかった場合は偽としてそのまま返したいので0で初期化。

	//集合が等しいかどうかを調べる。
	//もし等しい場合は真部分集合ではないので判定を行うわずそのまま偽を返す。
	if(bits != s.bits) {
		//集合の全要素をしらべる。
		for(int i = 0; i < LONG_BIT; i++){
			//集合をiビットずつ右にシフトしていき、その時に1が見つかったとき、つまり集合の要素を見つけたとき。
			if((bits >> i) & 1UL) {
				//その時の要素と集合sを渡した要素が対象の集合に含まれるかどうか調べる関数に渡す。
				jugde = s.contains(i);
			}
		}
	} else if (bits == s.bits) {
		jugde = 0;
	}

	//最終的に判定がどうなったかを返す。
	return jugde;
}

//--- 挿入子 ---//
ostream& operator<<(ostream& os, const BitSet& x)
{
	return os << x.to_string();
}
