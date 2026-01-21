/*A slightly improved selection sort – We know that selection sort algorithm takes the minimum on
every pass on the array, and place it at its correct position. The idea is to take also the maximum on
every pass and place it at its correct position. So in every pass, we keep track of both maximum and
minimum and array becomes sorted from both ends. Implement this logic.*/
#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n)
{
    int left = 0, right = n - 1;

    while (left < right)
    {
        int minIndex = left;
        int maxIndex = right;

        for (int i = left; i <= right; i++)
        {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        int temp = arr[left];
        arr[left] = arr[minIndex];
        arr[minIndex] = temp;

        if (maxIndex == left)
            maxIndex = minIndex;

        temp = arr[right];
        arr[right] = arr[maxIndex];
        arr[maxIndex] = temp;

        left++;
        right--;
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    improvedSelectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
