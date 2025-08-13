// Question 4
#include <iostream>
#include <string.h>
using namespace std;

void a(){	
	char str1[200], str2[100];
	cout << "\nEnter the first string";
	cin.getline(str1, 200);
	cout << "\nEnter the second string";
	cin.getline(str2, 100);
	strcat(str1, str2);
	cout << str1;
}

void b(){
	char str[100], temp;
	cout << "\nEnter the string\n";
	cin.getline(str, 100);
	int n = strlen(str);
	for (int i = 0; i < n/2; i++){
		temp = str[i];
		str[i] = str[n-i-1];
		str[n-i-1] = temp;
	} 
	cout << str;	
}

void del(char* str, int &n, int i){
	for (int j = i; j < n-1; j++){
		str[j] = str[j+1];
	}
}
void c(){
	char str[100], c;
	cout << "\nEnter the string";
	cin.getline(str, 100);
	int n = strlen(str);
	for (int i = 0; i < n; i++){
		c = tolower(str[i]);
		if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
			del(str, n, i);
			i--;
			n--;
			str[n] = '\0';
		}
	}
	cout << str;
}

void d(){
	char str[100],temp;
	cout << "\nEnter the string";
	cin.getline(str, 100);
	int n = strlen(str);
	for (int i = 0 ; i < n-1; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (str[j] > str[j+1]){
				temp = str[j];
				str[j] = str[j+1];
				str[j+1] = temp;
			}
		}
	}	
	cout << str;
}

void e(){
	char str[100];
	cout << "\nEnter the string";
	cin.getline(str, 100);
	int n = strlen(str);
	for (int i = 0; i < n; i++){
		if (isupper(str[i])){
			str[i] = str[i] + 'a' - 'A';
		}
	}
	cout << str;
}

int main(){
	char ch;
	do {
		cout << "\nEnter subpart (a,b,c,d,e) or x to exit: ";
		cin >> ch;
		cin.ignore();
		switch(ch){
			case 'a': a();  break;
			case 'b': b(); break;
			case 'c': c();  break;
			case 'd':  d(); break;
			case 'e': e(); break;
			case 'x':  break;
			default: cout  << "Invalid\n";
		}
	} while(ch != 'x');
}

