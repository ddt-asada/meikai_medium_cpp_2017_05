/*演習3-11
 * quicksort関数を用いて、配列を昇順にソートするプログラム。
 * 作成日：2017年5月25日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

//xとyの指すnバイトの領域を交換する関数。
namespace
{
	void memswap(void* x,void* y, size_t n) {
		unsigned char* a = reinterpret_cast<unsigned char*>(x);
		unsigned char* b = reinterpret_cast<unsigned char*>(y);

		for( ; n--; a++, b++) {
			unsigned char c= *a;
			*a = *b;
			*b = c;
		}
	}
}

//汎用クイックソートの宣言。
void quicksort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));

//文字列の比較関数の宣言。
int int_cmp(const int* a, const int* b);

int main()
{
	//ソートする配列の宣言。
	const int n = 100;		//配列の要素数。

	int* x = new int[n];	//配列を生成。

	//配列の各要素に値を代入する。
	for(int i = 0; i < n; i++) {
		x[i] = i;
		cout	<<"x["	<<i	<<"] = "	<<x[i]	<<'\n';
	}

	quicksort(x, n, sizeof(int),reinterpret_cast<int (*)(const void*, const void*)>(int_cmp));

	//ソートし終わった文字列を表示。
	cout	<<"\n配列の並び替えが完了しました。\n結果は以下の通りです。\n";

	for(int i = 0; i < n; i++) {
		cout	<<"x["	<<i	<<"] = "	<<x[i]	<<'\n';
	}

	return 0;
}

//汎用クイックソートの定義。
void quicksort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*))
{
	if(nmemb > 0) {
		const char* v = reinterpret_cast<const char*>(base);	//先頭要素へのポインタ。
		size_t pl = 0;											//左カーソル。
		size_t pr = nmemb - 1;									//右カーソル。
		size_t pv = nmemb;										//枢軸。
		size_t pt = (pl + pr) / 2;								//枢軸の更新値。

		do {
			const char* x;										//枢軸へのポインタ。

			if(pv != pt) {
				x = &v[(pv = pt) * size];
			}

			while (compar(reinterpret_cast<const void*>(&v[pl * size]), x) < 0) {
				pl++;
			}

			while (compar(reinterpret_cast<const void*>(&v[pr * size]), x) > 0) {
				pr--;
			}

			if(pl <= pr) {
				pt = (pl == pv) ? pr : (pr== pv) ? pl : pv;
				memswap(const_cast<void*>(reinterpret_cast<const void*>(&v[pl * size])), const_cast<void*>(reinterpret_cast<const void*>(&v[pr * size])), size);

				pl ++ ;

				if(pr == 0) {
					goto QuickRight;
				}

				pr--;
				}
			} while (pl <= pr);

		if(0 < pr) {
			quicksort(const_cast<void*>(reinterpret_cast<const void*>(&v[0])), pr + 1, size, compar);
		}

		QuickRight:
		if(pl < nmemb - 1) {
			quicksort(const_cast<void*>(reinterpret_cast<const void*>(&v[pl * size])), nmemb - pl, size,compar);
		}
	}
}

//文字列の比較関数の定義。
int int_cmp(const int* a, const int* b)
{
	int judge = 0;

	//大小を比較しそれに応じた値を返す。
		if(*a < *b) {
			judge = 1;
		} else if (*a > *b) {
			judge = -1;
		}

		//判定を返す。
		return judge;
}
