#ifndef _TMAP_H_
#define _TMAP_H_

#include <string>
using namespace std;

template<class TValue>
class TRecord
{
public:
	TRecord(string key = "", TValue value = TValue(0)) : key(key), value(value)
	{ }

	string GetKey() const { return key; }
	TValue GetValue() const { return value; }
	void SetValue(TValue val) { value = val; }
private:
	string key;
	TValue value;
};

template<class T>
class TMap
{
public:
	TMap(int size = 0);
	TMap(const TMap<T> &m);
	~TMap();

	int GetCount() const { return count; }
	int GetCapacity() const { return size; }
	bool IsEmpty() const { return count == 0; }
	bool IsFull() const { return count == size; }

	int Add(const string &key, const T &value = T(0));
	void Delete(const string &key);
	bool HasValue(const string &key) const;
	T GetValue(const string &key) const;
	void SetValue(const string &key, const T &value);
	int Find(const string &key) const;

	string GetKeyAt(int idx) const;
	T GetValueAt(int idx) const;
	void SetValueAt(int idx, T value);

	TMap<T> &operator=(const TMap<T> &m);
private:
	int size, count;
	TRecord<T> *rows;
};

template<class T>
TMap<T>::TMap(int size)
{
	this->size = size;
	this->count = 0;
	rows = new TRecord<T>[size];
}

template<class T>
TMap<T>::TMap(const TMap<T> &m)
{
	this->size = m.size;
	this->count = m.size;
	rows = new TRecord<T>[size];
	for (int i = 0; i < count; i++)
		rows[i] =  m.rows[i];
}

template<class T>
TMap<T>::~TMap() {
	delete [] rows;
}

template<class T>
int TMap<T>::Add(const string &key, const T &value)
{
	if (IsFull()) throw;
	int i = Find(key);
	if (i != -1) {
		rows[i].SetValue(value);
		return i;
	}
	rows[count] = TRecord<T>(key, value);
	return count++;
}

template<class T>
void TMap<T>::Delete(const string &key)
{
	int i = Find(key);
	if (i != -1)
		rows[i] = rows[--count];
}

template<class T>
bool TMap<T>::HasValue(const string &key) const {
	return Find(key) != -1;
}

template<class T>
T TMap<T>::GetValue(const string &key) const
{
	int i = Find(key);
	if (i == -1) throw;
	return rows[i].GetValue();
}

template<class T>
void TMap<T>::SetValue(const string &key, const T &value)
{
	int i = Find(key);
	if (i == -1) throw;
	rows[i].SetValue(value);
}

template<class T>
int TMap<T>::Find(const string &key) const
{
	for (int i = 0; i < count; i++) {
		if (rows[i].GetKey() == key)
			return i;
	}
	return -1;
}

template<class T>
string TMap<T>::GetKeyAt(int idx) const
{
	if (idx < 0 || idx >= count) throw;
	return rows[idx].GetKey();
}

template<class T>
T TMap<T>::GetValueAt(int idx) const
{
	if (idx < 0 || idx >= count) throw;
	return rows[idx].GetValue();
}

template<class T>
void SetValueAt(int idx, T value)
{
	if (idx < 0 || idx >= count) throw;
	rows[idx].Setvalue(value);
}

template<class T>
TMap<T> &TMap<T>::operator=(const TMap<T> &m)
{
	if (size != m.size) {
		delete [] rows;
		rows = new TRecord<T>[m.size];
	}
	size = m.size;
	count = m.count;
	for (int i = 0; i < count; i++)
		rows[i] = m.rows[i];
	return *this;
}

#endif _TMAP_H_ // _TMAP_H_