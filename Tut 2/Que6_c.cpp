#include <iostream>
#include <vector>
using namespace std;

struct Element {
    int row, col, val;
};

void printSparse(Element arr[], int n) {
    cout << "Row Col Value\n";
    for (int i = 0; i < n; i++)
        cout << arr[i].row << "   " << arr[i].col << "   " << arr[i].val << endl;
}

int main() {
    int r1, c1, n1;
    cout << "Enter rows, cols and non-zero elements of first matrix: ";
    cin >> r1 >> c1 >> n1;
    Element a[n1];
    cout << "Enter row, col, value for first matrix:\n";
    for (int i = 0; i < n1; i++)
        cin >> a[i].row >> a[i].col >> a[i].val;

    int r2, c2, n2;
    cout << "Enter rows, cols and non-zero elements of second matrix: ";
    cin >> r2 >> c2 >> n2;
    Element b[n2];
    cout << "Enter row, col, value for second matrix:\n";
    for (int i = 0; i < n2; i++)
        cin >> b[i].row >> b[i].col >> b[i].val;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible due to dimension mismatch.\n";
        return 0;
    }

    // Use map to accumulate values for result matrix entries
    // Key: pair(row, col), Value: sum product
    vector<Element> result;
    // Multiply only when column of A = row of B
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (a[i].col == b[j].row) {
                int row = a[i].row;
                int col = b[j].col;
                int val = a[i].val * b[j].val;

                // Search if element exists in result
                bool found = false;
                for (int k = 0; k < (int)result.size(); k++) {
                    if (result[k].row == row && result[k].col == col) {
                        result[k].val += val;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    Element e = {row, col, val};
                    result.push_back(e);
                }
            }
        }
    }

    cout << "\nResultant Sparse Matrix after multiplication:\n";
    cout << "Row Col Value\n";
    for (auto &e : result)
        cout << e.row << "   " << e.col << "   " << e.val << endl;

    return 0;
}
