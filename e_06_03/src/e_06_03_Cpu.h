/*演習6-3
 * じゃんけんクラス群の作成。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_Cpu
#define ___Class_Cpu

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "e_06_03_Hand.h"

//じゃんけんクラス
class Cpu : public Hand
{
	int	hand;//じゃんけんの手の決定使う変数。

public:
	//コンストラクタ。
	Cpu() : hand(0)
	{
		//乱数の種を決定。
		srand(time(NULL));

		//乱数により手を決定。
		int h = rand() % 3;

		//手の選択を促す。
		std::cout	<<"乱数により手を決定しました。\n";

		hand = h;
	}

	void whand() const
	{
		//出した手の判定を行う。
		switch(hand) {
		case 0:	std::cout	<<"CPUの出した手はグーです。\n";		break;
		case 1:	std::cout	<<"CPUの出した手はチョキです。\n";		break;
		case 2:	std::cout	<<"CPUの出した手はパーです。\n";		break;
		}
	}
};

#endif
