/*演習3-5
 * 九九の加算表と乗算票のどちらを表示するのかを選択させ、表示させるプログラム。
 * 作成日：2017年5月25日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include<iomanip>
#include <iostream>

using namespace std;

void (*kukuselect())();

void kukusum();

void kukumul();

int main()
{
	//九九の演算方法を選択する関数から帰ってきた関数のポインタに応じて関数を呼び出す。
	void (*kuku)() = kukuselect();
	kuku();

	return 0;
}

void (*kukuselect())()
{
	int select;		//なにを求めるかを選択する変数。

	//どちらを求めるかを選択させる。
	cout	<<"九九の加算と乗算どちらを行いますか\n加算…0／乗算…1：";
	cin		>>select;

	//どちらの九九の演算を行うかを選択に応じて分岐。
	switch (select) {
	case 0:		return kukusum;
	case 1:		return kukumul;
	}
	return NULL;
}

void kukusum()
{
	//九九を表として見せるための枠を作る。
	cout	<<"  |";
	//九九の添字を表の上の端に表示する。
	for(int i = 1; i <= 9; i++) {
		cout	<<setw(3)	<<'\n';
	}

	//添字と計算結果の境目。
	cout	<<"\n--+";
	for(int i = 1; i <= 27; i++) {
		cout	<<'-';
	}
	cout	<<'\n';

	//表の左端に添字を表示しつつ右に向かって計算していく。
	for(int i = 1; i <= 9; i++) {
		cout	<<i	<<" |";
		//右に向かって計算を行う。
		for(int j = 1; j <= 9; j++) {
			cout	<<setw(3)	<<i + j;
		}
		cout	<<'\n';
	}
}

void kukumul()
{
	//九九を表として見せるための枠を作る。
	cout	<<"  |";
	//九九の添字を表の上の端に表示する。
	for(int i = 1; i <= 9; i++) {
		cout	<<setw(3)	<<'\n';
	}

	//添字と計算結果の境目。
	cout	<<"\n--+";
	for(int i = 1; i <= 27; i++) {
		cout	<<'-';
	}
	cout	<<'\n';

	//表の左端に添字を表示しつつ右に向かって計算していく。
	for(int i = 1; i <= 9; i++) {
		cout	<<i	<<" |";
		//右に向かって計算を行う。
		for(int j = 1; j <= 9; j++) {
			cout	<<setw(3)	<<i * j;
		}
		cout	<<'\n';
	}
}
