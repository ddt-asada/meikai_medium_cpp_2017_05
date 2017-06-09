/*演習9-9
 * スタッククラステンプレートにメンバ関数を追加。
 * 作成日：2017年6月5日
 * 作成者：浅田　知嗣
 * 更新日：2017年6月9日
 * 更新者：浅田　知嗣
 */

#ifndef ___Class_SimpleStack
#define ___Class_SimpleStack

//スタッククラステンプレート
template<class Type> class SimpleStack
{
	int size;			//スタックの容量。
	int ptr;			//スタックのポインタ。
	Type* stk;			//スタックの本体の先頭要素へのポインタ。

	SimpleStack(const SimpleStack<Type>&);		//コピーコンストラクタをの外部呼出しを無効。
	SimpleStack& operator=(const SimpleStack<Type>&);	//代入演算子を外部呼出しを無効。

public:
	//スタックが満タンの時にプッシュされたときに送出される例外クラス。
	class Overflow{};

	//空のスタックからのポップしようとしたときに送出される例外クラス。
	class Empty{};

	//明示的コンストラクタ。
	explicit SimpleStack(int sz);

	//デストラクタ
	~SimpleStack();

	//プッシュ
	Type& push(const Type& x);

	//ポップ
	Type pop();

	//頂上のデータを変更することなくそのまま返す。
	Type& peek() const;

	//スタックの容量のゲッタ。
	int capacity() const;

	//スタックが満杯かどうかを返す。
	bool is_full() const;

	//スタックが空であるかどうかを返す。
	bool is_empty() const;
};


#include "e_09_09_SmpleStackImplementation.h"
#endif
