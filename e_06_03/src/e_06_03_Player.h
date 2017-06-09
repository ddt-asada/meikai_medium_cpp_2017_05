/*演習6-3
 * じゃんけんクラス群の作成。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#ifndef ___Class_Player
#define ___Class_Player

#include <iostream>
#include "e_06_03_Check.h"

//じゃんけんクラス
class Player : public Check
{
	int phand;		//じゃんけんの手を選択する変数。
public:
	//コンストラクタ。
	Player(int h = 0) : phand(h)
	{

		//手の選択を促す。
		std::cout	<<"出す手を選んでください。（0…グー / 1…チョキ / 2…パー）";
		std::cin	>>h;

		phand = h;
	}

	//手を確認する関数。
	void whand() const
	{
		std::cout	<<"あなたの出したでは。";
		Check::whand(phand);
	}
};

#endif
