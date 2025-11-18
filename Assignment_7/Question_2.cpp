#include <iostream>
using namespace std;

void improvedSelection(int a[], int n) {
    int left = 0, right = n - 1;
    int minIndex, maxIndex, i, t;

    while (left < right) {
        minIndex = left;
        maxIndex = right;

        for (i = left; i <= right; i++) {
            if (a[i] < a[minIndex]) minIndex = i;
            if (a[i] > a[maxIndex]) maxIndex = i;
        }

        t = a[left];
        a[left] = a[minIndex];
        a[minIndex] = t;

        if (maxIndex == left) maxIndex = minIndex;

        t = a[right];
        a[right] = a[maxIndex];
        a[maxIndex] = t;

        left++;
        right--;
    }
}

int main() {
    int n, a[100], i;
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];

    improvedSelection(a, n);

    for (i = 0; i < n; i++) cout << a[i] << " ";
}

