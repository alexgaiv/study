#ifndef _TMATRIX4_H_
#define _TMATRIX4_H_

using namespace System;
using namespace System::Windows::Forms;

template<class T>
class TMatrix_imp4
{
public:
	TMatrix_imp4(int size = 0);
	TMatrix_imp4(const TMatrix_imp4 &m);
	~TMatrix_imp4();

	TMatrix_imp4<T> &operator=(const TMatrix_imp4<T> &m);
	TMatrix_imp4<T> operator+(const TMatrix_imp4<T> &m) const;
	TMatrix_imp4<T> operator-(const TMatrix_imp4<T> &m) const;
	TMatrix_imp4<T> operator*(const TMatrix_imp4<T> &m) const;

	T GetElem(int i, int j) const {
		if (j < i) return T(0);
		return arr[i][j - i];
	}
	void SetElem(int i, int j, T elem) {
		if (j >= i) arr[i][j - i] = elem;
	}

	void Input(DataGridView ^dataGrid) { }
	void Output(DataGridView ^dataGrid) const { }
private:
	int size;
	int **arr;
};

template<class T>
TMatrix_imp4<T>::TMatrix_imp4(int size)
{
	this->size = size;
	arr = new T*[size];
	for (int i = 0; i < size; i++) {
		arr[i] = new T[size - i];
		for (int j = 0; j < size - i; j++)
			arr[i][j] = 0;
	}
}

template<class T>
TMatrix_imp4<T>::TMatrix_imp4(const TMatrix_imp4 &m)
{
	this->size = m.size;
	arr = new T*[size];
	for (int i = 0; i < size; i++) {
		arr[i] = new T[size - i];
		for (int j = 0; j < size - i; j++)
			arr[i][j] = m.arr[i][j];
	}
}

template<class T>
TMatrix_imp4<T>::~TMatrix_imp4()
{
	for (int i = 0; i < size; i++)
		delete[] arr[i];
	delete[] arr;
}

template<class T>
TMatrix_imp4<T> &TMatrix_imp4<T>::operator=(const TMatrix_imp4<T> &m)
{
	if (size != m.size) {
		size = m.size;
		this->~TMatrix_imp4();
		arr = new T*[size];
	}
	
	for (int i = 0; i < size; i++) {
		if (size != m.size)
			arr[i] = new T[size - i];
		for (int j = 0; j < size - i; j++)
			arr[i][j] = m.arr[i][j];
	}
	return *this;
}

template<class T>
TMatrix_imp4<T> TMatrix_imp4<T>::operator+(const TMatrix_imp4<T> &m) const
{
	if (size != m.size) return TMatrix_imp4<T>();
	TMatrix_imp4<T> tmp(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - i; j++)
			tmp.arr[i][j] = arr[i][j] + m.arr[i][j];
	return tmp;
}

template<class T>
TMatrix_imp4<T> TMatrix_imp4<T>::operator-(const TMatrix_imp4<T> &m) const
{
	if (size != m.size) return TMatrix_imp4<T>();
	TMatrix_imp4<T> tmp(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - i; j++)
			tmp.arr[i][j] = arr[i][j] - m.arr[i][j];
	return tmp;
}

template<class T>
TMatrix_imp4<T> TMatrix_imp4<T>::operator*(const TMatrix_imp4<T> &m) const
{
	if (size != m.size) return TMatrix_imp4<T>();
	TMatrix_imp4<T> res(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int ij = 0;
			for (int k = 0; k < size; k++) {
				ij += GetElem(i, k) * m.GetElem(k, j);
			}
			res.SetElem(i, j, ij);
		}
	}
	return res;
}

void TMatrix_imp4<int>::Input(DataGridView ^dataGrid)
{
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++) {
			DataGridViewCell ^c = dataGrid->Rows[i]->Cells[j];
			int val = 0;
			if (c->Value != nullptr) 
				Int32::TryParse(c->Value->ToString(), val);
			SetElem(i, j, val);
		}
}

void TMatrix_imp4<int>::Output(DataGridView ^dataGrid) const
{
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++) {
			DataGridViewCell ^c = dataGrid->Rows[i]->Cells[j];
			c->Value = GetElem(i, j).ToString();
			
		}
}

#endif // _TMATRIX4_H_