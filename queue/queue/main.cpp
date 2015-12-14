#include <iostream>
#include "queue.h"
#include <math.h>
using namespace std;

#define ARR_SIZE 6

void Sort(int arr[ARR_SIZE], int maxDigits)
{
	Queue<int> *qs = new Queue<int>[10];

	for (int d = 0; d < maxDigits; d++) {
		for (int i = 0; i < ARR_SIZE; i++) {
			int digit = (arr[i] / (int)pow(10, d)) % 10;
			qs[digit].Push(arr[i]);
		}

		int k = 0;
		for (int i = 0; i < 10; i++) {
			while (!qs[i].IsEmpty()) {
				arr[k++] = qs[i].Pop();
			}
		}
		k++;
	}

	delete [] qs;
}


int main()
{
	int arr[ARR_SIZE] = { 1234, 5663, 6783, 3577, 6234, 5731 };
	int arr_new[ARR_SIZE] = {  };

	for (int i = 0; i < ARR_SIZE; i++)
		cout << arr[i] << ' ';
	cout << endl;

	Sort(arr, 4);

	for (int i = 0; i < ARR_SIZE; i++)
		cout << arr_new[i] << ' ';
	cout << endl;

	system("pause");
	return 0;
}