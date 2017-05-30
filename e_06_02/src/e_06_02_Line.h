/*演習6-1
 * 図形クラス群に直角二等辺三角形を表示するクラス群を追加する。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_Line
#define ___Class_Line

#include <string>
#include <sstream>
#include <iostream>

#include "e_06_02_Shape.h"

//直線クラス（抽象クラス）
class Line : public Shape {
protected:
	int length;			// 長さ

public:
	//コンストラクタ
	Line(int len) : length(len) { }

	//長さ（length）のゲッタ
	int get_length() const { return length; }

	//長さ（length）のセッタ
	void set_length(int len) { length = len; }

	//デバッグ用情報表示
	void debug() const {
		Shape::debug();
		std::cout << "length：" << length << '\n';
	}
};

#endif
