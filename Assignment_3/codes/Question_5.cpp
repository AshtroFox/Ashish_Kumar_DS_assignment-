#include <iostream>
#include <string.h>
using namespace std;

class intStack {
    int max = 50;
    int top = -1;
    int a[50];
public:
    void push(int ele) {
        if (top != max - 1) a[++top] = ele;
    }
    int pop() {
        if (top == -1) return -1;
        return a[top--];
    }
    bool isempty() {
        return (top == -1); }
};


int main() {
    char exp[50];
    cin >> exp;
    intStack s;
    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i];
        if (isdigit(ch)) {
            s.push(ch-'0');
        } else {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (ch) {
                case '+':
                    s.push(val1 + val2);
                    break;
                case '-':
                    s.push(val1 - val2);
                    break;
                case '*':
                    s.push(val1 * val2);
                    break;
                case '/':
                    s.push(val1 / val2);
                    break;
            }
        }
    }
    cout<< s.pop();
}
