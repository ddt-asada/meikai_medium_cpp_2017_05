/*演習6-1
 * 図形クラス群に直角二等辺三角形を表示するクラス群を追加する。
 * 作成日：2017年5月30日
 * 作成者：浅田　知嗣
 */

#include <iostream>
#include "e_06_02_HorzLine.h"
#include "e_06_02_Line.h"
#include "e_06_02_Point.h"
#include "e_06_02_Rectangle.h"
#include "e_06_02_Shape.h"
#include "e_06_02_Triangle.h"
#include "e_06_02_TriangleA.h"
#include "e_06_02_TriangleB.h"
#include "e_06_02_TriangleC.h"
#include "e_06_02_VertLine.h"

using namespace std;

int main()
{
	int select = 10;			//どのオブジェクトを生成したいかを選択する変数。
	//作成した二等辺三角形オブジェクトへの配列を生成。
	Shape* a[] = {
			new Point(),
			new HorzLine(9),
			new VertLine(6),
			new Rectangle(7, 3),
			new TriangleA(6),
			new TriangleB(6),
			new TriangleC(6)
	};

	//無限ループ
	do {
		select = 10;	//選択を初期化。
		//どのオブジェクトを出力したいかを選択させる。
		do {
			cout	<<"どのオブジェクトを生成しますか(0…Point / 1…HorzLine / 2…VertLine / 3…Rectangle / 4…TriangleA / 5…TriangleB / 6…TriangleC / 7…終了)";
			cin		>>select;
		} while (select < 0 || select > 7);

		//終了が選択されたとき以外。
		if(select != 7) {
			//選択に応じたオブジェクトを表示する。
			a[select] -> print();
			a[select] -> debug();
			cout	<<'\n';
		}
	} while(select != 7);

	//警告でないようにiをunsigned型にて宣言。
	for(unsigned i = 0; i < sizeof(a) / sizeof( a[0]); i++) {
		delete a[i];
	}
}
