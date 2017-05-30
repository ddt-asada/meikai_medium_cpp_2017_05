/*演習7-4
 * 図形クラス群に3次元クラスを追加する。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_ThreeDimensional
#define ___Class_ThreeDimensional
#include "e_07_04_TwoDimensional.h"

//2次元クラス（抽象クラス）
class ThreeDimensional : public TwoDimensional
{
public:
	//純粋仮想デストラクタ
	virtual ~ThreeDimensional() = 0;

	//面積を求める純粋仮想関数。
	virtual double get_volume() const = 0;
};

//純粋仮想デストラクタ。
inline ThreeDimensional::~ThreeDimensional() {}

#endif
