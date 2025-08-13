#include <iostream>
using namespace std;

int main() {
    int arr[100], n, diff;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }

    diff = arr[1] - arr[0];

    for (int i = 0; i < n - 1; i++) {
        if (arr[i + 1] != arr[i] + diff) {
            cout << "Missing number is: " << arr[i] + diff;
            return 0;
        }
    }

    cout << "No missing number found";
    return 0;
}

