/*演習7-3
 * 図形クラス群に直角二等辺三角形を表示するクラス群を追加する。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <iostream>
#include "e_07_03_Line.h"
#include "e_07_03_Point.h"
#include "e_07_03_Rectangle.h"
#include "e_07_03_Shape.h"
#include "e_07_03_Triangle.h"

using namespace std;

int main()
{
	//作成した図形クラス群への配列を生成。
	Shape* a[] = {
			new Point,						//点クラス。
			new HorzLine(6),				//水平直線クラス。
			new VertLine(9),				//垂直直線クラス。
			new Rectangle(7, 3),			//長方形クラス。
			new RectEquilTriangleLB(5),		//左下直角二等辺三角形クラス。
			new RectEquilTriangleRU(4),		//右上直角二等辺三角形クラス。
			new RectEquilTriangleLU(3),		//左上直角二等辺三角形クラス。
			new RectEquilTriangleRB(2),		//右下直角二等辺三角形クラス。
	};

	const int n = sizeof(a) / sizeof(a[0]);		//クラスの配列の要素数。

	//警告でないようにiをunsigned型にて宣言。
	for(int i = 0; i < n; i++) {
		//図形に関する情報を表示。
		a[i] -> print();

		//もし2次元図形であれば
		if(TwoDimensional* t = dynamic_cast<TwoDimensional*>(a[i])){
			cout	<<"面積は"	<<t->get_area()	<<"です。\n";
		}
		a[i] -> debug();
		cout	<<'\n';
	}

	//警告でないようにiをunsigned型にて宣言。
	for(int i = 0; i < n; i++) {
		delete a[i];
	}
}
