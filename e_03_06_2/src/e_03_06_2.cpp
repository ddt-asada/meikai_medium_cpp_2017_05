/*演習3-6-2
 * bsearch関数を用いて文字列の配列からの探索を行うプログラム。
 * 作成日：2017年5月25日
 * 作成者：浅田　知嗣
 */

//文字列の2次元配列を使用して走査を行う。

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

//文字列の比較関数の宣言。
int char_cmp(const char* a, const char*b);

int main()
{
	char arr[][5] = {"abc", "def", "ghi", "jkl", "lmn"};

	char *result;

	char key[] = "dwf";

	/*第1引数に走査する文字列の配列の先頭要素のアドレスを渡す。
	 * 第2引数に操作する対象の文字列の2次元配列の行の先頭要素のアドレスを渡す。
	 * 第3引数に配列の要素数を渡す。
	 * 第4引数char型のバイト数を渡す。
	 * 第5引数に文字列の比較関数を渡す。
	 */
	result = reinterpret_cast<char*>(bsearch(&key[0], &arr[0], sizeof(arr)/sizeof(arr[0]), sizeof(char), reinterpret_cast<int (*)(const void*, const void*)>(char_cmp)));

	if(result) {
		cout	<<result	<<"が一致します。\n";
	} else {
		cout	<<"見つかりませんでした。\n";
	}

	return 0;
}

//文字列の比較関数の定義。
int char_cmp(const char* a, const char* b)
{
	return strcmp(a, b);
}
