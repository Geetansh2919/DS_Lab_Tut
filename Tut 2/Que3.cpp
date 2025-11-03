#include<iostream>
using namespace std;

int main(){
    int arr[10],test[11]={};
    int x,j;
    cout<<"\nEnter highest number: ";
    cin>>x;

    cout<<"\nEnter the "<<x-1<<" elements: ";
    for(int i=0;i<x-1;i++){
        cin>>arr[i];
    }
    for(int j=0;j<x-1;j++){
        int i;
        i=arr[j];
        test[i]++;
        
    }
   for(j=1;j<x+1;j++){
    cout<<test[j]<<endl;
    if(test[j]==0){
        cout<<j;
    }
   }
    return 0;
}

