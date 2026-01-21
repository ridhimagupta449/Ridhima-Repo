#include <iostream>
using namespace std;

const int MAX = 100;

void readSparse(int sparse[MAX][3])
{
    int rows, cols, n;
    cout << "Enter rows, cols and number of non-zero elements: ";
    cin >> rows >> cols >> n;

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = n;

    cout << "Enter row, col and value for each non-zero element:\n";
    for (int i = 1; i <= n; i++)
    {
        cin >> sparse[i][0] >> sparse[i][1] >> sparse[i][2];
    }
}
void printSparse(int sparse[MAX][3])
{
    int n = sparse[0][2];
    cout << "Row Col Val\n";
    for (int i = 0; i <= n; i++)
    {
        cout << sparse[i][0] << " "
             << sparse[i][1] << " "
             << sparse[i][2] << endl;
    }
}

// (a) Transpose of sparse matrix
void transpose(int sparse[MAX][3], int result[MAX][3])
{
    int rows = sparse[0][0], cols = sparse[0][1], n = sparse[0][2];

    result[0][0] = cols;
    result[0][1] = rows;
    result[0][2] = n;

    int k = 1;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (sparse[j][1] == i)
            {
                result[k][0] = sparse[j][1];
                result[k][1] = sparse[j][0];
                result[k][2] = sparse[j][2];
                k++;
            }
        }
    }
}

// (b) Addition of two sparse matrices
void addSparse(int A[MAX][3], int B[MAX][3], int result[MAX][3])
{
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1])
    {
        cout << "Matrices cannot be added!\n";
        return;
    }

    int n1 = A[0][2], n2 = B[0][2];
    result[0][0] = A[0][0];
    result[0][1] = A[0][1];

    int i = 1, j = 1, k = 1;

    while (i <= n1 && j <= n2)
    {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1]))
        {
            result[k][0] = A[i][0];
            result[k][1] = A[i][1];
            result[k][2] = A[i][2];
            i++;
            k++;
        }
        else if (B[j][0] < A[i][0] || (A[i][0] == B[j][0] && B[j][1] < A[i][1]))
        {
            result[k][0] = B[j][0];
            result[k][1] = B[j][1];
            result[k][2] = B[j][2];
            j++;
            k++;
        }
        else
        {
            int sum = A[i][2] + B[j][2];
            if (sum != 0)
            {
                result[k][0] = A[i][0];
                result[k][1] = A[i][1];
                result[k][2] = sum;
                k++;
            }
            i++;
            j++;
        }
    }

    while (i <= n1)
    {
        result[k][0] = A[i][0];
        result[k][1] = A[i][1];
        result[k][2] = A[i][2];
        i++;
        k++;
    }

    while (j <= n2)
    {
        result[k][0] = B[j][0];
        result[k][1] = B[j][1];
        result[k][2] = B[j][2];
        j++;
        k++;
    }

    result[0][2] = k - 1;
}

// (c) Multiplication of two sparse matrices
void multiplySparse(int A[MAX][3], int B[MAX][3], int result[MAX][3])
{
    if (A[0][1] != B[0][0])
    {
        cout << "Matrices cannot be multiplied!\n";
        return;
    }

    int n1 = A[0][2], n2 = B[0][2];
    int rows = A[0][0], cols = B[0][1];

    int temp[MAX][3];
    temp[0][0] = rows;
    temp[0][1] = cols;
    int k = 1;

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (A[i][1] == B[j][0])
            {
                int r = A[i][0];
                int c = B[j][1];
                int val = A[i][2] * B[j][2];

                bool found = false;
                for (int x = 1; x < k; x++)
                {
                    if (temp[x][0] == r && temp[x][1] == c)
                    {
                        temp[x][2] += val;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    temp[k][0] = r;
                    temp[k][1] = c;
                    temp[k][2] = val;
                    k++;
                }
            }
        }
    }

    temp[0][2] = k - 1;

    for (int i = 0; i <= temp[0][2]; i++)
    {
        result[i][0] = temp[i][0];
        result[i][1] = temp[i][1];
        result[i][2] = temp[i][2];
    }
}

int main()
{
    int A[MAX][3], B[MAX][3], T[MAX][3], C[MAX][3];

    cout << "Enter first sparse matrix:\n";
    readSparse(A);

    cout << "\nEnter second sparse matrix:\n";
    readSparse(B);

    cout << "\nFirst matrix in triplet form:\n";
    printSparse(A);

    cout << "\nSecond matrix in triplet form:\n";
    printSparse(B);

    // Transpose
    cout << "\nTranspose of first matrix:\n";
    transpose(A, T);
    printSparse(T);

    // Addition
    cout << "\nAddition of matrices:\n";
    addSparse(A, B, C);
    printSparse(C);

    // Multiplication
    cout << "\nMultiplication of matrices:\n";
    multiplySparse(A, B, C);
    printSparse(C);

    return 0;
}
