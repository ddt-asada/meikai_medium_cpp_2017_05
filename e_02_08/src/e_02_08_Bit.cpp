/*演習2-8
 * 要素数が制限されない、集合の下限値と上限値を任意に設定できるビットベクトル集合クラス作成。
 * 作成日：2017年5月26日
 * 作成者：浅田　知嗣
 */

#include <limits>
#include <string>
#include <sstream>
#include <iostream>
#include "e_02_08_Bit.h"

using namespace std;

//--- 文字列表現"{a, b, c}"を返却（要素をコンマで区切って{}で囲む）---//
string BitSet::to_string() const
{
	ostringstream s;
	int set[bitmax - bitmin + 1];			// 含まれる要素
	int count = 0;				// 要素数

	//中身に1が入っている箇所を調べる。
	//一回の繰り返しで32ビット分調べられる。
	for(int i = 1; i <= bitmax / LONG_BIT + 1; i++) {
		for (int j = 0; j < LONG_BIT; j++) {
			//もし1があった場合はあった場所つまりjを記憶。
			if (setbit[i] & set_of(j)) {
				//あった場所を記憶。
				//繰り返しが増えるごとに32を加算していく。
				set[count++] = j + bitmin + LONG_BIT * (i - 1);
			}
		}
	}

	s << "{";
	//配列の中に何かあった場合。
	if (count) {
		for (int i = 0; i < count - 1; i++) {
			s << set[i] << ", ";
		}
		s << set[count - 1];
	}
	s << "}";

	return s.str();
}

//--- ビットベクトルの文字列表現"010…10"を返却 ---//
void BitSet::bit_string() const
{
	//空集合の場合
	if(setbit[1] == 0) {

		for(int i = 0; i < LONG_BIT; i++) {
			cout	<<'0';
		}

	//空集合でない場合。
	} else {
		//まず、左から順にbitmax - bitminの分だけビットベクトルを出力。
		for(int i = 1; i <= bitmax / LONG_BIT + 1; i++) {
			for (int j = 0;(j < bitmax - bitmin - LONG_BIT * (i - 1) + 1) && (j < LONG_BIT); j++) {
				if(set_of(j) & setbit[i]) {
					cout	<<'1';

				} else {
					cout	<<'0';
				}
			}
		}

		//最後にbitminだけ0を出力し、桁数を合わせる。
		for(int i = 0; i < bitmin; i ++) {
		cout	<<'0';
		}
	}
}



//--- 挿入子 ---//
ostream& operator<<(ostream& os, const BitSet& x)
{
	return os << x.to_string();
}
