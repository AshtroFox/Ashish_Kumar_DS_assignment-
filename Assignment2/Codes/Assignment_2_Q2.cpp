#include <iostream>
using namespace std;

void swap(int i, int j, int arr[]){
	int temp = arr[i];
	arr[i] = arr[j]; 
	arr[j] = temp;
}

int main(){
	
	int arr[100], n;
	
	cout << "\nEnter the number of elements in array";
	cin  >> n;
	
	for (int i = 0; i < n; i++){
		cout << "\nEnter the " << i << "th element";
		cin >> arr[i]; 
	}
	
	for (int i = 0; i < n-1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if (arr[j] > arr[j+1]){
				swap(j, j+1, arr);
				
			}
		}
	}
	
	for (int i = 0; i < n; i++){
		cout << "\n" << arr[i];
	}
}
