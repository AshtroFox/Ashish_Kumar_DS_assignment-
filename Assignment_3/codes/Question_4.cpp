#include <iostream>
#include <string.h>
using namespace std;

class stack {
    int max = 20;
    char a[20];
    int top = -1;

public:

    void push(char ele) {
        if (top == max - 1) {
            cout << "\nStack Overflow";
        }
        else {
            a[++top] = ele;
        }
    }

    char pop() {
        if (top == -1) {
            cout << "\nStack empty";
            return '\0';
        }
        else {
            return a[top--];
        }
    }

    char peek() {
        if (top == -1)
            return '\0';
        return a[top];
    }

    bool isempty() {
        return top == -1;
    }
};

int precedence(char op) {
    if (op == '+' || op == '-'){
       
        return 1;}
    if (op == '*' || op == '/'){
       
        return 2;}
    if (op == '^') return 3;{
        return 0;}
}

int main() {
    char infix[20];
    cout << "Enter the infix exp";
    cin.getline(infix, 20);

    stack s;

    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            cout << c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isempty() && s.peek() != '(') {
                cout << s.pop();
            }
            s.pop();
        }
        else {
            while (!s.isempty() && precedence(s.peek())>= precedence(c)) {
                cout << s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isempty()) {
        cout << s.pop();
    }
    cout << endl;
    return 0;
}
