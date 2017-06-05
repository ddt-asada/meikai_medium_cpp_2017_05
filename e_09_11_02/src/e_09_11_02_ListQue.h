/*演習9-11
 * 抽象クラステンプレートを使用してキュークラス群とその利用例を実装したプログラムを作成。
 * 作成日：2017年6月5日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_ListQue
#define ___Class_ListQue

#include "e_09_11_02_Que.h"

//線形リストによるスタッククラステンプレート
template<class Type> class ListQue : public Que<Type>
{

	//ノード
	template<class Type> class Node
	{
		friend class ListQue<Type>;
		Type* data;			//データ。
		Node* next;			//後続ポインタ。

	public:
		Node(Type* d, Node* n) : data(d), next(n) {}
	};

	Node<Type>* top;		//先頭ノードへのポインタ
	Node<Type>* dummy;		//ダミーノードへのポインタ

public:
	//コンストラクタ
	ListQue()
	{
		top = dummy = new Node<Type>(0, 0);
	}

	//デストラクタ
	~ListQue()
	{
		Node<Type>* ptr = top;

		//ポインタをすべて削除するまで繰り返す。
		while(ptr != dummy) {
			Node<Type>* next = ptr -> next;
			delete ptr -> data;
			delete ptr;
			ptr = next;
		};

		delete dummy;
	}

	//プッシュ
	void push(const Type& x)
	{
		//ノードが先頭を指すようにする。
		Node<Type>* ptr = top;

		try {
			top = new Node<Type>(new Type(x), ptr);
		}

		catch(const bad_alloc&) {
			throw Overflow();
		}
	}

	//キュー
	Type que()
	{
		//ダミーと先頭が同じときはスタックが空。
		if(top == dummy) {
			throw Empty();

		} else {
			Node<Type>* ptr = top -> next;
			Type temp = *(top -> ddata);
			delete top -> data;
			delete top;
			top = ptr;
			return temp;
		}
	}
};

#endif
