/*演習7-4
 * 図形クラス群に3次元クラスを追加する。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 */

#include <iostream>
#include "e_07_04_Line.h"
#include "e_07_04_Point.h"
#include "e_07_04_Rectangle.h"
#include "e_07_04_Shape.h"
#include "e_07_04_Triangle.h"

using namespace std;

int main()
{
	//作成した図形クラス群への配列を生成。
	Shape* a[] = {
			new Point,						//点クラス。
			new HorzLine(6),				//水平直線クラス。
			new VertLine(9),				//垂直直線クラス。
			new Rectangle(7, 3, 6),			//長方形クラス。
			new RectEquilTriangleLB(5, 3),		//左下直角二等辺三角形クラス。
			new RectEquilTriangleRU(4, 4),		//右上直角二等辺三角形クラス。
			new RectEquilTriangleLU(3, 5),		//左上直角二等辺三角形クラス。
			new RectEquilTriangleRB(2, 6),		//右下直角二等辺三角形クラス。
	};

	//警告でないようにiをunsigned型にて宣言。
	for(unsigned i = 0; i < sizeof(a) / sizeof( a[0]); i++) {
		//図形に関する情報を表示。
		a[i] -> print();

		//もし2次元図形であれば
		if(ThreeDimensional* t = dynamic_cast<ThreeDimensional*>(a[i])){
			cout	<<"面積は"	<<t -> get_area()	<<"です。\n";
			cout	<<"体積は"	<<t -> get_volume()	<<"です。\n";
		}
		a[i] -> debug();
		cout	<<'\n';
	}

	//警告でないようにiをunsigned型にて宣言。
	for(unsigned i = 0; i < sizeof(a) / sizeof( a[0]); i++) {
		delete a[i];
	}
}
