/*Implement Merge sort for the given array int arr[] = {12, 11, 13, 5, 6, 7}. After implementing
Merge Sort, apply the same implementation to sort another array: int arr2[] = {38, 27, 43,
3, 9, 82, 10}.*/
#include <iostream>
using namespace std;
void merge(int a[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[100], R[100];
    for (int i = 0; i < n1; i++)
        L[i] = a[p + i];
    for (int j = 0; j < n1; j++)
        R[j] = a[q + 1 + j];
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];
}
void mergesort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergesort(a, p, q);
        mergesort(a, q + 1, r);
        merge(a, p, q, r);
    }
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    cout << "Array before sorting:- ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergesort(arr, 0, 5);
    cout << "Array after Merge Sort:- ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "\n";

    int arr1[] = {38, 27, 43, 3, 9, 82, 10};
    cout << "Array before sorting:- ";
    for (int i = 0; i < 7; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    mergesort(arr1, 0, 6);
    cout << "Array after Merge Sort:- ";
    for (int i = 0; i < 7; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    return 0;
}