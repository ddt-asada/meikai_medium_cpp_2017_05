/*演習9-2
 * Date型のテンプレートクラスを作るプログラム。。
 * 作成日：2017年5月31日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <string>
#include <iostream>
#include "e_09_02_Twain.h"

using namespace std;

int main()
{
	//Date型のオブジェクトを生成。
	Twin<Date> t1(Date(100, 10, 2), Date(20, 2, 10));

	//Date型のTwinのTwinを生成。
	Twin<Twin<Date> > t2(Twin<Date>(Date(1993, 9, 11), Date()), Twin<Date>(Date(2000, 13, 50), Date(1232, 50, 20)));

	//中身を表示して確認する。
	cout	<<"t1 = "	<<t1	<<'\n';

	cout	<<"t2 = "	<<t2	<<'\n';
}
