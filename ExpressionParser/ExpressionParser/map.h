#ifndef _TABLE_H_
#define _TABLE_H_

#include <string>
using namespace std;

template<class TValue>
class Record
{
public:
	Record(string key = "", TValue value = TValue(0)) : key(key), value(value)
	{ }

	string GetKey() const { return key; }
	TValue GetValue() const { return value; }
	void SetValue(TValue val) { value = val; }
private:
	string key;
	TValue value;
};

template<class T>
class Map
{
public:
	Map(int size = 0);
	Map(const Map<T> &m);
	~Map();

	int GetCount() const { return count; }
	int GetCapacity() const { return size; }
	bool IsEmpty() const { return count == 0; }
	bool IsFull() const { return count == size; }

	void Add(const string &key, const T &value = T(0));
	void Delete(const string &key);
	bool HasValue(const string &key) const;
	T GetValue(const string &key) const;
	void SetValue(const string &key, const T &value);
	
	//T GetValueAt(int index) const;
	//string GetNameAt(int index) const;
	
	Map<T> &operator=(const Map<T> &m);
private:
	int size, count;
	Record<T> *rows;

	int Find(const string &key) const;
};

template<class T>
Map<T>::Map(int size)
{
	this->size = size;
	this->count = 0;
	rows = new Record<T>[size];
}

template<class T>
Map<T>::Map(const Map<T> &m)
{
	this->size = m.size;
	this->count = m.size;
	rows = new Record<T>[size];
	for (int i = 0; i < count; i++)
		rows[i] =  m.rows[i];
}

template<class T>
Map<T>::~Map() {
	delete [] rows;
}

template<class T>
void Map<T>::Add(const string &key, const T &value)
{
	if (IsFull()) throw;
	rows[count++] = Record<T>(key, value);
}

template<class T>
void Map<T>::Delete(const string &key)
{
	int i = Find(key);
	if (i != -1)
		rows[i] = rows[--count];
}

template<class T>
bool Map<T>::HasValue(const string &key) const {
	return Find(key) != -1;
}

template<class T>
T Map<T>::GetValue(const string &key) const
{
	int i = Find(key);
	if (i == -1) throw;
	return rows[i].GetValue();
}

template<class T>
void Map<T>::SetValue(const string &key, const T &value)
{
	int i = Find(key);
	if (i == -1) throw;
	rows[i].SetValue(value);
}

template<class T>
int Map<T>::Find(const string &key) const
{
	for (int i = 0; i < count; i++) {
		if (rows[i].GetKey() == key)
			return i;
	}
	return -1;
}

template<class T>
Map<T> &Map<T>::operator=(const Map<T> &m)
{
	if (size != m.size) {
		delete [] rows;
		rows = new Record<T>[m.size];
	}
	size = m.size;
	count = m.count;
	for (int i = 0; i < count; i++)
		rows[i] = m.rows[i];
	return *this;
}

#endif _TABLE_H_