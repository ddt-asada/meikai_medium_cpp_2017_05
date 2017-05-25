/*演習3-9
 * binsearch関数を用いて文字列の配列からの探索を行うプログラム。
 * 作成日：2017年5月25日
 * 作成者：浅田　知嗣
 */

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

//線形探索を行う関数の宣言。
void* binsearch(const void* key, const void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));

//文字列の比較関数の宣言。
int char_cmp(const char* a, const char*b);

int main()
{
	const char *arr[] = {"abc", "def", "ghi", "jkl", "lmn", "opq", "stu", "xyz"};

	char **result;

	const char *key = "stu";

	result = reinterpret_cast<char**>(binsearch(&key, arr, sizeof(arr)/sizeof(arr[0]), sizeof(char *), reinterpret_cast<int (*)(const void*, const void*)>(char_cmp)));

	if(result) {
		cout	<<*result	<<"が一致します。\n";
	} else {
		cout	<<"見つかりませんでした。\n";
	}

	return 0;
}

//線形探索を行う関数の定義。
void* binsearch(const void* key, const void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*))
{
	if(nmemb > 0){
		const char* x =reinterpret_cast<const char*>(base);
		size_t pl = 0;			//探索範囲先頭の添字。
		size_t pr = nmemb - 1;	//探索範囲末尾の添字。
		size_t pc;				//探索範囲中央の添字。

		while (true) {
			int comp = compar(key, reinterpret_cast<const void*>(&x[(pc = (pl + pr) / 2) * size]));

			//探索が成功した時。
			if(comp == 0) {
				return const_cast<void*>(reinterpret_cast<const void*>(&x[pc * size]));
			//探索範囲がなくなったとき。
			} else if (pl == pr) {
				break;
			//探索範囲を後半に絞り込む。
			} else if (comp > 0) {
				pl = pc + 1;
			//探索範囲を前半に絞り込む。
			} else {
				pr = pc - 1;
			}
		}
	}

	return NULL;
}

//文字列の比較関数の定義。
int char_cmp(const char* a, const char* b)
{
	return strcmp(a, b);
}
