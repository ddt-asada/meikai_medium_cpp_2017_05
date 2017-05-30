/*演習7-4
 * 図形クラス群に3次元クラスを追加する。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_TwoDimensional
#define ___Class_TwoDimensional

//2次元クラス（抽象クラス）
class TwoDimensional
{
public:
	//純粋仮想デストラクタ
	virtual ~TwoDimensional() = 0;

	//面積を求める純粋仮想関数。
	virtual double get_area() const = 0;
};

//純粋仮想デストラクタ。
inline TwoDimensional::~TwoDimensional() {}

#endif
