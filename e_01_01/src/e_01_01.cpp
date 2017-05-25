/*演習1-1
 * データメンバの初期化がクラス定義のデータメンバの宣言順に行われていることを確認するプログラム。
 * 作成日：2017年5月20日
 * 作成者：浅田　知嗣
 */

#include <string>
#include <iostream>
#include "e_01_01_human.h"

using namespace std;

int main()
{
	//オブジェクトの生成。
	Human nakano("中野太郎", 173, 65);

	//体重を減らすセッタの呼び出し。
	nakano.slim_off(3);

	//各種ゲッタを呼び出し、中野に属するオブジェクトの中身を確認する。
	cout	<<"nakano = "	<<nakano.name()	<<" "	<<nakano.get_height()	<<"cm "	<<nakano.get_weight()	<<"kg\n";

	//0を返す。
	return 0;
}
