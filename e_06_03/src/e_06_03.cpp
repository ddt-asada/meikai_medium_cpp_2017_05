/*演習6-3
 * じゃんけんクラス群の作成。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 */

#include <iostream>
#include "e_06_03_Hand.h"
#include "e_06_03_Cpu.h"
#include "e_06_03_Player.h"

using namespace std;

int main()
{
	//じゃんけんクラスへのポインタの配列を生成。
	Hand* a[] = {
			new Cpu(),
			new Player(),
	};


	//それぞれの手を確認する。
	//エラーが出ないようにiはunsigned型にしている。
	for(unsigned i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		cout	<<"それぞれの手を確認します。\n";
		a[i] -> whand();
		cout	<<'\n';

	}

	//勝ち負けの判定を行う。
	if(a[0] > a[1]) {
		cout	<<"CPUの勝ちです。\n";

	} else if (a[0] < a[1]) {
		cout	<<"あなたの勝ちです。\n";

	} else {
		cout	<<"あいこです。\n";
	}

	for(unsigned i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		delete a[i];
	}

	return 0;
}
