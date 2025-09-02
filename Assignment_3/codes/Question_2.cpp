#include <iostream>
#include <string.h>
using namespace std;

class stack{
    int max = 20;
    int top = -1;
    char a[20];
   
    public:
   
    void push(int ele){
        if ( top == max - 1){
            cout << "\nStack Overflow";
        }
        else{
            a[++top]  = ele;
        }
       
    }
   
    void pop(){
        if (top == -1){
            cout << "\nStack empty";
        }
        else{
            cout << a[top--];
        }
    }
   
    void display(){
        for (int i = top; i >= 0; i--){
            cout  << a[i];
        }
    }
   
    void isempty(){
        if (top == -1){
            cout << "true";
        }
        else{
            cout << "false";
        }
    }
    void isfull(){
        if (top == max-1){
            cout << "true";
        }
        else{
            cout << "false";
        }
    }
    void peek(){
        cout << a[top];
    }
};


int main(){
    stack s;
    char str[20];
   
    cout << "\nEnter the string: ";
    cin.getline(str, 20);
   
    for (int i = 0; i < strlen(str); i++ ){
        s.push(str[i]);
    }
    s.display();
}
