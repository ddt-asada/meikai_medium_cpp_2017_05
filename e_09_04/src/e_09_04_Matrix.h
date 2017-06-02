/*演習9-4
 * 二つの展示を持つ2次元配列クラステンプレートを作成。
 * 作成日：2017年6月2日
 * 作成者：浅田　知嗣
 */

#ifndef ___ClassTemplate_Matrix
#define ___ClassTemplate_Matrix

#include <iomanip>


//配列のクラステンプレート
template <class Type> class Matrix
{
	int		row;		//行列の行に当たる要素数。
	int		colum;		//行列の列に当たる部分の要素数。
	Type**	vec;		//配列の先頭要素へのポインタ。

	//添字が妥当かどうかを判定。この判定によって返却先で例外を送出する。
	bool is_valid_index(int idx)
	{
		return ((idx > 0 && idx <= row) || (idx > 0 && idx <= colum));
	}

public:
	//添字範囲エラーを送出するためのクラス。
	class IdxRngErr
	{
		const Matrix* ident;		//配列のクラステンプレートへのポインタ。
		int idx;				//エラーが出た配列の要素。
	public:
		//コンストラクタ
		IdxRngErr(const Matrix* p, int i) : ident(p), idx(i) { }

		//エラーが出た場所を返す関数。
		int Index() const
		{
			return idx;
		}
	};

	//明示的コンストラクタ
	explicit Matrix(int r, int c, const Type& v = Type()) : row(r), colum(c)
	{
		//配列を生成。
		vec = new Type*[row + 1];					//行列の行に当たる部分を生成。
		*vec = new Type[(row + 1) * (colum + 1)];	//行列の全要素分の配列を生成。

		//ポインタの配列が配列の各行の先頭要素を指すようにする。
		for(int i = 1; i <= row; i++) {
			*(vec + i) = *vec + (i * colum);
		}

		//値の初期化。値の初期値は呼び出し側のデフォルトコンストラクタを指定。
		for(int i = 1; i <= row; i++) {
			for(int j = 1; j <= colum; j++) {
				vec[i][j] = v;
			}
		}
	}

	//コピーコンストラクタ
	Matrix(const Matrix<Type>& x)
	{
		//自己初期化に対応する。自己初期化の場合は空の配列とする。
		if(&x == this) {
			row   = 0;
			colum = 0;
			vec   = 0;

		} else {
			row   = x.row;		//行数のコピー
			colum = x.colum;	//列数のコピー
			vec   = new Type*[row + 1];					//行列の行に当たる部分を生成。
			*vec  = new Type[(row + 1) * (colum + 1)];	//行列の全要素分の配列を生成。
		}

		//ポインタの配列が配列の各行の先頭要素を指すようにする。
		for(int i = 1; i <= row; i++) {
			*(vec + i) = *vec + (i * colum);
		}

		//値の初期化。値の初期値は呼び出し側のデフォルトコンストラクタを指定。
		for(int i = 1; i <= row; i++) {
			for(int j = 1; j <= colum; j++) {
				vec[i][j] = x.vec[i][j];
			}
		}
	}

	//デストラクタ
	~Matrix()
	{
		delete[] vec;
	}

	//行数数を返す。
	int height() const
	{
		return row;
	}

	//列数を返す。
	int width() const
	{
		return colum;
	}

	//行列の表示。
	void display_matrix()
	{
		for(int i = 1; i <= row; i++) {
			for(int j = 1; j <= colum; j++) {
				std::cout	<<std::setw(3)	<<vec[i][j];
			}
			std::cout	<<'\n';
		}
		std::cout	<<'\n';
	}


	//代入演算子。
	Matrix& operator=(const Matrix<Type>& x)
	{
		//自己初期化に対応する。自己初期化の場合は空の配列とする。
		if(&x == this) {
			row   = 0;
			colum = 0;
			vec   = 0;

		} else {
			row   = x.row;		//行数のコピー
			colum = x.colum;	//列数のコピー
			vec   = new Type*[row + 1];					//行列の行に当たる部分を生成。
			*vec  = new Type[(row + 1) * (colum + 1)];	//行列の全要素分の配列を生成。
		}

		//ポインタの配列が配列の各行の先頭要素を指すようにする。
		for(int i = 1; i <= row; i++) {
			*(vec + i) = *vec + (i * colum);
		}

		//値の初期化。値の初期値は呼び出し側のデフォルトコンストラクタを指定。
		for(int i = 1; i <= row; i++) {
			for(int j = 1; j <= colum; j++) {
				vec[i][j] = x.vec[i][j];
			}
		}

		//代入し終わった配列を返す。
		return *this;
	}

	//添字演算子[]
	Type* & operator[](int i)
	{
		//添字を妥当性を確かめる関数に渡しもし、妥当でないという判定が返ってきた場合は例外を送出。
		if(!is_valid_index(i)) {
			//添字範囲のエラーのクラスを呼び出し、要素数と配列の情報を取得し、それを例外として送出する。
			throw IdxRngErr(this, i);
		}

		return vec[i];
	}
/*
	//const版添字演算子[]
	const Type& operator[](int i) const
	{
		//添字を妥当性を確かめる関数に渡しもし、妥当でないという判定が返ってきた場合は例外を送出。
		if(! is_valid_index(i)) {
			//添字範囲のエラーのクラスを呼び出し、要素数と配列の情報を取得し、それを例外として送出する。
			throw IdxRngErr(this, i);
		}

		return vec[i];
	}
	*/
};

#endif
