#include <iostream>
using namespace std;

class stack{
    int max = 5;
    int a[5], top = -1;
   
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
            cout << " " << a[i];
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
   
    stack st;
   
    int ch;
   
    while (ch != 7){
   
        cout << "\n1 : PUSH  2: POP 3: isEMPTY 4:isfull 5: display 6: peek 7: Exit\n";
        cin >> ch;
       
        switch(ch){
            case 1:
                int element;
                cout << "\nEnter element";
                cin >> element;
                st.push(element);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                st.isempty();
                break;
            case 4:
                st.isfull();
                break;
            case 5:
                st.display();
                break;
            case 6:
                st.peek();
                break;
            case 7:
                break;
        }
    }
           
       
}
