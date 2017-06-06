/*演習10-6
 * 算術演算のファンクタとtransformアルゴリズムを組み合わせたプログラム。
 * 作成日：2017年6月6日
 * 作成者：浅田　知嗣
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

//ベクトルの全要素を表示するテンプレート関数の宣言。
template<class InputIterator>
void print(InputIterator first, InputIterator last);

int main()
{
	//計算につかう配列を生成。
	vector<int> a;

	//値を格納。
	for(vector<int>::size_type  i = 10; i < 20; i++) {
		a.push_back(i);
	}

	//計算に使う配列を生成。
	vector<int> b;

	//値を格納。
	for(vector<int>::size_type i = 20; i > 10; i--) {
		b.push_back(i);
	}

	//計算結果を格納する配列。
	vector<int> c(10);

	vector<int> d(10);

	vector<int> e(10);

	vector<int> f(10);

	vector<int> g(10);

	//配列aをコピー
	vector<int> h(a);

	//配列 a + bを配列cに格納
	transform(a.begin(), a.end(), b.begin(), c.begin(), plus<int>());

	//配列 a - bを配列dに格納。
	transform(a.begin(), a.end(), b.begin(), d.begin(), minus<int>());

	//配列 a * b を配列eに格納。
	transform(a.begin(), a.end(), b.begin(), e.begin(), multiplies<int>());

	//配列 a / bを配列fに格納。
	transform(a.begin(), a.end(), b.begin(), f.begin(), divides<int>());

	//配列 a % bを配列gに格納。
	transform(a.begin(), a.end(), b.begin(), g.begin(), modulus<int>());

	//配列-aを配列hに格納。
	transform(a.begin(), a.end(), h.begin(), negate<int>());

	//配列の中身を表示して計算結果を確認。
	//配列a
	cout	<<"a = ";
	print(a.begin(), a.end());
	cout	<<'\n';

	//配列b
	cout	<<"b = ";
	print(b.begin(), b.end());
	cout	<<'\n';

	//配列a + b
	cout	<<"a + b = ";
	print(c.begin(), c.end());
	cout	<<'\n';

	//配列a - b
	cout	<<"a - b = ";
	print(d.begin(), d.end());
	cout	<<'\n';

	//配列a * b
	cout	<<"a * b = ";
	print(e.begin(), e.end());
	cout	<<'\n';

	//配列a / b
	cout	<<"a / b = ";
	print(f.begin(), f.end());
	cout	<<'\n';

	//配列a % b
	cout	<<"a % b = ";
	print(g.begin(), g.end());
	cout	<<'\n';

	//配列-a
	cout	<<"-a = ";
	print(h.begin(), h.end());
	cout	<<'\n';

	return  0;
}

//ベクトルの全要素を表示するテンプレート関数の定義。
template<class InputIterator>
void print(InputIterator first, InputIterator last)
{
	cout	<<'{';

	//ベクトルの全要素を表示。
	for(InputIterator i = first; i < last; i++) {
		cout	<<*i	<<" ";
	}

	cout	<<'}';
}
