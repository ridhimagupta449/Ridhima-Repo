/*Consider an array arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91} and use Binary Search to find
the target 23*/
#include <iostream>
using namespace std;
int main()
{
    int t, arr[100], n, i;
    cout << "Enter size of your array:";
    cin >> n;
    cout << "Enter the elements of array:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter target element:";
    cin >> t;
    int l = 0, r = n - 1, mid;
    while (1 <= r)
    {
        mid = (1 + r) / 2;
        if (arr[mid] = t)
        {
            cout << "Element found at position " << mid + 1;
            break;
        }
        else if (arr[mid] < t)
        {
            l = mid + 1;
        }
        else if (arr[mid] > t)
        {
            r = mid - 1;
        }
    }
    return 0;
}