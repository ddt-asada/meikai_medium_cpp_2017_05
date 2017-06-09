/*演習12-5
 * 要素型がdoubleで要素数が10の配列の全要素の値を読み書きできるプログラム。
 * 作成日：2017年6月6日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<double> pi(10, 3.14159265358979323846);

	//ファイルをオープンする。
	ofstream fos("double.bin", ios_base::binary);

	//ファイルがオープンできなかった場合。
	if(!fos) {
		cout	<<"ファイルをオープンできません。\n";

	//ファイルがオープンできた場合
	} else {
		//配列の全要素をファイルに出力する。
		for(int i = 0; i < 10; i++) {
			fos.write(reinterpret_cast<char*>(&pi[i]), sizeof(double));
		}

		//ファイルをクローズする。
		fos.close();
	}

	//ファイルをオープンする。
	ifstream fis("double.bin", ios_base::binary);

	//ファイルがオープンできなかった場合。
	if(!fis) {
		cout	<<"ファイルをオープンできません。\n";

	//ファイルがオープンできた場合
	} else {

		//配列の全要素にファイルから実数値を入力。
		for(int i = 0; i < 10; i++) {
		fis.read(reinterpret_cast<char*>(&pi[i]), sizeof(double));

		cout	<<"doubleの値は"	<<fixed	<<setprecision(20)	<<pi[i]	<<"です。\n";
		}

		//ファイルをクローズする。
		fis.close();
	}

	return 0;
}
