#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

void printSparseMatrix(Element arr[], int n, int r, int c) {
    cout << "Row Col Value\n";
    for (int i = 0; i < n; i++)
        cout << arr[i].row << "   " << arr[i].col << "   " << arr[i].val << endl;
}

void transpose(Element arr[], int n, Element trans[], int r, int c) {
    int k = 0;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j].col == i) {
                trans[k].row = arr[j].col;
                trans[k].col = arr[j].row;
                trans[k].val = arr[j].val;
                k++;
            }
        }
    }
}

int main() {
    int rows, cols, nonZero;
    cout << "Enter rows, cols and number of non-zero elements: ";
    cin >> rows >> cols >> nonZero;

    Element arr[nonZero];
    cout << "Enter row, col, value of non-zero elements:\n";
    for (int i = 0; i < nonZero; i++)
        cin >> arr[i].row >> arr[i].col >> arr[i].val;

    cout << "\nOriginal Sparse Matrix (Triplet format):\n";
    printSparseMatrix(arr, nonZero, rows, cols);

    Element trans[nonZero];
    transpose(arr, nonZero, trans, rows, cols);

    cout << "\nTranspose of Sparse Matrix:\n";
    printSparseMatrix(trans, nonZero, cols, rows);

    return 0;
}
