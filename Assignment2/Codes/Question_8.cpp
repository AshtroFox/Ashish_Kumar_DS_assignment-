#include <iostream>
using namespace std;

int main() {
    int arr[100], n, count = 0;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] == arr[j]) {
				count++;
            }
        }

    }

    cout << "distinct elements = " << n-count;
    return 0;
}

