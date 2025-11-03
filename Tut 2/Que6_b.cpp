#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

void printSparse(Element arr[], int n) {
    cout << "Row Col Value\n";
    for (int i = 0; i < n; i++)
        cout << arr[i].row << "   " << arr[i].col << "   " << arr[i].val << endl;
}

void addSparse(Element a[], int n, Element b[], int m, Element result[], int &k) {
    k = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            result[k++] = a[i++];
        } else if (a[i].row > b[j].row || (a[i].row == b[j].row && a[i].col > b[j].col)) {
            result[k++] = b[j++];
        } else {
            int sum = a[i].val + b[j].val;
            if (sum != 0) {
                result[k].row = a[i].row;
                result[k].col = a[i].col;
                result[k].val = sum;
                k++;
            }
            i++;
            j++;
        }
    }
    while (i < n) // Remaining from a
        result[k++] = a[i++];
    while (j < m) // Remaining from b
        result[k++] = b[j++];
}

int main() {
    int r1, c1, n1;
    cout << "Enter rows, cols and non-zero elements of first sparse matrix: ";
    cin >> r1 >> c1 >> n1;
    Element a[n1];
    cout << "Enter row, col, value of non-zero elements for first matrix:\n";
    for (int i = 0; i < n1; i++)
        cin >> a[i].row >> a[i].col >> a[i].val;

    int r2, c2, n2;
    cout << "Enter rows, cols and non-zero elements of second sparse matrix: ";
    cin >> r2 >> c2 >> n2;
    Element b[n2];
    cout << "Enter row, col, value of non-zero elements for second matrix:\n";
    for (int i = 0; i < n2; i++)
        cin >> b[i].row >> b[i].col >> b[i].val;

    if (r1 != r2 || c1 != c2) {
        cout << "Matrix dimensions must be same for addition.\n";
        return 0;
    }

    Element result[n1 + n2];
    int k;
    addSparse(a, n1, b, n2, result, k);

    cout << "\nResultant Sparse Matrix after addition:\n";
    printSparse(result, k);

    return 0;
}
