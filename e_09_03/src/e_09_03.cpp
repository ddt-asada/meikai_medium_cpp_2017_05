/*演習9-3
 * Twin<Date>を要素として持つArray<>クラステンプレートオブジェクトを生成。
 * 作成日：2017年6月1日
 * 作成者：浅田　知嗣
 */

#include <new>
#include <iostream>
#include "e_09_03_Twin.h"
#include "e_09_03_Array.h"
#include "e_09_03_Date.h"

using namespace std;

int main()
{
	//配列クラステンプレートからDate型のオブジェクトを持つ配列を生成。
	Array<Twin<Date> > x(3, (Twin<Date>(Date(1993, 9, 11), Date())));

	for(int i = 0; i < x.size(); i++) {
		cout	<<"x["	<<i	<<"] = "	<<x[i]	<<'\n';
	}

	return 0;
}
