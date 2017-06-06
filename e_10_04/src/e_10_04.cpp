/*演習10-4
 * ベクトル表示にdouble型とstring型を追加。
 * 作成日：2017年6月6日
 * 作成者：浅田　知嗣
 */

#include <vector>
#include <iostream>
#include <string>

using namespace std;

//ベクトルの全要素を表示するテンプレート関数の宣言。
template<class InputIterator>
void print(InputIterator first, InputIterator last);

int main()
{
	//ベクトルにコピーするint型の配列を生成。
	int a[] = {1, 2, 3, 4, 5};
	//ベクトルクラスにコピー
	vector<int> x(a, a + 5);

	//ベクトルにコピーするdouble型の配列を生成。
	double b[] = {1.1, 2.2, 3.3, 4.4};
	//ベクトルクラスにコピー
	vector<double> y(b, b + 4);

	//ベクトルにコピーするstring型の配列を生成。
	string c[] = {"abcd", "VWXYZ", "12345"};
	//ベクトルクラスにコピー
	vector<string> z(c, c + 3);

	//ポインタをわたして配列を表示。
	cout	<<"int型：a = ";
	print(a, a + 5);
	cout	<<'\n';

	//反復子をわたして配列を表示。
	cout	<<"int型：x = ";
	print(x.begin(), x.end());
	cout	<<'\n';

	//ポインタをわたして配列を表示。
	cout	<<"double型：b = ";
	print(b, b + 4);
	cout	<<'\n';

	//反復子をわたして配列を表示。
	cout	<<"double型：y = ";
	print(y.begin(), y.end());
	cout	<<'\n';

	//ポインタをわたして配列を表示。
	cout	<<"string型：c = ";
	print(c, c + 3);
	cout	<<'\n';

	//反復子をわたして配列を表示。
	cout	<<"string型：z = ";
	print(z.begin(), z.end());
	cout	<<'\n';
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
