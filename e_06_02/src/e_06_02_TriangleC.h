/*演習6-2
 * 図形クラス群に直角二等辺三角形を表示するクラス群を追加する。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#ifndef ___Class_TriangleC
#define ___Class_TriangleC

#include <string>
#include <sstream>
#include <iostream>
#include "e_06_02_Shape.h"
#include "e_06_02_Triangle.h"

//右下直角の二等辺三角形クラス
class TriangleC : public Triangle {
public:
	//コンストラクタ
	TriangleC(int len) : Triangle(len) { }

	//複製。
	virtual TriangleC* clone() const
	{
		return new TriangleC(length);
	}

	//右下直角三角形の描画。
	void draw() const
	{
		//右下直角三角形を出力していく。
		//縦方向の移動。
		for(int i = length; i > 0; i--) {
			//間隔の確保。
			for(int k = i - 1; k > 0; k--) {
				std::cout	<<' ';
			}			//横方向の描画。
			for(int j = 0; j <= length - i; j++) {

				std::cout	<<'*';
			}
			std::cout	<<'\n';
		}
	}

	//文字列表現。
	std::string to_string() const
	{
		std::ostringstream os;
		os	<<"TriangleA(height:"	<<length	<<")";
		return os.str();
	}
	//デバッグ用情報表示
	void debug() const {
		Shape::debug();
		std::cout << "length：" << length << '\n';
	}
};

#endif
