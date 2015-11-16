#ifndef _STACK_H_
#define _STACK_H_

template<class T>
class Stack
{
public:
	Stack(int size = 0);
	Stack(const Stack<T> &s)
	~Stack();

	Stack<T> &operator=(const Stack<T> &s);

	int GetSize() const { return last; }
	bool IsEmpty() const { return last == 0; }
	bool IsFull() const { return last == size; }

	void Push(T elem);
	T Pop();
	T Top() const;
private:
	int *data;
	int size, last;
};

template<class T>
Stack<T>::Stack(int size)
{
	this->size = size;
	this->last = 0;
	data = new T[size];
}

template<class T>
Stack<T>::Stack(const Stack<T> &s)
{
	size = s.size;
	last = s.last;
	data = new T[size];
	for (int i = 0; i < last; i++)
		data[i] = s.data[i];
}

template<class T>
Stack<T>::~Stack() {
	delete [] data;
}

template<class T>
void Stack<T>::Push(T elem)
{
	if (IsFull()) throw;
	data[last++] = elem;
}

template<class T>
T Stack<T>::Pop()
{
	if (IsEmpty()) throw;
	return data[--last];
}

template<class T>
T Stack<T>::Top() const
{
	if (IsEmpty()) throw;
	return data[last - 1];
}

#endif // _STACK_H_