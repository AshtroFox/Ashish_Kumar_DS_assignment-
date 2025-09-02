#include <iostream>
using namespace std;

void create_triplet(int arr[][3], int n){
	
	for (int i =0; i < n; i++){
		cout << "\nEnter the row";
		cin >> arr[i][0];
		cout << "\nEnter the column";
		cin >> arr[i][1];
		cout << "\nEnter the value";
		cin >> arr[i][2];
	}
}

void display(int arr[][3], int row, int col, int n){
    for (int i = 0; i < row; i++){
        cout << endl;
        for (int j = 0; j < col; j++){
            int val = 0;
            for (int t = 0; t < n; t++){
                if (arr[t][0] == i && arr[t][1] == j) {
                    val = arr[t][2];
                    break;
                }
            }
            cout << " " << val;
        }
    }
    cout << endl;
}

void transpose(int arr[][3], int n, int *row, int *col){
	int temp = 0;
	for (int i = 0; i < n; i++){
		temp = arr[i][0];
		arr[i][0] = arr[i][1];
		arr[i][1] = temp;
	}
	temp = *row;
	*row = *col;
	*col = temp;
}

void add(int arr1[][3], int r1, int c1, int v1, int arr2[][3], int v2 ,int res[][3], int *v3){
	int sum = 0, t =0;
	for (int i = 0; i < r1; i++){
		for (int j = 0; j < c1; j++){
			sum = 0;
			
			for (int k = 0; k < v1; k++){
				if ( i == arr1[k][0] && j == arr1[k][1]){
					sum += arr1[k][2];
					break;
				}
			}
			for (int k = 0; k < v2; k++){
				if ( i == arr2[k][0] && j == arr2[k][1]){
					sum += arr2[k][2];
					break;
				}
			}
			
			if (sum != 0){
				res[t][0] = i;
				res[t][1] = j;
				res[t++][2] = sum;
			}
		}
	}
	*v3 = t;
	
}

void multiply(int arr1[][3], int r1, int c1, int v1, int arr2[][3], int r2, int c2, int v2) {
    if (c1 != r2) {
        cout << "\nnot possible!" << endl;
        return;
    }

    for (int i = 0; i < r1; i++) {
        cout << endl;
        for (int j = 0; j < c2; j++) {
            int sum = 0;

            for (int a = 0; a < v1; a++) {
                if (arr1[a][0] == i) { 
                    int k = arr1[a][1];

                    for (int b = 0; b < v2; b++) {
                        if (arr2[b][0] == k && arr2[b][1] == j) {
                            sum += arr1[a][2] * arr2[b][2];
                        }
                    }
                }
            }

            cout << " " << sum;
        }
    }
    cout << endl;
}
void a() {
    int r, c, v;
    cout << "Enter rows, cols, number fo non-zero values";
    cin >> r >> c >> v;

    int arr[20][3];
    create_triplet(arr, v);

    cout << "\nOriginal Matrix\n";
    display(arr, r, c, v);

    transpose(arr, v, &r, &c);

    cout << "\nTranspose \n";
    display(arr, r, c, v);
}

void b() {
    int r1, c1, v1, r2, c2, v2;
    cout << "Enter rows, cols, non-zero values for matrix 1";
    cin >> r1 >> c1 >> v1;
    int arr1[20][3];
    create_triplet(arr1, v1);

    cout << "Enter rows, cols, non-zero values for Matrix 2";
    cin >> r2 >> c2 >> v2;
    int arr2[20][3];
    create_triplet(arr2, v2);

    if (r1 != r2 || c1 != c2) {
        cout << "\nnot possible" << endl;
        return;
    }

    int res[40][3], v3;
    add(arr1, r1, c1, v1, arr2, v2, res, &v3);

    cout << "\nResult\n";
    display(res, r1, c1, v3);
}

void c(){ 
    int r1, c1, v1, r2, c2, v2;
    cout << "Enter rows, cols, non-zero values for Matrix 1";
    cin >> r1 >> c1 >> v1;
    int arr1[20][3];
    create_triplet(arr1, v1);

    cout << "Enter rows, cols, non-zero values for Matrix 2";
    cin >> r2 >> c2 >> v2;
    int arr2[20][3];
    create_triplet(arr2, v2);

    cout << "\nResult\n";
    multiply(arr1, r1, c1, v1, arr2, r2, c2, v2);
}




int main() {
    char ch;
    cout << "\nchoose subpart a,b,c";
    cin >> ch;

    switch (ch) {
        case 'a': 
		a(); 
		break;
        case 'b': 
		b(); 
		break;
        case 'c':
		c(); 
		break;
    }
    return 0;
}

