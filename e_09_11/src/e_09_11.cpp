/*演習9-11
 * 抽象クラステンプレートを使用してキュークラス群とその利用例を実装したプログラムを作成。
 * 作成日：2017年6月5日
 * 作成者：浅田　知嗣
 */

#include <string>
#include <iostream>
#include "e_09_11_Que.h"
#include "e_09_11_ArrayQue.h"
#include "e_09_11_ListQue.h"
#include "e_09_11_VectorQue.h"

using namespace std;

//列挙体の宣言。
enum QueType {ArraySTK, ListSTK, VectorSTK};

//選択に応じた型のスタックを生成する関数の宣言。
template<class Type>
Que<Type>* generate_Que(QueType sw);

//全てのデータをポップして表示する関数の宣言。
template<class Type>
void pop_all(Que<Type>& s);

int main()
{
	int type;		//スタックの種類を選択する変数。
	int menu;		//どの操作を行うかを選択する変数。
	int xlen;		//文字列の長さを格納する型。
	string x;		//プッシュしたい文字列を入力する型。
	char c;			//ポップしてきた文字列を格納する型。

	do {
		//どの種類のスタックを生成するか選択する。
		cout	<<"スタックの種類(0…配列／1…リスト／2…vector)：";
		cin		>>type;
	} while(type < 0 || type > 2);

	//選択に応じた型のスタックを生成。
	Que<char>* s = generate_Que<char>(static_cast<QueType>(type));

	//途中で終了を選択するまで無限ループ
	while(1) {
		//生成したスタックに対してどの操作を行うかを選択する。
		cout	<<"(1)プッシュ (2)ポップ (3)全ポップ＆表示 (0)終了：";
		cin		>>menu;

		//終了が選択されたら終了。
		if(menu == 0) {
			break;

		//プッシュするときの分岐。
		} else if (menu == 1) {
			//スタックに対してプッシュしたい文字列を入力する。
			cout	<<"プッシュしたい文字列を入力してください：";
			cin		>>x;

			xlen = x.length();		//文字列の長さを取得する。

			//スタックがなくなったときに例外を送出する。
			try {
				//入力した文字列をプッシュしていく。
				for(int i = 0 ; i < xlen; i++) {
					s -> push(x[i]);
				}
			}

			catch(const Que<char>::Overflow&) {
				cout	<<"オーバーフローしました。\n";
			}

		//キューするときの分岐。
		} else if(menu == 2) {
			//スタックがなくなったときに例外を送出する。
			try {

				//文字列をキューしてくる。
				c = s -> que();

				//キューしてきたデータを表示。
				cout	<<"ポップしたデータは"	<<c	<<"です。\n";
			}

			catch(const Que<char>::Empty&) {
				cout	<<"スタックは空です。\n";
			}

		//全データをポップするときの分岐。
		} else if (menu == 3) {
			//全データをポップする関数を呼び出す。
			pop_all(*s);
			cout	<<'\n';
		}
	};

	return 0;
}

//選択に応じた型のスタックを生成する関数の定義。
template<class Type>
Que<Type>* generate_Que(QueType sw)
{
	switch(sw) {
	case ArraySTK:	return new ArrayQue<Type>();			//配列版スタック。
	case ListSTK:	return new ListQue<Type>();			//線形リスト版スタック。
	default:		return new VectorQue<Type>();			//ベクトル版スタック。
	}
}

//全てのデータをポップして表示する関数の定義。
template<class Type>
void pop_all(Que<Type>& s)
{
	cout	<<"{ ";

	//スタックが空の場合例外を送出する。
	try {
		//スタックの中身がなくなるまで無限ループ。
		while(1) {
			cout	<<s.que()	<<" ";
		};
	}

	//スタックがなくなった場合はループを抜ける。
	catch(const Que<char>::Empty&) {
		;
	}

	cout	<<"}";
}
