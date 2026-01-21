#include<iostream>
using namespace std;
int main(){
    int n, arr[100], count=0, i, k, j, c=0, p;
    cout<<"Enter the no. of elements in your array:";
    cin>>n;
    cout<<"Enter the elements in your array:"<<endl;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }   
    
    for (i = 0; i < n - c; i++)
    {
        for (j = i + 1; j < n - c; j++)
        {
            if (arr[i] == arr[j])
            {
                p = j;
                c = c + 1;

                for (k = p; k < n - c; k++)
                {
                    arr[k] = arr[k + 1];
                }

                j = j - 1; 
            }
        }
    }

    for(i=0;i<n-c;i++){
        for(j=i+1;j<n-c;j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    cout<<"\nNumber of distinct elements are: "<<n-c;

    return 0;
}

