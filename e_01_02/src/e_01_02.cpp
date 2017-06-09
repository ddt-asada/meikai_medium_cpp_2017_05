/*演習1-2
 * 与えられた日付が不正であれば、正しい値に変換して返却するように変更したクラス。
 * 作成日：2017年5月21日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */


#include <iostream>
#include "e_01_02_Date.h"

using namespace std;

//不正な値を入力した場合正常な値に変換して代入されるように変更しました。

//--- 日付に関する情報を表示 ---//
void display(const Date& day)
{
	string dw[] = { "日", "月", "火", "水", "木", "金", "土" };
	cout << "・日付" << day << "に関する情報\n";
	cout << "  曜日は" << dw[day.day_of_week()] << "曜日";
	cout << "  年内経過日数は" << day.day_of_year() << "日";
	cout << "  1970年1月1日の" << long(day) << "日後";
	cout << "  その年は閏年で" << (day.leap_year() ? "ある" : "はない。") << '\n';
}

//--- 日付を変更 ---//
void change(Date& day)
{
	while (true) {
		//日付の処理方法を選択する。
		cout << "[1]年変更 [2]月変更 [3]日変更 [4]年月日変更 "
			<< "[5]n日進める [6]n日戻す [0]戻る：";
		int selected;
		cin >> selected;

		//0の時は何もせずに呼び出された位置に戻る。
		if(selected == 0){
			return;
		}

		int y, m, d, n;
		//選択に応じて分岐する。
		//1または4の時は年数を書き換える。
		if (selected == 1 || selected == 4) {
			cout << "年：";
			cin >> y;
		}

		//2または4の時は月を書き換える。
		if (selected == 2 || selected == 4) {
			cout << "月：";
			cin >> m;
		}

		//3または4の時は日数を書き換える。
		if (selected == 3 || selected == 4) {
			cout << "日：";
			cin >> d;
		}

		//5または6の時は何日進めるかまたは戻すかを入力する。
		if (selected == 5 || selected == 6) {
			cout << "日数：";
			cin >> n;
		}

		switch (selected) {
		//年数を書き換えるセッタを呼び出す。
		case 1: day.set_year(y);	break;		// y年に設定
		//月数を書き換えるセッタを呼び出す。
		case 2: day.set_month(m);	break;		// m月に設定
		//日数を書き換えるセッタを呼び出す。
		case 3: day.set_day(d);	break;		// d日に設定
		//年月日すべてを書き換えるセッタを呼び出す。
		case 4: day.set(y, m, d);	break;		// y年m月d日に設定
		//n日進めるメンバ関数を呼び出す。
		case 5: day += n;			break;		// n日進める
		//n日戻すメンバ関数を呼び出す。
		case 6: day -= n;			break;		// n日戻す
		}

		cout << day << "に更新されました。\n";
	}
}

//--- 増分および減分演算子を適用 ---//
void inc_dec(Date& day)
{
	while (true) {
		//処理方法の選択。
		cout << "[1]++day  [2]day++  [3]--day  [4]day-- [0]戻る：";
		int selected;
		cin >> selected;

		//0の場合何もしない。
		if (selected == 0) return;

		switch (selected) {
		//1の時はインクリメントする。
		case 1: cout << "++day = " << ++day << '\n';  break;	// 前置増分
		//2の時はインクリメントする。
		case 2: cout << "day++ = " << day++ << '\n';  break;	// 後置増分
		//3の時はデクリメントする。
		case 3: cout << "--day = " << --day << '\n';  break;	// 前置減分
		//4の時はデクリメントする。
		case 4: cout << "day-- = " << day-- << '\n';  break;	// 後置減分
		}
		cout << "day   = " << day << '\n';
	}
}

//--- 前後の日付を求める ---//
void before_after(Date& day)
{
	while (true) {
		//処理方法を選択する。
		cout << "[1]翌日 [2]前日 [3]n日後(day+n) [4]n日後(n+day)"
			<< "[5]n日前 [0]戻る：";
		int selected;
		cin >> selected;


		//0の場合何もしない。
		if (selected == 0) return;

		int n;
		//3または4または5の時は先に何日進めるかを入力する。
		if (selected >= 3 && selected <= 5) {
			cout << "日数：";  cin >> n;
		}

		cout << "それは";
		switch (selected) {
		//1の場合は翌日の値を返す。メンバの値は変更されない。
		case 1: cout << day.following_day();	break;	// 翌日
		//2の場合は前日の値を返す。メンバの値は変更されない。
		case 2: cout << day.preceding_day();	break;	// 前日
		//3の場合はn日後の値を返す。メンバの値は変更されない。
		case 3: cout << day + n;				break;	// n日後（Date + int ）
		//4の場合はn日後の値を返す。メンバの値は変更されない。
		case 4: cout << n + day;				break;	// n日後（int  + Date）
		//5の場合はn日前の値を返す。メンバの値は変更されない。
		case 5: cout << day - n;				break;	// n日前（Date - int ）
		}
		cout << "です。\n";
	}
}

//--- 他の日付との比較 ---//
void compare(const Date& day)
{
	int y, m, d;
	//処理方法を選択する。
	cout << "比較対象の日付day2を入力せよ。\n";
	cout << "年：";  cin >> y;
	cout << "月：";  cin >> m;
	cout << "日：";  cin >> d;

	Date day2(y, m, d);	// 比較対象の日付

	cout << boolalpha;
	//dayオブジェクトの中身を確認する。
	cout << "day  = " << day << '\n';
	//day2オブジェクトの中身を確認する。
	cout << "day2 = " << day2 << '\n';
	//演算を行う。
	cout << "day  -  day2  = " << (day - day2) << '\n';
	//演算を行う。
	cout << "day2 -  day   = " << (day2 - day) << '\n';
	//演算を行う。
	cout << "day  == day2  = " << (day == day2) << '\n';
	//演算を行う。
	cout << "day  != day2  = " << (day != day2) << '\n';
	//演算を行う。
	cout << "day  >  day2  = " << (day  >  day2) << '\n';
	//演算を行う。
	cout << "day  >= day2  = " << (day >= day2) << '\n';
	//演算を行う。
	cout << "day  <  day2  = " << (day  <  day2) << '\n';
	//演算を行う。
	cout << "day  <= day2  = " << (day <= day2) << '\n';
}

int main()
{
	int y, m, d;
	//日付の入力を促す。
	cout << "日付dayを入力せよ。\n";
	cout << "年：";  cin >> y;
	cout << "月：";  cin >> m;
	cout << "日：";  cin >> d;

	Date day(y, m, d);	// 読み込んだ日付

	while (true) {
		//処理方法を選択する。
		cout << "[1]情報表示 [2]日付の変更 [3]増減分演算子 [4]前後の日付 "
			<< "[5]比較 [0]終了：";

		int selected;
		cin >> selected;

		//0の時は何もしない。
		if (selected == 0) break;

		switch (selected) {
		//1の時は情報を表示。
		case 1: display(day);		break;	// 日付に関する情報を表示
		case 2: change(day);		break;	// 日付を変更
		case 3: inc_dec(day);		break;	// 増分演算子・減分演算子
		case 4: before_after(day);	break;	// 前後の日付を求める
		case 5: compare(day);		break;	// 他の日付との比較
		}
	}
}
