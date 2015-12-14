#ifndef _TStack_H_
#define _TStack_H_

template<class T>
class TStack
{
public:
	TStack(int size = 0);
	TStack(const TStack<T> &s);
	~TStack();

	TStack<T> &operator=(const TStack<T> &s);

	int GetCount() const { return last; }
	int GetCapacity() const { return size; }
	bool IsEmpty() const { return last == 0; }
	bool IsFull() const { return last == size; }

	void Push(T elem);
	T Pop();
	T Top() const;
private:
	T *data;
	int size, last;
};

template<class T>
TStack<T>::TStack(int size)
{
	this->size = size;
	this->last = 0;
	data = new T[size];
}

template<class T>
TStack<T>::TStack(const TStack<T> &s)
{
	size = s.size;
	last = s.last;
	data = new T[size];
	for (int i = 0; i < last; i++)
		data[i] = s.data[i];
}

template<class T>
TStack<T> &TStack<T>::operator=(const TStack<T> &s)
{
	if (size != s.size) {
		delete [] data;
		data = new T[s.size];
	}
	size = s.size;
	last = s.last;
	for (int i = 0; i < last; i++)
		data[i] = s.data[i];
	return *this;
}

template<class T>
TStack<T>::~TStack() {
	delete [] data;
}

template<class T>
void TStack<T>::Push(T elem)
{
	if (IsFull()) throw;
	data[last++] = elem;
}

template<class T>
T TStack<T>::Pop()
{
	if (IsEmpty()) throw;
	return data[--last];
}

template<class T>
T TStack<T>::Top() const
{
	if (IsEmpty()) throw;
	return data[last - 1];
}

#endif // _TStack_H_