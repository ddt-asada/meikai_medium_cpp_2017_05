/*演習2-7
 * ビットベクトル集合クラスに対してメンバ関数を追加したものを作成。
 * 作成日：2017年5月24日
 * 作成者：浅田　知嗣
 * 更新日：2017年5月25日
 * 更新者；浅田　知嗣
 */

#include <iostream>
#include "e_02_07_Bit.h"

using namespace std;

//集合s1とs2を交換する非メンバ関数の宣言。
void swap(BitSet& s1, BitSet& s2);

int main()
{
	//デフォルトコンストラクタより空集合を生成する。
	BitSet b1;

	//集合の要素として1,3,5をもつ集合を生成する。
	int a[] = {1, 3, 5};
	BitSet b2(a, sizeof(a) / sizeof(a[0]));

	//集合の要素として16,9,20を持つ集合を生成する。
	int b[] = {16,9,20};
	BitSet b3(b, sizeof(b) / sizeof(b[0]));

	//集合の要素として1, 3, 5, 7, 9を持つ集合を生成する。
	int c[] = {1, 3, 5, 7, 9};
	BitSet b4(c, sizeof(c) / sizeof(c[0]));

	//集合を表示する。
	cout	<<"集合b1："	<<b1	<<"を生成しました。"	<<'\n';
	cout	<<"集合b2："	<<b2	<<"を生成しました。"	<<'\n';
	cout	<<"集合b3："	<<b3	<<"を生成しました。"	<<'\n';
	cout	<<"集合b4："	<<b4	<<"を生成しました。"	<<"\n\n";

	//集合の最小の要素数を調べて返却する関数を呼び出す。
	cout	<<"空集合b1の最小の要素は"	<<b1.min()	<<'\n';
	cout	<<"集合b2の最小の要素は"	<<b2.min()	<<'\n';
	cout	<<"集合b3の最小の要素は"	<<b3.min()	<<'\n';
	cout	<<"集合b4の最小の要素は"	<<b4.min()	<<"\n\n";

	//集合の最大の要素数を調べて返却する関数を呼び出す。
	cout	<<"空集合b1の最大の要素は"	<<b1.max()	<<'\n';
	cout	<<"集合b2の最大の要素は"	<<b2.max()	<<'\n';
	cout	<<"集合b3の最大の要素は"	<<b3.max()	<<'\n';
	cout	<<"集合b4の最大の要素は"	<<b4.max()	<<"\n\n";

	//集合の全要素を削除し、空集合にする関数を呼び出す。
	cout	<<"集合b3のすべての要素を削除します。\n"	<<"削除前："	<<b3;
	b3.clear();
	cout	<<"\n削除後："	<<b3	<<"\n\n";

	//集合を入れ替える関数を呼び出す。
	cout	<<"空集合b1と集合b2を入れ替えます。\n"	<<"入れ替え前\nb1："	<<b1	<<"\nb2："	<<b2	<<'\n';
	b1.swap(b2);
	cout	<<"入れ替え後\nb1："	<<b1	<<"\nb2："	<<b2	<<"\n\n";

	//集合を入れ替える関数を呼び出す。
	cout	<<"集合b1と空集合b2を入れ替えます。\n"	<<"入れ替え前\nb1："	<<b1	<<"\nb2："	<<b2	<<'\n';
	swap(b1, b2);
	cout	<<"入れ替え後\nb1："	<<b1	<<"\nb2："	<<b2	<<"\n\n";


	//集合s1とs2の対象差を求める関数を呼び出す。
	cout	<<"集合b2とb4の対象差："	<<b2.symmetric_difference(b2, b4)	<<"\n\n";

	//積集合を求めて表示。
	//cout	<<"集合b2とb4の積集合："	<<b2 & b4	<<"\n\n";

	//和集合を求めて表示。
//	cout	<<"集合b2とb3の和集合："	<<b2 | b3	<<"\n\n";

	//差集合を求めて表示。
	//cout	<<"集合b2とb4の差集合："	<<b2 ^ b4	<<"\n\n";

	//部分集合かどうかを調べる。
	cout	<<"集合b2は集合b4の部分集合"	<<(b2.is_subset_of(b4) ? "です。\n\n" : "ではありません。\n\n");

	//真部分集合かどうかを調べる。
	cout	<<"集合b2は集合b4の真部分集合"	<<(b2.is_proper_subset_of(b4) ? "です。\n\n" : "ではありません。\n\n");

	return 0;
}

//集合s1を集合s2と交換する非メンバ関数の定義。
void swap(BitSet& s1, BitSet& s2)
{
	BitSet swap;	//デフォルトコンストラクタよりから行列を生成。ここを交換するときの仮の置き場とする

	//交換していく
	swap = s1;
	s1 = s2;
	s2 = swap;
}
