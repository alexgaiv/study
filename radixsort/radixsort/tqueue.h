#ifndef _TQueue_H_
#define _TQueue_H_

template<class T>
class ListEntry
{
public:
	T data;
	ListEntry *next;

	ListEntry(T data = T(0), ListEntry<T> *next = 0)
		: data(data), next(next) { }
	~ListEntry() {
		if (next) delete next;
	}
};

template<class T>
class TQueue
{
public:
	TQueue() { first = last = 0; }
	TQueue(const TQueue &q);
	~TQueue() { if (first) delete first; }

	TQueue<T> &operator=(const TQueue<T> &q);

	bool IsEmpty() const { return first == 0; }

	void Push(T elem);
	T Pop();
private:
	ListEntry<T> *first;
	ListEntry<T> *last;
};

template<class T>
TQueue<T>::TQueue(const TQueue &q)
{
	first = last = 0;
	ListEntry<T> *iter = q.first;
	while (iter) {
		Push(iter->data);
		iter = iter->next;
	}
}

template<class T>
TQueue<T> &TQueue<T>::operator=(const TQueue<T> &q)
{
	if (first) delete first;
	first = last = 0;
	ListEntry<T> *iter = q.first;
	while (iter) {
		Push(iter->data);
		iter = iter->next;
	}
	return *this;
}

template<class T>
void TQueue<T>::Push(T elem)
{
	ListEntry<T> *e = new ListEntry<T>(elem);
	if (!first) {
		first = last = e;
	}
	else {
		last->next = e;
		last = e;
	}
}

template<class T>
T TQueue<T>::Pop()
{
	if (IsEmpty()) throw;
	ListEntry<T> *tmp = first;
	T elem = tmp->data;

	first = first->next;
	tmp->next = 0;
	delete tmp;

	if (!first) last = 0;
	return elem;
}



#endif // _TQueue_H_