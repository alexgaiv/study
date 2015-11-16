#include "map.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define SIZE 8

string keys[SIZE] = { "abc", "derp", "*", "1", "step", "max", "+", "/" };

template<class T>
void PrintMap(const Map<T> &m)
{
	for (int i = 0; i < m.GetCount(); i++) {
		string &s = keys[i];
		cout << s << ' ' << m.GetValue(s) << endl;
	}
	cout << endl;
}

int main()
{
	srand(time((time_t)NULL));
	Map<int> m(SIZE);

	cout << "count = " <<  m.GetCount() << endl;
	cout << "capacity = " <<  m.GetCapacity() << endl;

	cout << "is full = " << boolalpha << m.IsFull() << endl;
	cout << "is empty = " << boolalpha << m.IsEmpty() << endl;

	string keys[SIZE] = { "abc", "derp", "*", "1", "step", "max", "+", "/" };
	
	int i = 0;
	while (!m.IsFull()) {
		string &s = keys[i];
		m.Add(s, rand() % 100);
		cout << s << ' ' << m.GetValue(s) << endl;
		i++;
	}

	m.SetValue("*", 5);
	cout << m.GetValue("*") << "\n\n";

	Map<int> m2(m);
	Map<int> m3;
	m3 = m;

	PrintMap(m2);
	PrintMap(m3);

	i = 0;
	while (!m.IsEmpty()) {
		string &s = keys[i];
		m.Delete(s);
		cout << m.GetCount() << endl;
		i++;
	}

	cout << "count = " <<  m.GetCount() << endl;
	cout << "capacity = " <<  m.GetCapacity() << endl;

	cout << "is full = " << boolalpha << m.IsFull() << endl;
	cout << "is empty = " << boolalpha << m.IsEmpty() << endl;

	system("pause");
	return 0;
}