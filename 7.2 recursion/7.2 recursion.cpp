#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCout, const int colCout, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCout, const int colCout, int i, int j);
int sum(int** a, const int rowCount, const int colCount, int j, int s);

int main()
{
	srand((unsigned)time(NULL));

	int Low, High, rowCount, colCount;
	cout << "Low = "; cin >> Low;
	cout << "High = "; cin >> High;
	cout << "rowcount (k) = "; cin >> rowCount;
	cout << "colCount (n) = "; cin >> colCount;


	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);

	cout << "max sum = " << sum(a, rowCount, colCount, 1, 0) << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}

int sum(int** a, const int rowCount, const int colCount, int j, int s)
{
	if (j < colCount)
	{
		int max = a[0][j];
		for (int i = 1; i < rowCount; i++)
		{
			if (a[i][j] > max)
				max = a[i][j];
		}
		sum(a, rowCount, colCount, j += 2, s += max);
	}
	else
		return s;
}
