#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void MoveMaxEvenRowsToDiagonal(int** a, const int n);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -10, High = 20;
    int n;
    cout << "n = "; cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High);
    cout << "Original matrix:" << endl;
    Print(a, n);

    MoveMaxEvenRowsToDiagonal(a, n);

    cout << "Modified matrix (max of even rows on diagonal):" << endl;
    Print(a, n);

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(5) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int MaxIndexRow(int* row, const int n)
{
    int idx = 0;
    for (int j = 1; j < n; j++)
        if (row[j] > row[idx])
            idx = j;
    return idx;
}

void MoveMaxEvenRowsToDiagonal(int** a, const int n)
{
    for (int i = 0; i < n; i += 2)
    {
        int maxCol = MaxIndexRow(a[i], n);
        swap(a[i][i], a[i][maxCol]);
    }
}
