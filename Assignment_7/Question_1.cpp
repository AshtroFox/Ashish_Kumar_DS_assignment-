#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
    int i, j, minIndex, t;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) minIndex = j;
        }
        t = a[i];
        a[i] = a[minIndex];
        a[minIndex] = t;
    }
}

void insertionSort(int a[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void bubbleSort(int a[], int n) {
    int i, j, t;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

void merge(int a[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1, n2 = r - m;
    int L[100], R[100];

    for (i = 0; i < n1; i++) L[i] = a[l + i];
    for (j = 0; j < n2; j++) R[j] = a[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int partitionArr(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1, t, j;
    for (j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            t = a[i]; a[i] = a[j]; a[j] = t;
        }
    }
    t = a[i + 1]; a[i + 1] = a[high]; a[high] = t;
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partitionArr(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main() {
    int n, i, ch, a[100];
    cout << "\Enter the number of elements";
    cin >> n;
    
    cout << "\nEnter the elements\n";
    for (i = 0; i < n; i++) cin >> a[i];
	cout << "\n1 - Selection\n2 Insertion\n3 Bubble\n4 Merge\n5 Quick";
    cin >> ch;

    if (ch == 1) selectionSort(a, n);
    else if (ch == 2) insertionSort(a, n);
    else if (ch == 3) bubbleSort(a, n);
    else if (ch == 4) mergeSort(a, 0, n - 1);
    else if (ch == 5) quickSort(a, 0, n - 1);

    for (i = 0; i < n; i++) cout << a[i] << " ";
}

