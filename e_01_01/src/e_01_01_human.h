/*演習1-1
 * データメンバの初期化がクラス定義のデータメンバの宣言順に行われていることを確認するプログラム。
 * 作成日：2017年5月20日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#ifndef ___Class_Human
#define ___Class_Human

#include <string>

//人間クラスの定義。
class Human
{
	std::string full_name;		//氏名
	int height;					//身長
	int weight;					//体重

public:
	//コンストラクタの宣言。
	Human(const std::string&full_name, int height, int weight);

	//氏名を返すゲッタの宣言。
	std::string name() const;

	//身長を返すゲッタの宣言。
	int get_height() const;

	//体重を返すゲッタの宣言。
	int get_weight() const;

	//体重を加算するセッタの宣言。
	void grow_fat(int dw);

	//体重を減ｚナンするセッタの宣言。
	void slim_off(int dw);
};

#endif
