/*演習7-4
 * 図形クラス群に3次元クラスを追加する。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_Point
#define ___Class_Point

#include <string>
#include <sstream>
#include <iostream>

#include "e_07_04_Shape.h"

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
