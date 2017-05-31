/*演習8-1
 * set_terminate関数によってexception_errorを登録したプログラムの動作の検証。
 * 作成日：2017年5月31日
 * 作成者：浅田　知嗣
 */

#include <cctype>
#include <string>
#include <iostream>
#include <exception>

using namespace std;

class FormatError {};		//不正な書式
class ValueError {};		//不正な値

//文字列をint型の値に変換する関数の宣言。
int string_to_int(const string&str);

//整数値を読み込む関数の宣言。
int get_int();

//low以上high以下の整数値を読み込む関数の宣言。
int get_int_bound(int low, int high);

//terminate関数の挙動の変更。
void exception_error();

int main()
{
	//例外処理の設定。
	set_terminate(exception_error);


	//異常終了するために適当な例外処理を送出する。
	throw 1;

	//例外補足。
	try {
		cout	<<"aの値：";
		int a = get_int();		//関数からaの値を読み込む。

		cout	<<"bの値（10～99）：";
		int b = get_int_bound(10, 99);	//関数からbの値を読み込む。

		cout	<<"a+ b は"	<<a + b	<<"です。\n";

	//例外を補足した時。
	} catch (...) {
		cout	<<"入力エラー発生！！\n";
	}

	return 0;
}

//文字列をint型の値に変換する関数の定義。
int string_to_int(const string&str)
{
	unsigned i = 0;	//警告が出ないように符号なし整数型で宣言。
	int no = 0;		//変換後の数値。
	int sign = 1;	//符号。

	//空白文字類を読み飛ばす。
	while(isspace(str[i])) {
		i++;
	};

	//符号の判定。
	switch(str[i]){
	case '+':	i++;				break;		//正符号の時。
	case '-':	i++;	sign = -1;	break;		//負符号の時。
	}

	//不正な文字を発見するための繰り返し。
	while(i < str.length()) {
		//不正な文字を見つけたとき。
		if(!isdigit(str[i])) {
			throw FormatError();		//例外を送出。
		}

		no = no * + (str[i] - '0');
		i++;
	}

	//整数値に変換したものに符号をつけて返す。
	return no *= sign;
}

//整数値を読み込む関数の定義。
int get_int()
{
	int no = 0;
	string temp;

	//例外補足。
	try {
		cin	>>temp;		//文字列として読み込む。
		no = string_to_int(temp);	//整数値に変換。

		//何もなければ整数値を返す。
		return no;

	//例外を補足した時。
	} catch (FormatError&) {
		cout	<<"数字以外の文字が入力されました。\n";
		throw;
	}
}

//low以上high以下の整数値を読み込む関数の定義。
int get_int_bound(int low, int high)
{
	int no = low;

	//例外補足。
	try {
		no = get_int();

		//範囲外の数値であれば。
		if((no < low) || (no > high)) {
			//例外を送出。
			throw ValueError();
		}

		//何もなければそのまま整数値を返す。
		return no;

	//例外補足。
	} catch (ValueError&) {
		cout	<<"不正な値が入力されました。\n";
		throw;
	}
}

//terminate関数の挙動の変更。
void exception_error()
{
	cout	<<"例外関連のエラーが発生しました。\n";
	abort();
}

//処理すべき例外がない場合は、異常終了したことが宣言された後に、terminate関数が呼び出された。
