#include <iostream>
using namespace std;

void createArray(int arr[], int &n) {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void insertElement(int arr[], int &n) {
    int pos, val;
    cout << "Enter pos and value: ";
    cin >> pos >> val;
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    n++;
}

void deleteElement(int arr[], int &n) {
    int pos;
    cout << "Enter pos: ";
    cin >> pos;
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void linearSearch(int arr[], int n) {
    int key;
    cout << "Enter value to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Found at position " << i + 1 << "\n";
            return;
        }
    }
    cout << "Not found\n";
}

int main() {
    int arr[100], n = 0, choice;
    do {
        cout << "1.CREATE 2.DISPLAY 3.INSERT 4.DELETE 5.SEARCH 6.EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: createArray(arr, n); break;
            case 2: displayArray(arr, n); break;
            case 3: insertElement(arr, n); break;
            case 4: deleteElement(arr, n); break;
            case 5: linearSearch(arr, n); break;
            case 6: break;
            default: cout << "Wrong choice\n";
        }
    } while (choice != 6);
}

