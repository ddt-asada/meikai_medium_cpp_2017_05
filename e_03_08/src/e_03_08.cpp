/*演習3-8
 * seqsearch関数を用いて文字列の配列からの探索を行うプログラム。
 * 作成日：2017年5月25日
 * 作成者：浅田　知嗣
 */

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

//線形探索を行う関数の宣言。
void* seqsearch(const void* key, const void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));

//文字列の比較関数の宣言。
int char_cmp(const char* a, const char*b);

int main()
{
	const char *arr[] = {"abc", "def", "ghi", "jkl", "lmn", "opq", "stu", "xyz"};

	char **result;

	const char *key = "stu";

	result = reinterpret_cast<char**>(seqsearch(&key, arr, sizeof(arr)/sizeof(arr[0]), sizeof(char *), reinterpret_cast<int (*)(const void*, const void*)>(char_cmp)));

	if(result) {
		cout	<<*result	<<"が一致します。\n";
	} else {
		cout	<<"見つかりませんでした。\n";
	}

	return 0;
}

//線形探索を行う関数の定義。
void* seqsearch(const void* key, const void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*))
{
	const char* x =reinterpret_cast<const char*>(base);

	for(size_t i = 0;i < nmemb; i++) {
		if(!compar(key, reinterpret_cast<const void*>(&x[i* size]))) {
			return const_cast<void*>(reinterpret_cast<const void*>(&x[i *size]));
		}
	}
	return NULL;
}

//文字列の比較関数の定義。
int char_cmp(const char* a, const char* b)
{
	return strcmp(a, b);
}
