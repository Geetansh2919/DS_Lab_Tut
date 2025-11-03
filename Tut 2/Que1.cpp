#include<iostream>
using namespace std;

int main(){
    int arr[10];
    int first,last,mid;
    int x,key;

    
    cout<<"Specify the number of elements: ";
    cin>>x;
    cout<<"Enter the integers in the Array: ";
    for(int i=0;i<x;i++){
        cin>>arr[i];
    }
    
    cout<<"The Array created is: ";
    for(int i=0;i<x;i++){
        cout<<arr[i]<<" ";
    }
    
    
    cout<<"\nEnter the element you want to search: ";
    cin>>key;
    first=0;
    last=x-1;

    while(first<=last){
         mid=(first+last)/2;
        if(arr[mid]==key){
            cout<<"Element found at: "<<mid+1;
            break;
        }else if(arr[mid]>key){
            last=mid-1;
        }else {
            first=mid+1;
        }
        }
    

    return 0;
}