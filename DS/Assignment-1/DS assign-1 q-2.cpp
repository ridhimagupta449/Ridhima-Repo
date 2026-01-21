#include <iostream>
using namespace std;

int main()
{
    int arr[100];
    int i, j, size, c = 0, p, k;

    cout << "Enter number of students: ";
    cin >> size;

    for (i = 0; i < size; i++)  
    {
        cout << "Enter " << i + 1 << " student marks = ";
        cin >> arr[i];
    }

    for (i = 0; i < size - c; i++)
    {
        for (j = i + 1; j < size - c; j++)
        {
            if (arr[i] == arr[j])
            {
                p = j;
                c = c + 1;

                for (k = p; k < size - c; k++)
                {
                    arr[k] = arr[k + 1];
                }

                j = j - 1; 
            }
        }
    }

    cout << "\nArray after removing duplicates: ";
    for (i = 0; i < size - c; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

