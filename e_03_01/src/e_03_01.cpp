/*演習3-1
 * 点数に応じて識別表示するプログラムの作成。
 * 作成日：2017年５月24日
 * 作成者：浅田　知嗣
 */

#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

//成績は良（70～79点か）どうかを判定する関数の宣言。
bool isB(int x);

//成績は優（80～100）または可（60～69）かを判定する関数の宣言。
bool isAorC(int x);

//成績は不可（59点以下）どうかを判定する関数の宣言。
bool isD(int x);

//関数の返却値が真である配列の要素を識別表示する関数の宣言。
void put_list(const int a[], int n, bool fit(int));

int main()
{
	int a[10];								//点数をいれる配列。
	int n = sizeof(a) / sizeof(a[0]);		//点数を入れる配列の要素数。

	srand(time(NULL));						//乱数の種を決定。

	for(int i = 0; i < n; i++) {
		//配列すべてに点数を代入。今回は乱数で設定する。
		a[i] = rand() % 101;		//0～100の乱数を代入。
	}

	//識別する関数を呼び出し、良のものを識別させる。
	cout	<<"良----------\n";
	put_list(a, n, isB);

	//識別する関数を呼び出し、優のものと可のものを識別させる。
	cout	<<"\n優または可--\n";
	put_list(a, n, isAorC);

	//識別する関数を呼び出し、不可のものを識別させる。
	cout	<<"\n不可-------\n";
	put_list(a, n, isD);

	return 0;
}

//成績は良（70～79点か）どうかを判定する関数の宣言。
bool isB(int x)
{
	return x >= 70 && x <= 79;
}

//成績は優（80～100）または可（60～69）かを判定する関数の宣言。
bool isAorC(int x)
{
	return (x >= 80 && x <= 100) || (x >= 60 && x <= 69);
}

//成績は不可（59点以下）どうかを判定する関数の宣言。
bool isD(int x)
{
	return (x >= 0 && x <= 59);
}

//関数の返却値が真である配列の要素を識別表示する関数の宣言。
void put_list(const int a[], int n, bool fit(int))
{
	//配列すべてに対して識別を行う。
	for(int i = 0; i < n; i++) {
		if(fit(a[i])) {
			cout	<<"★";
		} else {
			cout	<<"　";
		}
		cout	<<"a["	<<i	<<"] = "	<<a[i]	<<'\n';
	}
}
