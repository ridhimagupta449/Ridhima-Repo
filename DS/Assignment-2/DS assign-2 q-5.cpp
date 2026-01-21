#include <iostream>
using namespace std;

 //(a) Diagonal Matrix
class DiagonalMatrix
{
    int n;
    int *arr;

public:
    DiagonalMatrix(int size)
    {
        n = size;
        arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = 0;
    }
    void set(int i, int j, int val)
    {
        if (i == j)
            arr[i - 1] = val;
    }
    int get(int i, int j)
    {
        if (i == j)
            return arr[i - 1];
        return 0;
    }
    void display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
    ~DiagonalMatrix() { delete[] arr; }
};


// (b) Tri-diagonal Matrix

class TriDiagonalMatrix
{
    int n;
    int *arr;

public:
    TriDiagonalMatrix(int size)
    {
        n = size;
        arr = new int[3 * n - 2];
        for (int i = 0; i < 3 * n - 2; i++)
            arr[i] = 0;
    }
    int index(int i, int j)
    {
        if (i - j == 1)
            return i - 2; // below diagonal
        else if (i == j)
            return (n - 1) + (i - 1); // main diagonal
        else if (j - i == 1)
            return (2 * n - 1) + (i - 1); // above diagonal
        return -1;
    }
    void set(int i, int j, int val)
    {
        int k = index(i, j);
        if (k != -1)
            arr[k] = val;
    }
    int get(int i, int j)
    {
        int k = index(i, j);
        if (k != -1)
            return arr[k];
        return 0;
    }
    void display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
    ~TriDiagonalMatrix() { delete[] arr; }
};


// (c) Lower Triangular Matrix

class LowerTriangularMatrix
{
    int n;
    int *arr;

public:
    LowerTriangularMatrix(int size)
    {
        n = size;
        arr = new int[n * (n + 1) / 2];
        for (int i = 0; i < n * (n + 1) / 2; i++)
            arr[i] = 0;
    }
    int index(int i, int j)
    {
        if (i >= j)
            return (i * (i - 1)) / 2 + (j - 1);
        return -1;
    }
    void set(int i, int j, int val)
    {
        int k = index(i, j);
        if (k != -1)
            arr[k] = val;
    }
    int get(int i, int j)
    {
        int k = index(i, j);
        if (k != -1)
            return arr[k];
        return 0;
    }
    void display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
    ~LowerTriangularMatrix() { delete[] arr; }
};


// (d) Upper Triangular Matrix

class UpperTriangularMatrix
{
    int n;
    int *arr;

public:
    UpperTriangularMatrix(int size)
    {
        n = size;
        arr = new int[n * (n + 1) / 2];
        for (int i = 0; i < n * (n + 1) / 2; i++)
            arr[i] = 0;
    }
    int index(int i, int j)
    {
        if (i <= j)
            return (j * (j - 1)) / 2 + (i - 1);
        return -1;
    }
    void set(int i, int j, int val)
    {
        int k = index(i, j);
        if (k != -1)
            arr[k] = val;
    }
    int get(int i, int j)
    {
        int k = index(i, j);
        if (k != -1)
            return arr[k];
        return 0;
    }
    void display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
    ~UpperTriangularMatrix() { delete[] arr; }
};


// (e) Symmetric Matrix

class SymmetricMatrix
{
    int n;
    int *arr;

public:
    SymmetricMatrix(int size)
    {
        n = size;
        arr = new int[n * (n + 1) / 2];
        for (int i = 0; i < n * (n + 1) / 2; i++)
            arr[i] = 0;
    }
    int index(int i, int j)
    {
        if (i >= j)
            return (i * (i - 1)) / 2 + (j - 1);
        else
            return (j * (j - 1)) / 2 + (i - 1);
    }
    void set(int i, int j, int val)
    {
        int k = index(i, j);
        arr[k] = val;
    }
    int get(int i, int j)
    {
        int k = index(i, j);
        return arr[k];
    }
    void display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
    ~SymmetricMatrix() { delete[] arr; }
};
int main()
{
    cout << "Diagonal Matrix Example:\n";
    DiagonalMatrix dm(4);
    dm.set(1, 1, 5);
    dm.set(2, 2, 8);
    dm.set(3, 3, 9);
    dm.set(4, 4, 12);
    dm.display();

    cout << "\nTri-Diagonal Matrix Example:\n";
    TriDiagonalMatrix tdm(4);
    tdm.set(1, 1, 2);
    tdm.set(1, 2, 3);
    tdm.set(2, 1, 4);
    tdm.set(2, 2, 5);
    tdm.set(2, 3, 6);
    tdm.display();

    cout << "\nLower Triangular Matrix Example:\n";
    LowerTriangularMatrix ltm(4);
    ltm.set(2, 1, 7);
    ltm.set(3, 2, 9);
    ltm.set(4, 4, 11);
    ltm.display();

    cout << "\nUpper Triangular Matrix Example:\n";
    UpperTriangularMatrix utm(4);
    utm.set(1, 1, 1);
    utm.set(1, 3, 5);
    utm.set(2, 4, 7);
    utm.display();

    cout << "\nSymmetric Matrix Example:\n";
    SymmetricMatrix sm(4);
    sm.set(1, 1, 1);
    sm.set(2, 1, 2);
    sm.set(2, 2, 3);
    sm.set(3, 1, 4);
    sm.set(3, 3, 5);
    sm.set(4, 4, 6);
    sm.display();

    return 0;
}
