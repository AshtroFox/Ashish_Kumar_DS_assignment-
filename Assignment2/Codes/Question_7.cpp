//Question 7
#include <iostream>
using namespace std;

int main(){
	int arr[100], n, count = 0;
	cout << "\nEnter the number of elements";
	cin >> n;
	cout << "\nEnter the elements";
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	for (int i  = 0; i < n; i++){
		for ( int j = i+1; j < n; j++){
			if (arr[i] > arr[j]){
				count++; 
			}
		}
	}
	cout << "\nNumber of inversions = " << count;
}
