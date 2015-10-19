#ifndef _TMATRIX5_H_
#define _TMATRIX5_H_


template<class T>
class TVector
{
public:
	TVector(int size = 0, int first = 0);
	TVector(const TVector<T> &v);
	~TVector();

	TVector<T> &operator=(const TVector<T> &v);
	TVector<T> operator+(const TVector<T> &v);
	TVector<T> operator-(const TVector<T> &v);
	T operator*(const TVector<T> &v);

	T &operator[](int i);
private:
	int size;
	int first;
	T *arr;
};

template<class T>
TVector<T>::TVector(int size, int first)
{
	this->size = size;
	this->first = first;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}

template<class T>
TVector<T>::TVector(const TVector<T> &v)
{
	size = v.size;
	first = v.first;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = v.arr[i];
}

template<class T>
TVector<T>::~TVector() {
	delete[] arr;
}

template<class T>
TVector<T> &TVector<T>::operator=(const TVector<T> &v)
{
	if (size != v.size) {
		delete[] arr;
		arr = new T[size];
	}
	size = v.size;
	first = v.first;
	for (int i = 0; i < size; i++)
		arr[i] = v.arr[i];
}

template<class T>
TVector<T> operator+(const TVector<T> &v)
{
	TVector<T> tmp(min(size, v.size));
}

#endif // _TMATRIX5_H_