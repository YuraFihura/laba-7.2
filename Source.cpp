#include <iostream>
#include <iomanip>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low = 0, const int High = 20);

void Print(int** a, const int rowCount, const int colCount);
bool SearchMaxMinElem(int** a, const int rowCount, const int colCount, int& maxElem);
bool SearchMinMaxElem(int** a, const int colCount, const int rowCount, int& minElem);
void Change(int** a, const int rowCount, const int colCount);

int main()
{
	srand((unsigned)time(NULL));

	int n, k;
	cout << "k(row) = "; cin >> k;
	cout << "n(col) = "; cin >> n;

	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];

	Create(a, k, n);
	Change(a, k, n);
	Print(a, k, n);

	int maxElem;
	if (SearchMaxMinElem(a, k, n, maxElem))
		cout << "max from min elem = " << maxElem << endl;

	int minElem;
	if (SearchMinMaxElem(a, k, n, minElem))
		cout << "min from max elem = " << minElem << endl;

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}

void Create(int** a, const int colCount, const int rowCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int colCount, const int rowCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}


bool SearchMaxMinElem(int** a, const int colCount, const int rowCount, int& minElem)
{
	int min_index = 0;
	for (int i = 0; i < rowCount; i++)
	{
		if (a[i][0] < a[min_index][0])
		{
			min_index = i;
		}
	}
	minElem = a[min_index][0];

	for (int j = 0; j < colCount; j += 2)
	{
		int min_index = 0;
		for (int i = 0; i < rowCount; i++)
			if (a[i][j] < a[min_index][j])
				min_index = i;

		cout << "min[" << min_index << "][" << j << "] = " << a[min_index][j] << endl;
		if (a[min_index][j] > minElem)
			minElem = a[min_index][j];
	}

	return true;
}

bool SearchMinMaxElem(int** a, const int colCount, const int rowCount, int& maxElem)
{
	int max_index = 0;
	for (int i = 0; i < rowCount; i++)
	{
		if (a[i][0] < a[max_index][0])
		{
			max_index = i;
		}
	}
	maxElem = a[max_index][0];

	for (int j = 1; j < colCount; j += 2)
	{
		int max_index = 0;
		for (int i = 0; i < rowCount; i++)
			if (a[i][j] < a[max_index][j])
				max_index = i;

		cout << "max[" << max_index << "][" << j << "] = " << a[max_index][j] << endl;
		if (a[max_index][j] < maxElem)
			maxElem = a[max_index][j];
	}

	return true;
}

void Change(int** a, const int rowCount, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		for (int i = 0; i < rowCount; i++)
		{
			int max_index = 0, min_index = 0;
			tmp = a[max_index][j];
			a[max_index][j] = a[min_index][j];
			a[min_index][j] = tmp;
		}
	}
}

