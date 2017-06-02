/*演習9-4
 * 二つの展示を持つ2次元配列クラステンプレートを作成。
 * 作成日：2017年6月2日
 * 作成者：浅田　知嗣
 */

#include <iostream>
#include "e_09_04_Matrix.h"

using namespace std;

int main()
{
	//int型の行列を生成する。
	Matrix<int> x(5, 6);

	//double型の行列を生成する。
	Matrix<double> y(7, 8);

	//行列の中身を表示して確認する。
	cout	<<"------行列x-------\n";
	x.display_matrix();

	cout	<<"----------行列y-----------\n";
	y.display_matrix();

	//行列の中身に値を代入していく。
	for(int i = 1; i <= x.height(); i++) {
		for(int j = 1; j <= x.width(); j++) {
			x[i][j] = i * j;
		}
	}

	for(int i = 1; i <= y.height(); i++) {
		for(int j = 1; j <= y.width(); j++) {
			y[i][j] = i * j;
		}
	}

	//行列の中身を表示して確認する。
	cout	<<"------行列x-------\n";
	x.display_matrix();

	cout	<<"----------行列y-----------\n";
	y.display_matrix();

	return 0;
}
