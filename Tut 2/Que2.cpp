#include<iostream>
using namespace std;    

//Bubble Sort Function
int x;
void inputArray(int arr[]){
    cout<<"Specify the number of elements: ";
    cin>>x;
    cout<<"Enter the integers in the Array: ";
    for(int i=0; i<x; i++){ 
        cin>>arr[i];
    }
}

void displayArray(int arr[]){
    cout<<"The Array created is: ";
    for(int i=0; i<x; i++){
        cout<<arr[i]<<" ";
    }  
}

void bubbleSort(int arr[]){
    int temp;
    for(int i=0;i<x;i++){
        for(int j=0;j<x-i+1;j++){
            if(arr[j+1]>arr[j]){
             temp=arr[j+1]   ;
             arr[j+1]=arr[j];
             arr[j]=temp;
            }
        }
    }
}

void binarySearch(int arr[]){
    int first, last, mid;
    int  key;
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
}

int main(){
    int choice;
    int arr[10];
    do{
    cout<<"Choose from following options: \n";
    cout<<"1. Input the Array\n";
    cout<<"2. Display the Array\n";
    cout<<"3. Bubble Sort the Array\n";
    cout<<"4. Search an element in Array\n";
    cout<<"5. Exit\n";

    
    cout<<"\nEnter your choice: ";
    cin>>choice;   
    switch(choice){
        case 1:
            inputArray(arr );
            break;
        case 2:
            displayArray(arr);
            break;
        case 3:
            bubbleSort(arr);
            cout<<"Array after Bubble Sort: ";
            displayArray(arr);
            break;
        case 4:
            binarySearch(arr); 
            break;
        case 5:
            cout<<"Exiting the program.";
            break;
        default:
            cout<<"Invalid choice!";
    }
}while(choice!=5);
    return 0;

}