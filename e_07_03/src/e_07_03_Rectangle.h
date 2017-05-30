/*演習6-1
 * 図形クラス群に直角二等辺三角形を表示するクラス群を追加する。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_Rectangle
#define ___Class_Rectangle

#include <string>
#include <sstream>
#include <iostream>

#include "e_07_03_Shape.h"
#include "e_07_03_TwoDimensional.h"

//長方形クラス
class Rectangle : public Shape, public TwoDimensional
{
	int width;		// 幅
	int height;		// 高さ

public:
	//コンストラクタ
	Rectangle(int w, int h) : width(w), height(h) { }

	//複製
	Rectangle* clone() const {
		return new Rectangle(width, height);
	}

	//描画
	void draw() const {
		for (int i = 1; i <= height; i++) {
			for (int j = 1; j <= width; j++)
				std::cout << '*';
			std::cout << '\n';
		}
	}

	//文字列表現
	std::string to_string() const {
		std::ostringstream os;
		os << "Rectangle(width:" << width << ", height:" << height << ")";
		return os.str();
	}

	//デバッグ用情報表示
	void debug() const {
		Shape::debug();
		std::cout << "width ：" << width << '\n';
		std::cout << "height：" << height << '\n';
	}

	//面積を求める関数。
	double get_area() const
	{
		return width * height;
	}
};

#endif
