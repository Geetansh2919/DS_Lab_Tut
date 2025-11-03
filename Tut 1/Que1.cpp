#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void createArray(int arr[], int &n) 
{
	cout << "Enter number of elements: ";
	cin >> n;
	if (n > MAX_SIZE || n < 1) 
    {
		cout << "Invalid size!\n";
		n = 0;
		return;
	}
	cout << "Enter elements: ";
	for (int i = 0; i < n; ++i) 
    {
		cin >> arr[i];
	}
}

void displayArray(int arr[], int n) 
{
	if (n == 0) 
    {
		cout << "Array is empty!\n";
		return;
	}
	cout << "Array elements: ";
	for (int i = 0; i < n; ++i)
    {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void insertElement(int arr[], int &n) 
{
	if (n >= MAX_SIZE) 
    {
		cout << "Array is full!\n";
		return;
	}
	int pos, val;
	cout << "Enter position to insert (1 to " << n+1 << "): ";
	cin >> pos;
	if (pos < 1 || pos > n+1) 
    {
		cout << "Invalid position!\n";
		return;
	}
	cout << "Enter value to insert: ";
	cin >> val;
	for (int i = n; i >= pos; --i) 
    {
		arr[i] = arr[i-1];
	}
	arr[pos-1] = val;
	++n;
	cout << "Element inserted.\n";
}

void deleteElement(int arr[], int &n) 
{
	if (n == 0) 
    {
		cout << "Array is empty!\n";
		return;
	}
	int pos;
	cout << "Enter position to delete (1 to " << n << "): ";
	cin >> pos;
	if (pos < 1 || pos > n) 
    {
		cout << "Invalid position!\n";
		return;
	}
	for (int i = pos-1; i < n-1; ++i) 
    {
		arr[i] = arr[i+1];
	}
	--n;
	cout << "Element deleted.\n";
}

void linearSearch(const int arr[], int n) 
{
	if (n == 0) 
    {
		cout << "Array is empty!\n";
		return;
	}
	int key, found = 0;
	cout << "Enter value to search: ";
	cin >> key;
	for (int i = 0; i < n; ++i) 
    {
		if (arr[i] == key) 
        {
			cout << "Found at position " << (i+1) << endl;
			found = 1;
		}
	}
	if (found==0) cout << "Not found!\n";
}

int main() 
{
	int arr[MAX_SIZE], n = 0, choice;
	do {
		cout << "\n——MENU——-\n";
		cout << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) 
        {
			case 1: createArray(arr, n); break;
			case 2: displayArray(arr, n); break;
			case 3: insertElement(arr, n); break;
			case 4: deleteElement(arr, n); break;
			case 5: linearSearch(arr, n); break;
			case 6: cout << "Exiting...\n"; break;
			default: cout << "Invalid choice!\n";
		}
	} while (choice != 6);
	return 0;
}
