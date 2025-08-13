#include <iostream>
using namespace std;

int main(){
	int arr[100], n, target, m;
	
	cout << "\nEnter the number of elements in array";
	cin  >> n;
	
	for (int i = 0; i < n; i++){
		cout << "\nEnter the " << i << "th element";
		cin >> arr[i]; 
	}
	
	cout << "\nEnter the element to be found";
	cin >> target;
	
	int l = 0, r = n-1;
	
	while (l <= r){
		
		m = (l + r)/2;
		
		if (arr[m] == target){

			cout << m;
			return 0;
		}
		if (arr[m] > target){

			r = m + -1;
		}
		if (arr[m] < target){

			l = m + 1;
		}
	}
		
	cout << "\nElement not found";
	return 0;
	
}
