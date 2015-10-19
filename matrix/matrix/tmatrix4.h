#ifndef _TMATRIX4_H_
#define _TMATRIX4_H_


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
		this->~TMatrix_imp4();
		arr = new T*[size];
	}
	
	for (int i = 0; i < size; i++) {
		if (size != m.size)
			arr[i] = new T[size - i];
		for (int j = 0; j < size - i; j++)
			arr[i][j] = m.arr[i][j];
	}
	size = m.size;
	return *this;
}

template<class T>
TMatrix_imp4<T> TMatrix_imp4<T>::operator+(const TMatrix_imp4<T> &m) const
{
	TMatrix_imp4<T> tmp;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - i; j++)
			tmp.arr[i][j] = arr[i][j] + m.arr[i][j];
	return tmp;
}

template<class T>
TMatrix_imp4<T> TMatrix_imp4<T>::operator-(const TMatrix_imp4<T> &m) const
{
	TMatrix_imp4<T> tmp;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - i; j++)
			tmp.arr[i][j] = arr[i][j] - m.arr[i][j];
	return tmp;
}

template<class T>
TMatrix_imp4<T> TMatrix_imp4<T>::operator*(const TMatrix_imp4<T> &m) const
{

}

#endif // _TMATRIX4_H_