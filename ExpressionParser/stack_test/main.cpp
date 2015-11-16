#include "stack.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define SIZE 10

int main()
{
	srand(time((time_t)NULL));
	Stack<int> s(SIZE);

	int arr[SIZE] = { };
	cout << "array: ";
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << ' ';
	}
	
	cout.setf(ios::boolalpha);
	cout << "\nIsEmpty == " << s.IsEmpty() << endl;
	cout << "IsFull == " << s.IsFull() << endl;

	int i = 0;
	while (!s.IsFull()) {
		s.Push(arr[i++]);
		cout << "Top = " << s.Top() << endl;
	}

	Stack<int> s2(s);
	cout << "\ns2: \n";
	while (!s2.IsEmpty()) {
		cout << s2.Pop() << ' ';
	}

	Stack<int> s3(3);
	s3 = s;
	cout << "\ns3: \n";
	while (!s3.IsEmpty()) {
		cout << s3.Pop() << ' ';
	}


	cout << "\n\nIsEmpty == " << s.IsEmpty() << endl;
	cout << "IsFull == " << s.IsFull() << endl;

	while (!s.IsEmpty()) {
		cout << s.Pop() << ' ';
	}

	cout << "\n\nIsEmpty == " << s.IsEmpty() << endl;
	cout << "IsFull == " << s.IsFull() << endl;

	cout << endl;
	system("pause");
	return 0;
};