/*演習6-3
 * じゃんけんクラス群の作成。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_Player
#define ___Class_Player

#include <iostream>
#include "e_06_03_Hand.h"

//じゃんけんクラス
class Player : public Hand
{
	int	hand;//じゃんけんの手の決定使う変数。

public:
	//コンストラクタ。
	Player() : hand(0)
	{
		int h;
		//手の選択を促す。
		std::cout	<<"出す手を選んでください。（0…グー / 1…チョキ / 2…パー）";
		std::cin	>>h;

		hand = h;
	}

	void whand() const
	{
		//出した手の判定を行う。
		switch(hand) {
		case 0:	std::cout	<<"あなたの出した手はグーです。\n";		break;
		case 1:	std::cout	<<"あなたの出した手はチョキです。\n";	break;
		case 2:	std::cout	<<"あなたの出した手はパーです。\n";		break;
		}
	}
};

#endif
