#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of tridiagonal matrix: ";
    cin >> n;
    int size = 3 * n - 2;
    int arr[size];
    cout << "Enter tridiagonal elements (" << size << " elements):\n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << arr[n - 1 + i] << " ";
            else if (i - j == 1)
                cout << arr[i - 1] << " ";
            else if (j - i == 1)
                cout << arr[2 * n - 1 + i] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}
