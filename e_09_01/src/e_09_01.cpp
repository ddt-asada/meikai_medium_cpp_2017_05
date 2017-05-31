/*演習9-1
 * char型に特殊化した挿入子を作成する。
 * 作成日：2017年5月31日
 * 作成者：浅田　知嗣
 */

#include <string>
#include <iostream>
#include "e_09_01_Twin.h"

using namespace std;

//比較演算子<の定義。
template <class Type>bool operator<(const Twin<Type>& a, const Twin<Type>& b)
{
	if(a.first() < b.first()) {
		return true;

	} else if (!(b.first() < a.first()) && (a.second() < b.second())) {
		return true;
	}

	return false;
}

int main()
{
	//int型のオブジェクトを生成。
	Twin<Twin<int> > t1(Twin<int>(36, 57), Twin<int>(23, 48));
	cout	<<"t1 = "	<<t1	<<'\n';

	//string型のオブジェクトを生成。
	Twin<Twin<string> > t2(Twin<string>("ABC", "DEF"), Twin<string>("STU", "XYZ"));
	cout	<<"t2 = "	<<t2	<<'\n';

	//char型のオブジェクトを生成。
	Twin<Twin<char> > t3(Twin<char>('A', 'B'), Twin<char>('C', 'D'));
	cout	<<"t3 = "	<<t3	<<'\n';

	//t3の値を変更する。
	cout	<<"t3の値を変更します。\n";
	cout	<<"新しい第1値の第1値：";
	cin		>>t3.first().first();

	cout	<<"新しい第1値の第2値：";
	cin		>>t3.first().second();

	cout	<<"新しい第2値の第1値：";
	cin		>>t3.second().first();

	cout	<<"新しい第2値の第2値：";
	cin		>>t3.second().second();

	//変更し終わったt3を表示。
	cout	<<t3;
}
