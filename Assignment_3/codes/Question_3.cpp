#include <iostream>
#include <string.h>
using namespace std;

class stack{
    int max = 20;
    int top = -1;
    char a[20];
   
    public:
   
    void push(char ele){
        if ( top == max - 1){
            cout << "\nStack Overflow";
        }
        else{
            a[++top]  = ele;
        }
    }
   
    char pop(){
        if (top == -1){
            cout << "\nStack empty";
            return '\0';
        }
        else{
            return a[top--];
        }
    }
   
    bool isempty(){
        return (top == -1);
    }

    char peek(){
        if (top == -1) return '\0';
        return a[top];
    }
};

int main(){
    stack s;
    char str[20];
   
    cout << "\nEnter the parantheses expression: ";
    cin.getline(str, 20);
   
    bool valid = true;
    for (int i = 0; i < strlen(str); i++ ){
        if (str[i] == '(' ||str[i] == '[' ||str[i] == '{'){
            s.push(str[i]);
        }
        else if (str[i] ==  ')' && s.peek() == '('){
            s.pop();
        }
        else if (str[i] ==  ']' && s.peek() == '['){
            s.pop();
        }
        else if (str[i] ==  '}' && s.peek() == '{'){
            s.pop();
        }
        else{
            valid = false;
            break;
        }
    }
    if (valid && s.isempty()){
        cout << "\nValid";
    }
    else{
        cout << "\nInvalid";
    }
    return 0;
}

