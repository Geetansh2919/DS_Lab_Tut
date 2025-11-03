#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;
    int size = n * (n + 1) / 2;
    int arr[size];
    cout << "Enter non-zero elements (" << size << " elements):\n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j)
                cout << arr[i * n - (i * (i - 1)) / 2 + (j - i)] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}
