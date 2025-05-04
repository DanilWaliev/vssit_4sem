#include <iostream>
using namespace std;
extern "C" int MODIFY_ARRAY(int*, int);
extern "C" int GET_RANDOM();

int main() 
{
	setlocale(LC_CTYPE, "Russian");
	int* initialArray = nullptr;
	int i = 0, numberOfReplaces = 0, numberOfElements = 0;

	cout << "Количество элементов массива: ";
	cin >> numberOfElements;

	initialArray = new int[numberOfElements];

	for (i = 0; i < numberOfElements; i++) {
		initialArray[i] = GET_RANDOM();
	}

	cout << "Было: ";
	for (i = 0; i < numberOfElements; i++) {
		cout << initialArray[i] << " ";
	}
	cout << endl;

	numberOfReplaces = MODIFY_ARRAY(initialArray, numberOfElements);
	cout << "Стало: ";
	for (i = 0; i < numberOfElements; i++) {
		cout << initialArray[i] << " ";
	}
	cout << endl;

	cout << "Количество замен: " << numberOfReplaces << endl;
	free(initialArray);
	initialArray = nullptr;
	system("pause");
}