#include <iostream>
using namespace std;

int main() {
    int a[10][10];
    int rows, cols;

    cout << "Enter rows and cols: ";
    cin >> rows >> cols;

    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> a[i][j];
        }
    }

    // calculating row sums
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += a[i][j];
        }
        cout << "Sum of row " << (i + 1) << " = " << sum << endl;
    }

    // calculating column sums
    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += a[i][j];
        }
        cout << "Sum of col " << (j + 1) << " = " << sum << endl;
    }

    return 0;
}

