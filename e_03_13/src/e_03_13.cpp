/*演習3-13
 * 年・月・日を当てさせるプログラム。
 * 作成日：2017年5月28日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <iostream>
#include "e_03_13_Date.h"

using namespace std;

int main()
{
	typedef int (SimpleDate::*Comp)(int) const;

	//関数へのポインタの配列の宣言。
	Comp pcomp[] = {&SimpleDate::comp_y,
					&SimpleDate::comp_m,
					&SimpleDate::comp_d,
	};

	int diff;		//当てるべき値を格納する型。

	int value;		//予想した日付を格納する型。

	const SimpleDate birthday(1963, 11, 18);	//自分の誕生日を格納したオブジェクトを生成。

	cout	<<"私の誕生日を当てて下さい。\n";

	//年を当てるまでループする。
	do {
		cout	<<"何年でしょうか\n";
		cin		>>value;

		//年数の差を求めるメンバ関数を呼び出し、返ってきた値で正解かどうかを判定する。
		diff = (birthday.*pcomp[0])(value);

		//返ってきた年が0の時。すなわち正解の時。
		if (!diff) {
			cout	<<"正解です。\n";

		//返ってきた年が答えよりも大きい場合。
		} else if (diff > 0) {
			cout	<<diff	<<"だけ大きいです。\n";

		//返ってきた年が答えより小さい場合。
		} else {
			cout	<<-diff	<<"だけ小さいです。\n";
		}

	//正解するまでループする。
	}while (diff);

	//月を当てるまでループする。
	do {
		cout	<<"何月でしょうか\n";
		cin		>>value;

		//月の差を求めるメンバ関数を呼び出し、返ってきた値で正解かどうかを判定する。
		diff = (birthday.*pcomp[1])(value);

		//返ってきた月が0の時。すなわち正解の時。
		if (!diff) {
			cout	<<"正解です。\n";

		//返ってきた月が答えよりも大きい場合。
		} else if (diff > 0) {
			cout	<<diff	<<"だけ大きいです。\n";

		//返ってきた月が答えより小さい場合。
		} else {
			cout	<<-diff	<<"だけ小さいです。\n";
		}

	//正解するまでループする。
	}while (diff);

	//日を当てるまでループする。
	do {
		cout	<<"何日でしょうか\n";
		cin		>>value;

		//日の差を求めるメンバ関数を呼び出し、返ってきた値で正解かどうかを判定する。
		diff = (birthday.*pcomp[2])(value);

		//返ってきた日が0の時。すなわち正解の時。
		if (!diff) {
			cout	<<"正解です。\n";

		//返ってきた日が答えよりも大きい場合。
		} else if (diff > 0) {
			cout	<<diff	<<"だけ大きいです。\n";

		//返ってきた日が答えより小さい場合。
		} else {
			cout	<<-diff	<<"だけ小さいです。\n";
		}

	//正解するまでループする。
	}while (diff);

	return 0;
}
