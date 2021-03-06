/*演習7-3
 * 図形クラス群に直角二等辺三角形を表示するクラス群を追加する。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#ifndef ___Class_Triangle
#define ___Class_Triangle

#include <string>
#include <sstream>
#include <iostream>

#include "e_07_03_Shape.h"
#include "e_07_03_TwoDimensional.h"

//二等辺三角形クラス（抽象クラス）
class RectEquilTriangle : public Shape, public TwoDimensional
{
protected:
	int length;			// 長さ

public:
	//コンストラクタ
	RectEquilTriangle(int len) : length(len) { }

	//面積を求める。
	double get_area() const
	{
		return length * length / 2.0;
	}
};

//左下直角の二等辺三角形クラス
class RectEquilTriangleLB : public RectEquilTriangle {
public:
	//コンストラクタ
	RectEquilTriangleLB(int len) : RectEquilTriangle(len) { }

	//複製。
	RectEquilTriangleLB* clone() const
	{
		return new RectEquilTriangleLB(length);
	}

	//左下直角の三角形の描画。
	void draw() const
	{
		//左下直角三角形を出力していく。
		//縦方向の移動。
		for(int i = 1; i <= length; i++) {
			//横方向の描画。
			for(int j = 1; j <= i; j++) {

				std::cout	<<'*';
			}
			std::cout	<<'\n';
		}
	}

	//文字列表現。
	std::string to_string() const
	{
		std::ostringstream os;
		os	<<"RectEquilTriangleLB(length:"	<<length	<<")";
		return os.str();
	}
	//デバッグ用情報表示
	void debug() const {
		Shape::debug();
		std::cout	<< "クラス：RectEquilTriangleLB\n";
		std::cout	<<"アドレス"	<<this		<<'\n';
		std::cout	<<"length："	<<length	<<'\n';
	}
};

//右上直角の二等辺三角形クラス
class RectEquilTriangleRU : public RectEquilTriangle {
public:
	//コンストラクタ
	RectEquilTriangleRU(int len) : RectEquilTriangle(len) { }

	//複製。
	RectEquilTriangleRU* clone() const
	{
		return new RectEquilTriangleRU(length);
	}

	//右上直角三角形の描画。
	void draw() const
	{
		//右上直角三角形を出力していく。
		//縦方向の移動。
		for(int i = length; i > 0; i--) {

			//間隔の確保。
			for(int k = 0; k < length - i; k++) {
				std::cout	<<' ';
			}
			//横方向の描画。
			for(int j = i; j > 0; j--) {

				std::cout	<<'*';
			}
			std::cout	<<'\n';
		}
	}

	//文字列表現。
	std::string to_string() const
	{
		std::ostringstream os;
		os	<<"RectEquilTriangleRU(height:"	<<length	<<")";
		return os.str();
	}
	//デバッグ用情報表示
	void debug() const {
		Shape::debug();
		std::cout	<< "クラス：RectEquilTriangleRU\n";
		std::cout	<<"アドレス"	<<this		<<'\n';
		std::cout	<<"length："	<<length	<<'\n';
	}
};

//左上直角の二等辺三角形クラス
class RectEquilTriangleLU : public RectEquilTriangle {
public:
	//コンストラクタ
	RectEquilTriangleLU(int len) : RectEquilTriangle(len) { }

	//複製。
	RectEquilTriangleLU* clone() const
	{
		return new RectEquilTriangleLU(length);
	}

	//左上直角三角形の描画。
	void draw() const
	{
		//左上直角三角形を出力していく。
		//縦方向の移動。
		for(int i = length; i > 0; i--) {
			//横方向の描画。
			for(int j = i; j > 0; j--) {
				std::cout	<<'*';
			}
			std::cout	<<'\n';
		}
	}

	//文字列表現。
	std::string to_string() const
	{
		std::ostringstream os;
		os	<<"RectEquilTriangleLU(height:"	<<length	<<")";
		return os.str();
	}
	//デバッグ用情報表示
	void debug() const {
		Shape::debug();
		std::cout	<< "クラス：RectEquilTriangleLU\n";
		std::cout	<<"アドレス"	<<this		<<'\n';
		std::cout	<<"length："	<<length	<<'\n';
	}
};

//右下直角の二等辺三角形クラス
class RectEquilTriangleRB : public RectEquilTriangle {
public:
	//コンストラクタ
	RectEquilTriangleRB(int len) : RectEquilTriangle(len) { }

	//複製。
	RectEquilTriangleRB* clone() const
	{
		return new RectEquilTriangleRB(length);
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
		os	<<"RectEquilTriangleRB(height:"	<<length	<<")";
		return os.str();
	}
//デバッグ用情報表示
	void debug() const {
		Shape::debug();
		std::cout	<< "クラス：RectEquilTriangleRB\n";
		std::cout	<<"アドレス"	<<this		<<'\n';
		std::cout	<<"length："	<<length	<<'\n';
	}
};

#endif
