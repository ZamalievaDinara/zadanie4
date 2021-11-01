#include <iostream>
using namespace std;

void fillArray(int* array, const int size, const int step, const int firstElement)
{
	array[0] = firstElement;
	for (int i = 1; i < size; i++)
		array[i] = array[i - 1] + step;
}

int randomElement(const int from, const int to)
{
	return from + rand() % (to - from + 1);
}

void rndFillArray(int* array, const int size)
{
	fillArray(array, size, 1, 1);

	int swapValue, swapIndex;

	for (int j = size; j > 1; j--)
	{
		swapIndex = randomElement(0, j);
		swapValue = array[j - 1];
		array[j - 1] = array[swapIndex];
		array[swapIndex] = swapValue;
	}
}

void rndFillArray3(int* array, const int size)
{
	for (int i = 0; i < size; i++)
		array[i] = randomElement(1000, 2000);
}

int countElements(const int* array, const int size)
{
	int cnt = 0;
	for (int i = 0; i < size; i++)
		if ((array[i] / 10) % 2 == 0)
			cnt++;
	return cnt;
}

void printArray(const int* array, const int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	std::srand(std::time(nullptr));

	int N;
	cout << "Введите колличество элементов массива: ";
	cin >> N; 
	int* array = new int[N];
	int step;
	cout << "Введите шаг арифметической прогрессии: ";
	cin >> step;
	int firstElement;
	cout << "Введите первый элемент арифметической прогрессии: ";
	cin >> firstElement;

	fillArray(array, N, step, firstElement);
	cout << "Арифметическая прогрессия: " << endl;
	printArray(array, N);
	delete[] array;

	cout << "Введите колличество элементов массива: ";
	cin >> N;
	array = new int[N];

	rndFillArray(array, N);
	printArray(array, N);
	delete[] array;

	
	cout << "Введите колличество элементов массива: ";
	cin >> N;
	array = new int[N];

	rndFillArray3(array, N);
	printArray(array, N);
	cout << "Колличество элементов, где вторая с конца цифра - четная:" << countElements(array, N) << endl;
	delete[] array;

	return 0;
}
