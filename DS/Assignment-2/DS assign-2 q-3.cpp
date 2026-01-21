#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
        int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the consecutive elements(can be in randomized order): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    bubbleSort(arr,n);

    int start = arr[0];
    int last = arr[n - 1];

    int totalCount = last - start + 1;

    int expectedSum = (totalCount * (start + last)) / 2;

    int actualSum = 0;
    for (int i = 0; i < n; i++) {
        actualSum += arr[i];
    }

    int m = expectedSum - actualSum;

    cout << "Missing Number is: " << m << endl;

    return 0;

}
