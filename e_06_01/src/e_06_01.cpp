/*演習6-1
 * 図形クラス群に直角二等辺三角形を表示するクラス群を追加する。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <iostream>
#include "e_06_01_Shape.h"
#include "e_06_01_Point.h"
#include "e_06_01_Line.h"
#include "e_06_01_HorzLine.h"
#include "e_06_01_VertLine.h"
#include "e_06_01_Rectangle.h"
#include "e_06_01_Triangle.h"
#include "e_06_01_TriangleA.h"
#include "e_06_01_TriangleB.h"
#include "e_06_01_TriangleC.h"
#include "e_06_01_TriangleD.h"

using namespace std;

int main()
{
	//作成した二等辺三角形オブジェクトへの配列を生成。
	Shape* a[] = {
			new TriangleA(6),
			new TriangleB(6),
			new TriangleC(6),
			new TriangleD(6)
	};

	//警告でないようにiをunsigned型にて宣言。
	for(unsigned i = 0; i < sizeof(a) / sizeof( a[0]); i++) {
		a[i] -> print();
		a[i] -> debug();
		cout	<<'\n';
	}

	//警告でないようにiをunsigned型にて宣言。
	for(unsigned i = 0; i < sizeof(a) / sizeof( a[0]); i++) {
		delete a[i];
	}
}
