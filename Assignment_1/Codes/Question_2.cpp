#include <iostream>
using namespace std;

int main() {
    int arr[100], n, i, j, k;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                for (k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;
                j--;
            }
        }
    }

    cout << "Array after removing duplicates: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

