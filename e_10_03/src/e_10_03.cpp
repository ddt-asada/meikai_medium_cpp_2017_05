/*演習10-3
 * 日付クラスDateとTwinの2次元配列を作成するプログラム。
 * 作成日：2017年6月6日
 * 作成者：浅田　知嗣
 */

#include <vector>
#include <iostream>
#include "e_10_03_Date.h"
#include "e_10_03_Twin.h"

using namespace std;

//行列の全要素を表示するテンプレート関数の宣言。
template <class T, class Allocator>
void print_matrix(const vector<T, Allocator>& v);

/*
//行列の列を追加するテンプレート関数の宣言。
template <class T, class Allocator>
void pushback_matrix(const vector<T, Allocator>& v);
*/

int main()
{
	int row;		//生成する行列の行。
	int column;		//生成する行列の列。

	//生成したい行数を入力する。
	cout	<<"行数：";
	cin		>>row;

	//生成したい列数を入力する。
	cout	<<"列数：";
	cin		>>column;

	//Date型の行列を作成。
	vector<vector<Date> > x(row, vector<Date>(column));

	//Twin型の行列を作成。
	vector<vector<Twin<int>> > y(row, vector<Twin<int>>(column));

	//Date型の行列の全要素を表示。
	cout	<<"行列Date\n";
	print_matrix(x);

	//Twin型の行列の全要素を表示。
	cout	<<"行列Twin\n";
	print_matrix(y);

	//凹凸（行ごとに列数の異なる行列）を生成。
	//行列の行数を入力。
	cout	<<"行数：";
	cin		>>row;

	vector<vector<Date> > z;

	//Date型凹凸行列の生成。
	for(int i = 0; i < row; i++) {
		//行に追加したい列数を入力。
		cout	<<i	<<"行目の列数：";
		cin		>>column;

		//行列の下に列数の分の配列を追加していく。
		z.push_back(vector<Date>(column));
	}

	//凹凸（行ごとに列数の異なる行列）を生成。
	//行列の行数を入力。
	cout	<<"行数：";
	cin		>>row;

	vector<vector<Twin<int>> > v;

	//Twin型の凹凸行列の生成。
	for(int i = 0; i < row; i++) {
		//行に追加したい列数を入力。
		cout	<<i	<<"行目の列数：";
		cin		>>column;

		//行列の下に列数の分の配列を追加していく。
		v.push_back(vector<Twin<int>>(column));
	}
	//Date型の行列の全要素を表示。
	cout	<<"行列Date\n";
	print_matrix(z);

	//Twin型の行列の全要素を表示。
	cout	<<"行列Twin\n";
	print_matrix(v);

	return 0;
}

//行列の全要素を表示するテンプレート関数の定義。
template <class T, class Allocator>
void print_matrix(const vector<T, Allocator>& v)
{
	int row = v.size();			//行列の行数を取得。
	int column;	//行列の列数を取得するための型。

	//受け取った行列の全要素を表示する。
	for(int i = 0; i < row; i++) {
		column = v[i].size();	//その列の行数をしゅとく。

		for(int j = 0; j < column; j++) {
			cout	<<'['	<<i	<<"]["	<<j	<<"] = "	<<v[i][j]	<<'\n';
		}
	}
}
/*
//行列の列を追加するテンプレート関数の定義。
template <class T, class Allocator>
void pushback_matrix(const vector<T, Allocator>& v)
{
	int row = v.size();			//行列の行数を取得。
	int column;					//追加したい列数の型。

	for(int i = 0; i < row; i++) {
		//行に追加したい列数を入力。
		cout	<<i	<<"行目の列数：";
		cin		>>column;

		//行列の下に列数の分の配列を追加していく。
		v.push_back(vector<T, Allocator>(column));
	}
}*/
