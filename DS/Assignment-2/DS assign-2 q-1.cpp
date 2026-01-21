#include<iostream>
using namespace std;
int main(){
    int arr[100],n,i,target;
    cout<<"Enter the no. of elements in your array:"<<endl;
    cin>>n;
    cout<<"Enter the elements:"<<endl;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the element you wish to search:";
    cin>>target;
    int low=0,high=n-1;
    while(low <= high){
        int mid;
        mid = (low + high)/2;
        if(arr[mid] == target){
    cout<<"element found at"<< " " << mid + 1 <<" "<<"position"<<endl;
        break;
        }
        else if(arr[mid] < target){
            low=mid+1;
        }
        else if(arr[mid] > target){
            high=mid-1;
        }

    }
return 0;

}
