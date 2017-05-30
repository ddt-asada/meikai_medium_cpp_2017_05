/*演習7-4
 * 図形クラス群に3次元クラスを追加する。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_Rectangle
#define ___Class_Rectangle

#include <string>
#include <sstream>
#include <iostream>

#include "e_07_04_Shape.h"
#include "e_07_04_ThreeDimensional.h"

//長方形クラス
class Rectangle : public Shape, public ThreeDimensional
{
	int width;		// 幅
	int height;		// 高さ
	int depth;		//奥行

public:
	//コンストラクタ
	Rectangle(int w, int h, int d) : width(w), height(h), depth(d) { }

	//複製
	Rectangle* clone() const {
		return new Rectangle(width, height, depth);
	}

	//描画。平面でしか表せないのでここはそのまま。
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
		os << "Rectangle(width:" << width << ", height:" << height	<<", depth:"	<<depth	<< ")";
		return os.str();
	}

	//デバッグ用情報表示
	void debug() const {
		Shape::debug();
		std::cout << "width ："	<<width		<<'\n';
		std::cout << "height："	<<height	<<'\n';
		std::cout << "depth："	<<depth		<<'\n';
	}

	//面積を求める関数。
	double get_area() const
	{
		return width * height;
	}

	//体積を求める関数。
	double get_volume() const
	{
		return get_area() * depth;
	}
};

#endif
