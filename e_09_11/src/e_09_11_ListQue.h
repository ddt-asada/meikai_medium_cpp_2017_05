/*演習9-11
 * 抽象クラステンプレートを使用してキュークラス群とその利用例を実装したプログラムを作成。
 * 作成日：2017年6月5日
 * 作成者：浅田　知嗣
 */

#ifndef ___Class_ListQue
#define ___Class_ListQue

#include "e_09_11_Que.h"
#include <new>

//線形リストによるスタッククラステンプレート
template<class Type> class ListQue : public Que<Type>
{

	//ノード
	template<class Que> class Node
	{
		friend class ListQue<Type>;
		Type* data;			//データ。
		Node* next;			//後続ポインタ。

	public:
		Node(Type* d, Node* n) : data(d), next(n) {}
	};

	Node<Type>* top;		//先頭ノードへのポインタ
	Node<Type>* dummy;		//ダミーノードへのポインタ
	Node<Type>* end;		//末尾ノードへのポインタ

public:

	//コンストラクタ
	ListQue()
	{
		top = dummy = end = new Node<Type>(0, 0);
	}

	//デストラクタ
	~ListQue()
	{
		Node<Type>* ptr = top;

		//ポインタをすべて削除するまで繰り返す。
		while(ptr != dummy) {
			Node<Type>* next = ptr -> next;
			delete ptr -> data;				//先頭の文字列を削除。
			delete ptr;						//先頭へのポインタを削除。
			ptr = next;						//新たなポインタとして先頭の一つ後ろのポインタを採用。
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

		catch(const std::bad_alloc&) {
			throw Que<char>::Overflow();
		}
	}

	//キュー
	Type que()
	{
		//ダミーと先頭が同じときはスタックが空。
		if(top == dummy) {
			throw Que<char>::Empty();

		} else {
			Node<Type>* ptr = top;		//先頭のポインタを一時的に別の場所に保管する。

			//先頭を指しているポインタの一つ後ろがNULLになるまで繰り返す。
			while (top -> next != dummy) {
				top = top -> next;
			}

			Type temp = *(top -> data);		//末尾の文字列を表示。
			delete top -> data;				//末尾の文字列を削除。
			delete top;						//末尾のポインタを削除。
			dummy = top;					//削除したポインタを新たな末尾として採用。
			top = ptr;						//保管していた先頭へのポインタを戻す。
			return temp;					//末尾の文字列を返す。
		}
	}
};

#endif
