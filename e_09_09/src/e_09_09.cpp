/*演習9-9
 * スタッククラステンプレートにメンバ関数を追加。
 * 作成日：2017年6月5日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <string>
#include <iostream>
#include "e_09_09_SmpleStack.h"

using namespace std;

int main()
{
	string x;		//スタックに渡す文字列。
	int xlen;		//スタックに渡す文字列xの長さ。

	//スタックに渡す文字列xの入力を促す。
	cout	<<"文字列：";
	cin		>>x;

	xlen = x.length();		//スタックに渡す文字列xの長さを取得。

	//スタックの空き箱を生成するクラスに文字列xの長さを渡す。
	SimpleStack<char> s(xlen);

	//スタックの容量を確認する。
	cout	<<"スタックの容量は"	<<s.capacity()	<<"です。\n";

	//スタックに関する例外処理の宣言。
	try {
		//スタックに文字列xをプッシュする。
		for(int i = 0; i < xlen; i++) {
			s.push(x[i]);

			//スタックが満杯かどうかを確認する。
			if(s.is_full()) {
				cout	<<"スタックは満杯です。\n";

			} else {
				cout	<<"スタックは満杯ではありません。\n";
			}
		}

		//スタックが空かどうかを確認する。
		if(s.is_empty()) {
			cout	<<"スタックは空です。\n";

		} else {
			cout	<<"スタックに何かが入ってます。\n";
		}

		//スタックから文字列xをポップして表示し、中身を確認する。
		for(int i = 0; i < xlen; i++) {
			//頂上のデータを変更することなく取得しつつ表示。
			char c = s.peek();
			cout	<<c;

			//ポップしながら、減らしながら取得して表示。
			c = s.pop();
			cout	<<c;
		}

		cout	<<'\n';
	}

	//満杯のスタックからプッシュしようとしたときの例外処理。
	catch(const SimpleStack<char>::Overflow&) {
		cout	<<"満杯の<char>スタックにプッシュしようとしました。\n";
	}

	//空のスタックからポップしようとしたときの例外処理。
	catch(const SimpleStack<char>::Empty&) {
		cout	<<"空の<char>スタックからポップしようとしました。\n";
	}

	return 0;
}
