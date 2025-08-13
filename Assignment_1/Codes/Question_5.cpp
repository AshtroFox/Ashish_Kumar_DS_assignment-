#include <iostream>
using namespace std;


int main(){
    int n,m;
    cout << "Enter the number of rows";
    cin >> n;
    cout << "Enetr the number opf columns";
    cin >> m;
    
    int arr[100][100];
    for( int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        cout << "Enter the "<< i<< "," <<  j<<  "element";
        cin >> arr[i][j];
      }
    }
    int row_sum = 0, col_sum = 0;
    
    for (int i = 0; i < n; i++){
        
        
        
        for (int j = 0; j < m; j++){
            row_sum += arr[i][j];
            col_sum += arr[j][i];
            
        }
        cout << "\nrow " << i << " sum = "<< row_sum;
        cout << "\ncol " << i << " sum = "<< col_sum;
        row_sum = 0;
        col_sum = 0;
    }
}
