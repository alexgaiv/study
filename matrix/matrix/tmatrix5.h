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
	TVector<T> operator+(const TVector<T> &v) const;
	TVector<T> operator-(const TVector<T> &v) const;
	T operator*(const TVector<T> &v) const;

	T &operator[](int i) const {
		if (i < first || i >= size + first) {
			zero = T(0);
			return (T &)zero;
		}
		return arr[i - first];
	}
private:
	int size;
	int first;
	mutable T zero;
	T *arr;
};

template<class T>
class TMatrix_imp5
{
public:
	TMatrix_imp5(int size = 0);
	TMatrix_imp5(const TMatrix_imp5 &m);

	TVector<T> &operator[](int i) {
		return vec[i];
	}
	TMatrix_imp5<T> &operator=(const TMatrix_imp5<T> &m);
	TMatrix_imp5<T> operator+(const TMatrix_imp5<T> &m) const;
	TMatrix_imp5<T> operator-(const TMatrix_imp5<T> &m) const;
	TMatrix_imp5<T> operator*(const TMatrix_imp5<T> &m) const;

	void Input(DataGridView ^dataGrid) { }
	void Output(DataGridView ^dataGrid) const { }
private:
	int size;
	TVector<TVector<T>> vec;
};

template<class T>
TVector<T>::TVector(int size, int first) : zero(T(0))
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
		arr = new T[v.size];
	}
	size = v.size;
	first = v.first;
	for (int i = 0; i < size; i++)
		arr[i] = v.arr[i];
	return *this;
}

template<class T>
TVector<T> TVector<T>::operator+(const TVector<T> &v) const
{
	if (size != v.size || first != v.first) return TVector<T>();

	TVector<T> tmp(size, first);
	for (int i = 0; i < size; i++)
		tmp.arr[i] = arr[i] + v.arr[i];
	return tmp;
}

template<class T>
TVector<T> TVector<T>::operator-(const TVector<T> &v) const
{
	if (size != v.size || first != v.first) return TVector<T>();

	TVector<T> tmp(size, first);
	for (int i = 0; i < size; i++)
		tmp.arr[i] = arr[i] - v.arr[i];
	return tmp;
}

template<class T>
T TVector<T>::operator*(const TVector<T> &v) const
{
	if (size != v.size) return TVector<T>();
	T res = T(0);
	for (int i = 0; i < size; i++)
		res = res + arr[i] * v.arr[i];
	return res;
}


template<class T>
TMatrix_imp5<T>::TMatrix_imp5(int size)
{
	this->size = size;
	vec = TVector<TVector<T>>(size);
	for (int i = 0; i < size; i++) {
		vec[i] = TVector<T>(size - i, i);
	}
}

template<class T>
TMatrix_imp5<T>::TMatrix_imp5(const TMatrix_imp5 &m)
{
	size = m.size;
	vec = m.vec;
}

template<class T>
TMatrix_imp5<T> &TMatrix_imp5<T>::operator=(const TMatrix_imp5<T> &m)
{
	size = m.size;
	vec = m.vec;
}

template<class T>
TMatrix_imp5<T> TMatrix_imp5<T>::operator+(const TMatrix_imp5<T> &m) const
{
	if (size != m.size) return TMatrix_imp5<T>();
	TMatrix_imp5<T> tmp(size);
	tmp.vec = vec + m.vec;
	return tmp;
}

template<class T>
TMatrix_imp5<T> TMatrix_imp5<T>::operator-(const TMatrix_imp5<T> &m) const
{
	if (size != m.size) return TMatrix_imp5<T>();
	TMatrix_imp5<T> tmp(size);
	tmp.vec = vec - m.vec;
	return tmp;
}

template<class T>
TMatrix_imp5<T> TMatrix_imp5<T>::operator*(const TMatrix_imp5<T> &m) const
{
	if (size != m.size) return TMatrix_imp5<T>();
	TMatrix_imp5<T> res(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int ij = 0;
			for (int k = 0; k < size; k++) {
				ij += vec[i][k] * m.vec[k][j];
			}
			res[i][j] = ij;
		}
	}
	return res;
}

void TMatrix_imp5<int>::Input(DataGridView ^dataGrid)
{
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++) {
			DataGridViewCell ^c = dataGrid->Rows[i]->Cells[j];
			int val = 0;
			Int32::TryParse(c->Value->ToString(), val);
			vec[i][j] = val;
		}
}

void TMatrix_imp5<int>::Output(DataGridView ^dataGrid) const
{
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++) {
			DataGridViewCell ^c = dataGrid->Rows[i]->Cells[j];
			c->Value = vec[i][j].ToString();
			
		}
}

#endif // _TMATRIX5_H_