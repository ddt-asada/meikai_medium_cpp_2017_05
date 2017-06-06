/*演習11-2
 * 関数テンプレートでの文字列の走査を反復子を用いて実行できるように書き換えたプログラム。
 * 作成日：2017年6月6日
 * 作成者：浅田　知嗣
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//文字列ベクトルを走査する関数テンプレートの宣言。
template<typename Allocator>
void put_string_vector(const vector<string, Allocator>& v);

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
	put_string_vector(s1);
	cout	<<'\n';

	//反復子を用いて文字列を走査し、表示。
	cout	<<"s2 = ";
	put_string_vector(s2);
	cout	<<'\n';

	return 0;
}

//文字列ベクトルを走査する関数テンプレートの定義。
template<typename Allocator>
void put_string_vector(const vector<string, Allocator>& v)
{
	cout	<<"{ ";

	//文字列を表示する。
	for(vector<string>::const_iterator i = v.begin(); i < v.end(); i++) {
		cout	<<'"';
		cout	<<*i;
		cout	<<"\" ";
	}
	cout	<<"} ";
}
