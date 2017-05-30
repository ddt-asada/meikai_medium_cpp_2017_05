/*演習6-3
 * じゃんけんクラス群の作成。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_Hand
#define ___Class_Hand

#include <iostream>

//じゃんけんクラス（抽象クラス）
class Hand
{
public:
	//純粋仮想デストラクタ。
	virtual ~Hand() = 0;

	//どの手を出したかを確認する純粋仮想関数。
	virtual void whand () const = 0;

};

//純粋仮想デストラクタ。
inline Hand::~Hand() { }

#endif
