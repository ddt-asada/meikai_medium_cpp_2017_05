/*演習3-9
 * binsearch関数を用いて文字列の配列からの探索を行うプログラム。
 * 作成日：2017年5月25日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

//線形探索を行う関数の宣言。
void* binsearch(const void* key, const void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));

//数値の比較関数の宣言。
int int_cmp(const int* a, const int* b);

int main()
{
	const int n = 100;		//配列の要素数。

	int* x = new int[n];	//配列を生成。

	int no = 49;				//探索する値。

	int* p;					//探索結果を指すポインタを生成。

	//配列の各要素に値を代入する。
	//代入する値は3個連続して並べる。
	for(int i = 0; i < n; i+= 3) {
		x[i] = i;
		cout	<<"x ["	<<i	<<"] = "	<<x[i]	<<'\n';
		x[i + 1] = i;
		cout	<<"x ["	<<i + 1	<<"] = "	<<x[i + 1]	<<'\n';
		x[i + 2] = i;
		cout	<<"x ["	<<i + 2	<<"] = "	<<x[i + 2]	<<'\n';
	}

	//数値を探索する関数に値を渡す。
	p = reinterpret_cast<int*>(binsearch(&no, x, n, sizeof(int), reinterpret_cast<int (*)(const void*, const void*)>(int_cmp)));

	if(p != NULL) {
		cout	<<"x["	<<(p - x)	<<"]が一致します。\n";
	} else {
		cout	<<"見つかりませんでした。\n";
	}

	return 0;
}

//線形探索を行う関数の定義。
void* binsearch(const void* key, const void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*))
{
	void* place = NULL; //返すポインタ。

	if(nmemb > 0){
		const char* x =reinterpret_cast<const char*>(base);
		size_t pl = 0;			//探索範囲先頭の添字。
		size_t pr = nmemb - 1;	//探索範囲末尾の添字。
		size_t pc;				//探索範囲中央の添字。

		while (true) {
			int comp = compar(key, reinterpret_cast<const void*>(&x[(pc = (pl + pr) / 2) * size]));

			//探索が成功した時。
			if(comp == 0) {
				place = const_cast<void*>(reinterpret_cast<const void*>(&x[pc * size]));
			//探索範囲がなくなったとき。
			} else if (pl == pr) {
				break;
			//探索範囲を後半に絞り込む。
			} else if (comp < 0) {
				pl = pc + 1;
			//探索範囲を前半に絞り込む。
			} else {
				pr = pc - 1;
			}
		}
	}

	return place;
}

//数値の比較関数の定義。
int int_cmp(const int* a, const int* b)
{
	int judge = 0;		//判定

	//大小を比較しそれに応じた値を返す。
	if(*a < *b) {
		judge = 1;
	} else if (*a > *b) {
		judge = -1;
	}

	//判定を返す。
	return judge;
}
