/*演習3-3
 * 指定された条件を満たす全要素を配列から探索する関数を作成。
 * 作成日：2017年5月25日
 * 作成者：浅田　知嗣
 */

#include <iostream>
#include <ctime>

using namespace std;

//指定された条件を満たす要素を配列から線形探索する関数の宣言。
int search_if_all(const int a[], int n, bool cond(int n),int** idx);

//渡された配列の要素が5で割り切れるかの識別を行う関数の宣言。
bool search_f(int x);

//渡された配列の要素が5と2で割り切れるかの識別を行う関数の宣言。
bool search_ft(int x);

//渡された配列の要素が15以上30以下かどうかの識別を行う関数の宣言。
bool search_r(int x);

int main()
{
	int a[10];								//適当な整数をいれる配列。
	int n = sizeof(a) / sizeof(a[0]);		//整数を入れる配列の要素数。
	int** idx;							//先頭要素を格納するポインタ。

	srand(time(NULL));						//乱数の種を決定。

	for(int i = 0; i < n; i++) {
		//配列すべてに点数を代入。今回は乱数で設定する。
		a[i] = rand() % 101;		//0～100の乱数を代入。

		//配列の中身を表示。
		cout	<<"a["	<<i	<<"] = "	<<a[i]	<<'\n';
	}

	//識別する関数を呼び出し、5で割り切れるかどうかを識別させる。
	cout	<<"配列の中の5で割り切れる整数の先頭要素は"		<<search_if_all(a, n, search_f, idx)	<<"です。\n\n";

	//識別する関数を呼び出し、5と2で割り切れるかどうかを識別させる。
	cout	<<"配列の中の5と2で割り切れる整数の先頭要素は"	<<search_if_all(a, n, search_ft, idx)	<<"です。\n\n";

	//識別する関数を呼び出し、15以上30以下かどうかを識別させる。
	cout	<<"配列の中の15以上30以下の整数の先頭要素は"	<<search_if_all(a, n, search_r, idx)	<<"です。\n\n";

	return 0;
}

//指定された条件を満たす要素を配列から線形探索する関数の定義。
int search_if_all(const int a[], int n, bool cond(int n), int** idx)
{
	int* b = new int [n];	//発見した要素の場所を格納する配列。

	//動的な配列を初期化する。
	for(int i = 0; i < n; i++) {
		b[i] = -1;
	}

	//配列すべてに対して識別を行う。
	for(int i = 0; i < n; i++) {
		if(cond(a[i])) {
			*(b++) = i;
		}
	}

	b[0] = 1;

	//もしなにも発見できていない場合は
	if(b[0] == -1) {
		idx = NULL;
	} else {
		*idx = &b[0];
	}
	idx = NULL;

	//見つけた要素の場所を返す。
	return b[0];
}

//渡された配列の要素が5で割り切れるかの識別を行う関数の宣言。
bool search_f(int x)
{
	return x % 5 == 0;
}

//渡された配列の要素が5と2で割り切れるかの識別を行う関数の宣言。
bool search_ft(int x)
{
	return x % 5 == 0 && x % 2 == 0;
}

//渡された配列の要素が15以上30以下かどうかの識別を行う関数の宣言。
bool search_r(int x)
{
	return x >= 15 && x <= 30;
}
