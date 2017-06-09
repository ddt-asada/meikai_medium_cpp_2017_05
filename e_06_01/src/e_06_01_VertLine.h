/*演習6-1
 * 図形クラス群に直角二等辺三角形を表示するクラス群を追加する。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#ifndef ___Class_VertLine
#define ___Class_VertLine

#include <string>
#include <sstream>
#include <iostream>
#include "e_06_01_Shape.h"
#include "e_06_01_Line.h"

//垂直直線クラス
class VertLine : public Line {
public:
	//コンストラクタ
	VertLine(int len) : Line(len) { }

	//複製
	virtual VertLine* clone() const {
		return new VertLine(length);
	}

	//描画
	void draw() const {
		for (int i = 1; i <= length; i++)
			std::cout << "|\n";
	}

	//文字列表現
	std::string to_string() const {
		std::ostringstream os;
		os << "VertLine(length:" << length << ")";
		return os.str();
	}
};

#endif
