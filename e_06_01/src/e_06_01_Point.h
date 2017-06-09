/*演習6-1
 * 図形クラス群に直角二等辺三角形を表示するクラス群を追加する。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#ifndef ___Class_Point
#define ___Class_Point

#include <string>
#include <sstream>
#include <iostream>
#include "e_06_01_Shape.h"

//点クラス
class Point : public Shape {
public:
	//描画
	void draw() const {
		std::cout << "*\n";
	}

	//複製
	Point* clone() const {
		return new Point;
	}

	//文字列表現
	std::string to_string() const {
		return "Point";
	}

	//デバッグ用情報表示
	void debug() const {
		Shape::debug();
	}
};

#endif
