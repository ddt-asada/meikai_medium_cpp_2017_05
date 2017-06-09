/*演習11-3
 * コマンドラインから与えられた文字列のソートやシャッフルなどを行うプログラム。
 * 作成日：2017年6月6日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//ポインタによる文字列の配列をvector<string>に変換する関数の宣言。
vector<string> strptary_to_vec(char** p, int n);

int main(int argc, char** argv)
{
	//コマンドライン引数をベクトルに変換する。
	vector<string> s1 = strptary_to_vec(argv, argc);

	//表示して中身を確認する。
	for(vector<string>::size_type i = 0; i < s1.size(); i++) {
		cout	<<"s1["	<<i	<<"] = "	<<s1[i]	<<'\n';
	}

	//文字列のシャッフルを行う。
	random_shuffle(s1.begin(), s1.end());

	cout	<<"シャッフル後\n";
	//表示して中身を確認する。
	for(vector<string>::size_type i = 0; i < s1.size(); i++) {
		cout	<<"s1["	<<i	<<"] = "	<<s1[i]	<<'\n';
	}

	//文字列のソートを行う。
	sort(s1.begin(), s1.end());

	cout	<<"ソート後\n";
	//表示して中身を確認する。
	for(vector<string>::size_type i = 0; i < s1.size(); i++) {
		cout	<<"s1["	<<i	<<"] = "	<<s1[i]	<<'\n';
	}

	return 0;
}

//ポインタによる文字列の配列をvector<string>に変換する関数の宣言。
vector<string> strptary_to_vec(char** p, int n)
{
	//ベクトルに変換した文字列を格納する型。
	vector<string> temp;

	//変換していく。
	for(int i = 0; i < n; i++) {
		temp.push_back(p[i]);
	}

	//変換し終わった文字列を返す。
	return temp;
}
