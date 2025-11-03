#include <iostream>
using namespace std;

int missingNumber(int arr[], int n) {
    int left = 0, right = n - 2; 
    
    if (arr[0] != 1)
        return 1;
    
    if (arr[n - 2] != n)
        return n;

    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == mid + 1)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return left + 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8}; 
    int n = sizeof(arr) / sizeof(arr[0]) + 1; 
    cout << "Missing number is: " << missingNumber(arr, n) << endl;
    return 0;
}
