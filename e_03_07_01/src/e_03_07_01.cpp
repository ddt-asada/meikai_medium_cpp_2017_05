/*演習3-7-1
 * qsort関数を用いて、配列を昇順にソートするプログラム。プログラム。
 * 作成日：2017年5月25日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

//文字列の比較関数の宣言。
int char_cmp(const char** a, const char** b);

int main()
{
	//ソートするポインタによる文字列の宣言。
	const char *arr[] = {"xyz", "adw", "afw", "afw", "awfa", "hrg","bfsr", "bmnn", "gesb", "gs", "gskdnersjkngnzbzd", "LISP", "C", "Ada", "Pascal","abc", "def", "ghi", "jkl", "lmn", "opq", "stu", "xyz", "adw", "afw", "afw", "awfa", "hrg","bfsr", "bmnn", "gesb", "gs", "gskdnersjkngnzbzd"};

	const int n = sizeof(arr) / sizeof(arr[0]);		//要素数。

	//ソートする前の文字列の表示。
	cout	<<"以下の文字列を昇順にソートします。\n";

	for(int i = 0; i < n; i++) {
		cout	<<"arr["	<<i	<<"] = "	<<arr[i]	<<'\n';
	}

	qsort(&arr[0], n, sizeof(char *),reinterpret_cast<int (*)(const void*, const void*)>(char_cmp));

	//ソートし終わった文字列を表示。
	cout	<<"\n文字列の並び替えが完了しました。\n結果は以下の通りです。\n";

	for(int i = 0; i < n; i++) {
		cout	<<"arr["	<<i	<<"] = "	<<arr[i]	<<'\n';
	}

	return 0;
}

//文字列の比較関数の定義。
int char_cmp(const char** a, const char** b)
{
	return strcmp(*a, *b);
}
