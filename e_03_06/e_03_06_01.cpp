/*演習3-6-1
 * bsearch関数を用いて文字列の配列からの探索を行うプログラム。
 * 作成日：2017年5月25日
 * 作成者：浅田　知嗣
 */

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

//文字列の比較関数の宣言。
int char_cmp(const char* a, const char*b);

int main()
{
	const char *arr[] = {"abc", "def", "ghi", "jkl", "lmn", "opq", "stu", "xyz"};

	char **result;

	const char *key = "abc";

	result = reinterpret_cast<char**>(bsearch(&key, arr, sizeof(arr)/sizeof(arr[0]), sizeof(char *), reinterpret_cast<int (*)(const void*, const void*)>(char_cmp)));

	if(result) {
		cout	<<*result	<<"が一致します。\n";
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
