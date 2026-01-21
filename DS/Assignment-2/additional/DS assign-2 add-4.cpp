#include<iostream>
using namespace std;
int main(){
int n,arr[n],i;
cout<<"\nEnter the number of elements=";
cin>>n;
cout<<"\nEnter elements(only 0,1,2)=";
     for(i=0;i<n;i++){   
       cin>>arr[i];
   }
   int low=0,mid=0,high=n-1;
   while(mid<=high){
   	if(arr[mid]==0){
   		swap(arr[low], arr[mid]);
            low++;
            mid++;
	   }
	   else if(arr[mid]==1){
	   	mid++;
	   }
	   else{
	   	swap(arr[mid], arr[high]);
	   	high--;
	   }
   }
   cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
	 return 0;	
	
}
