/*演習6-3
 * じゃんけんクラス群の作成。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#ifndef ___Class_Cpu
#define ___Class_Cpu

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "e_06_03_Check.h"

//じゃんけんクラス
class Cpu : public Check
{
	int chand;		//じゃんけんの手を選択する変数。
public:
	//コンストラクタ。
	Cpu(int h = 0) :  chand(h)
	{
		//乱数の種を決定。
		srand(time(NULL));

		//乱数により手を決定。
		h = rand() % 3;

		//手の選択を促す。
		std::cout	<<"乱数により手を決定しました。\n";

		chand = h;
	}

	//手を確認する関数。
	void whand() const
	{
		std::cout	<<"CPUの出した手は";
		Check::whand(chand);
	}
};

#endif
