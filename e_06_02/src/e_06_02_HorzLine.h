/*演習6-1
 * 図形クラス群に直角二等辺三角形を表示するクラス群を追加する。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_HorzLine
#define ___Class_HorzLine

#include <string>
#include <sstream>
#include <iostream>
#include "e_06_02_Line.h"
#include "e_06_02_Shape.h"

//水平直線クラス
class HorzLine : public Line {
public:
	//コンストラクタ
	HorzLine(int len) : Line(len) { }

	//複製
	virtual HorzLine* clone() const {
		return new HorzLine(length);
	}

	//描画
	void draw() const {
		for (int i = 1; i <= length; i++)
			std::cout << '-';
		std::cout << '\n';
	}

	//文字列表現
	std::string to_string() const {
		std::ostringstream os;
		os << "HorzLine(length:" << length << ")";
		return os.str();
	}
};

#endif
