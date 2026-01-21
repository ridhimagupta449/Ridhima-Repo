/*You are given a 1D array that may contain both positive and negative integers, and find
the sum of a contiguous subarray of numbers which has the largest sum. For example, if
the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7.*/
#include <iostream>
using namespace std;
void Traversal(int A[], int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        cout << A[i] << " ";
    }
}
int Sub_arr(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int sum = A[i];
        int maxel = A[i];
        for (int j = i + 1; j < n; j++)
        {
            sum = sum + A[j];
            maxel = max(maxel, A[j]);
            if (sum > maxel)
            {
                Traversal(A, i, j);
                cout << endl
                     << sum;
                return 0;
            }
        }
    }

    return -1;
}
int main()
{
    int B[8] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(B) / sizeof(B[0]);
    int result = Sub_arr(B, n);
    if (result == -1)
        cout << "No subarray found";
    return 0;
}