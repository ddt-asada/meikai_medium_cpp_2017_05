/*演習11-2
 * 関数テンプレートでの文字列の走査を反復子を用いて実行できるように書き換えたプログラム。
 * 作成日：2017年6月6日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//文字列ベクトルを走査する関数テンプレートの宣言。
template<class InputIterator>
void put_string_vector(InputIterator first, InputIterator last);

int main()
{
	//空の文字列を生成。
	vector<string> s1(3);

	//文字列を生成。
	vector<string> s2;

	//要素をプッシュしていく。
	s2.push_back("ABC");
	s2.push_back("123");
	s2.push_back("XYZ");

	//反復子をもちいて文字列を走査し、表示。
	cout	<<"s1 = ";
	put_string_vector(s1.begin(), s1.end());
	cout	<<'\n';

	//反復子を用いて文字列を走査し、表示。
	cout	<<"s2 = ";
	put_string_vector(s2.begin(), s2.end());
	cout	<<'\n';

	return 0;
}

//文字列ベクトルを走査する関数テンプレートの定義。
template<class InputIterator>
void put_string_vector(InputIterator first, InputIterator last)
{
	cout	<<"{ ";

	//文字列を表示する。
	for(InputIterator i = first; i < last; i++) {
		cout	<<'"';
		cout	<<*i;
		cout	<<"\" ";
	}
	cout	<<"} ";
}
