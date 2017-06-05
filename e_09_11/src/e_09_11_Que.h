/*演習9-11
 * 抽象クラステンプレートを使用してキュークラス群とその利用例を実装したプログラムを作成。
 * 作成日：2017年6月5日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_Que
#define ___Class_Que

//スタッククラステンプレート
template<class Type> class Que
{
public:
	//スタックが満タンの時にプッシュされたときに送出される例外クラス。
	class Overflow { };

	//空のスタックからのポップしようとしたときに送出される例外クラス。
	class Empty { };

	//デストラクタ
	virtual ~Que() = 0;

	//プッシュ
	virtual void push(const Type&) = 0;

	//ポップ
	virtual Type que() = 0;
};

//デストラクタ
template <class Type> Que<Type>::~Que() {};

#endif
