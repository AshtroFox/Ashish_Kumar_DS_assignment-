#include <iostream>
using namespace std;

void reverseArray() {
    int arr[100], n, i, temp;
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (i = 0; i < n; i++) cin >> arr[i];
    for (i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    cout << "Reversed array: ";
    for (i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

void matrixMultiplication() {
    int a[10][10], b[10][10], c[10][10], r1, c1, r2, c2, i, j, k;
    cout << "Enter rows and cols of first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and cols of second matrix: ";
    cin >> r2 >> c2;
    if (c1 != r2) {
        cout << "Not possible\n";
        return;
    }
    cout << "Enter first matrix:\n";
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            cin >> a[i][j];
    cout << "Enter second matrix:\n";
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            cin >> b[i][j];
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            c[i][j] = 0;
            for (k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    cout << "Result matrix:\n";
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++)
            cout << c[i][j] << " ";
        cout << "\n";
    }
}

void transposeMatrix() {
    int m[10][10], r, c, i, j;
    cout << "Enter rows and cols: ";
    cin >> r >> c;
    cout << "Enter matrix:\n";
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            cin >> m[i][j];
    cout << "Transpose:\n";
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++)
            cout << m[j][i] << " ";
        cout << "\n";
    }
}

int main() {
    char choice;
    do {
        cout << "a.Reverse array  b.Matrix multiplication  c.Transpose  d.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 'a': reverseArray(); break;
            case 'b': matrixMultiplication(); break;
            case 'c': transposeMatrix(); break;
            case 'd': break;
            default: cout << "Wrong choice\n";
        }
    } while (choice != 'd');
}

