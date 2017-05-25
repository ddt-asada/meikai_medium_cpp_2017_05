/*演習3-7-1
 * qsort関数を用いて、配列を昇順にソートするプログラム。プログラム。
 * 作成日：2017年5月25日
 * 作成者：浅田　知嗣
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
	const char *arr[] = {"LISP", "C", "Ada", "Pascal"};

	//ソートする前の文字列の表示。
	cout	<<"以下の文字列を昇順にソートします。\n";

	for(int i = 0; arr[i]; i++) {
		cout	<<"arr["	<<i	<<"] = "	<<arr[i]	<<'\n';
	}

	qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(char *),reinterpret_cast<int (*)(const void*, const void*)>(char_cmp));

	//ソートし終わった文字列を表示。
	cout	<<"\n文字列の並び替えが完了しました。\n結果は以下の通りです。\n";

	for(int i = 0; arr[i]; i++) {
		cout	<<"arr["	<<i	<<"] = "	<<arr[i]	<<'\n';
	}

	return 0;
}

//文字列の比較関数の定義。
int char_cmp(const char** a, const char** b)
{
	return strcmp(*a, *b);
}
