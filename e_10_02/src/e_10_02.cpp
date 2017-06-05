/*演習10-2
 * ベクトル関数テンプレートにスペースを追加。
 * 作成日：2017年6月6日
 * 作成者：浅田　知嗣
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//ベクトルの全要素を表示するテンプレート関数の宣言。
template <class T, class Allocator>
void print_vector(const vector<T, Allocator>& v);

int main()
{
	//テンプレート関数の動作を確認するためのint型の配列生成。
	int a[] = {1, 2, 3, 4, 5};
	//ベクトルクラスに値をコピー。
	vector<int> x(a, a + sizeof(a) / sizeof(a[0]));

	//テンプレート関数の動作を確認するためのdouble型の配列生成。
	double b[] = {3.5, 7.3, 2.2, 9.9};
	//ベクトルクラスに値をコピー。
	vector<double> y(b, b + sizeof(b) / sizeof(b[0]));

	//テンプレート関数の動作を確認するためのstring型の配列生成。
	string c[] = {"abc", "WXYZ", "123456"};
	//ベクトルクラスに値をコピー。
	vector<string> z(c, c + sizeof(c) / sizeof(c[0]));

	//配列の全要素を表示するテンプレート関数に値を渡して表示できるかを確認する。
	//int型の配列の表示の確認。
	cout	<<"x = ";
	print_vector(x);
	cout	<<'\n';

	//double型の配列の表示の確認。
	cout	<<"y = ";
	print_vector(y);
	cout	<<'\n';

	//string型の配列の表示の確認。
	cout	<<"z = ";
	print_vector(z);
	cout	<<'\n';

	return 0;
}

//ベクトルの全要素を表示するテンプレート関数の定義。
template <class T, class Allocator>
void print_vector(const vector<T, Allocator>& v)
{
	vector<int>::size_type i;

	cout	<<'{';

	//受け取った配列の全要素を並べて表示する。
	for(i = 0; i != v.size(); i++) {

		if(i == v.size() - 1) {
			cout	<<v[i];
		} else {
			cout	<<v[i]	<<", ";
		}
	}

	cout	<<'}';
}
