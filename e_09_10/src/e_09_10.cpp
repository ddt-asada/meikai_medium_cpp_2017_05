/*演習9-10
 * キューを実現するクラステンプレートの作成。
 * 作成日：2017年6月5日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <string>
#include <iostream>
#include "e_09_10_SimpleStackQue.h"

using namespace std;

int main()
{
	string x;		//スタックに渡す文字列。
	string y;		//スタックに渡す文字列。
	int len;		//スタックに渡す文字列の長さ。

	//キューに渡す文字列xの入力を促す。
	cout	<<"文字列：";
	cin		>>x;

	len = x.length();		//スタックに渡す文字列xの長さを取得。

	//キューの空き箱を生成するクラスに文字列xの長さを渡す。
	Queue<char> s(len);

	//キューの容量を確認する。
	cout	<<"キューの容量は"	<<s.capacity()	<<"です。\n";

	//キューに関する例外処理の宣言。
	try {
		//キューに文字列xをプッシュする。
		for(int i = 0; i < len; i++) {
			s.push(x[i]);

			cout	<<x[i]	<<"をプッシュしました。\n";

			//キューが満杯かどうかを確認する。
			if(s.is_full()) {
				cout	<<"キューは満杯です。\n";

			} else {
				cout	<<"キューは満杯ではありません。\n";
			}
		}

		//キューから文字列xをキューして表示し、中身を確認する。
		for(int i = 0; i < len; i++) {
			//キューしながら取得して表示。
			char c = s.pop();
			cout	<<c;
		}

		cout	<<'\n';

		//キューが空かどうかを確認する。
		if(s.is_empty()) {
			cout	<<"キューは空です。\n";

		} else {
			cout	<<"キューに何かが入ってます。\n";
		}

		cout	<<"もう一度プッシュします。\n";
		cout	<<"文字列：";
		cin		>>y;

		len = y.length();

		//キューに文字列xをプッシュする。
		for(int i = 0; i < len; i++) {
			s.push(y[i]);

			cout	<<y[i]	<<"をプッシュしました。\n";

			//キューが満杯かどうかを確認する。
			if(s.is_full()) {
				cout	<<"キューは満杯です。\n";

			} else {
				cout	<<"キューは満杯ではありません。\n";
			}
		}

		//キューから文字列xをポップして表示し、中身を確認する。
		for(int i = 0; i < len; i++) {
			//ポップしながら取得して表示。
			char c = s.pop();
			cout	<<c;
		}

		cout	<<'\n';

		//キューが空かどうかを確認する。
		if(s.is_empty()) {
			cout	<<"キューは空です。\n";

		} else {
			cout	<<"キューに何かが入ってます。\n";
		}

		cout	<<'\n';
	}

	//満杯のキューからプッシュしようとしたときの例外処理。
	catch(const Queue<char>::Overflow&) {
		cout	<<"満杯の<char>キューにプッシュしようとしました。\n";
	}

	//空のスタックからポップしようとしたときの例外処理。
	catch(const Queue<char>::Empty&) {
		cout	<<"プッシュされたキューを超えてポップしようとしました。\n";
	}

	return 0;
}
