#include<iostream>
using namespace std;

int main(){
    int n;
    int arr[10];
    int test[11];

    cout<<"Enter the highest number: ";
    cin>>n;
    cout<<"Enter "<<n-1<<" number: ";

    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }

    for(int j=0;j<=n;j++){
        test[j]=j+1;
    }
    
    for(int i=0;i<+n;i++){
        if(arr[i]!=test[i]){
            cout<<"The number missing is: "<<i+1;
        }
    }
}