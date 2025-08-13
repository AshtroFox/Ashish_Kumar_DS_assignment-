#include <iostream>
using namespace std;

// a 
class diagonal_mat {
    int mat[10];
    int n, temp;
public:
    void set(int m) {
        n = m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    cin >> mat[i];
                }
                else {
                    cin >> temp;
                }
            }
        }
    }
    int get(int i, int j) {
        if (i == j) {
            return mat[i];
        }
        return 0;
    }
};

void a() {
    int n;
    diagonal_mat mat;
    cout << "\nEnter the number of rows: ";
    cin >> n;
    cout << "\nEnter the elements of the matrix:\n";
    mat.set(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat.get(i, j) << " ";
        }
        cout << "\n";
    }
}

// b
class tri_diagonal_mat {
    int lower[10], main_d[10], upper[10];
    int n, temp;
public:
    void set(int m) {
        n = m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    cin >> main_d[i];
                else if (i == j + 1)
                    cin >> lower[i];
                else if (j == i + 1)
                    cin >> upper[i];
                else
                    cin >> temp;
            }
        }
    }
    int get(int i, int j) {
        if (i == j)
            return main_d[i];
        if (i == j + 1)
            return lower[i];
        if (j == i + 1)
            return upper[i];
        return 0;
    }
};

void b() {
    int n;
    tri_diagonal_mat mat;
    cout << "\nEnter the number of rows: ";
    cin >> n;
    cout << "\nEnter the elements of the matrix:\n";
    mat.set(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat.get(i, j) << " ";
        }
        cout << "\n";
    }
}

// c 
class lower_triangular_mat {
    int lower[50];
    int n, temp;
public:
    void set(int m) {
        n = m;
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= j)
                    cin >> lower[k++];
                else
                    cin >> temp;
            }
        }
    }
    int get(int i, int j) {
        if (i >= j)
            return lower[i * (i + 1) / 2 + j];
        return 0;
    }
};

void c() {
    int n;
    lower_triangular_mat mat;
    cout << "\nEnter the number of rows: ";
    cin >> n;
    cout << "\nEnter the elements of the matrix:\n";
    mat.set(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat.get(i, j) << " ";
        }
        cout << "\n";
    }
}

// d
class upper_triangular_mat {
    int lower[50];
    int n, temp;
public:
    void set(int m) {
        n = m;
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i <= j)
                    cin >> lower[k++];
                else
                    cin >> temp;
            }
        }
    }
    int get(int i, int j) {
        if (i <= j)
            return lower[j * (j + 1) / 2 + i];
        return 0;
    }
};

void d() {
    int n;
    upper_triangular_mat mat;
    cout << "\nEnter the number of rows: ";
    cin >> n;
    cout << "\nEnter the elements of the matrix:\n";
    mat.set(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat.get(i, j) << " ";
        }
        cout << "\n";
    }
}

// e
class sym_mat {
    int lower[50];
    int n, temp;
public:
    void set(int m) {
        n = m;
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= j)
                    cin >> lower[k++];
                else
                    cin >> temp;
            }
        }
    }
    int get(int i, int j) {
        if (i <= j)
            return lower[j * (j + 1) / 2 + i];
        else if (i >= j)
            return lower[i * (i + 1) / 2 + j];
        return 0;
    }
};

void e() {
    int n;
    sym_mat mat;
    cout << "\nEnter the number of rows: ";
    cin >> n;
    cout << "\nEnter the elements of the matrix:\n";
    mat.set(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat.get(i, j) << " ";
        }
        cout << "\n";
    }
}

int main() {
    char choice;
    do {
        cout << "\n(a/b/c/d/e, x to exit): ";
        cin >> choice;

        switch (choice) {
            case 'a': a();  break;
            case 'b':  b(); break;
            case 'c': c(); break;
            case  'd': d();   break;
            case 'e': e();  break;
            case 'x': break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 'x');

    return 0;
}

