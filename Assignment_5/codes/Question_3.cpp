#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
   
    Node(int val){
        data = val;
        next = nullptr;
    }
};
class LinkedList{

    public:
    Node* head;
    LinkedList(){
        head = nullptr;
    }
   
    void InsertStart(int val){
        if (head == nullptr){
            head = new Node(val);
        }
        else{
            Node *temp = head;
            head = new Node(val);
            head->next = temp;
        }
    }
    void Display(){
        Node *temp = head;
        while (temp != nullptr){
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    void InsertEnd(int val){
        if (head == nullptr){
            head = new Node(val);
        }
        else{
            Node *temp = head;
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = new Node(val);}
    }
    void Insert(int val, int pos){
        Node *temp = head;
        while (temp != nullptr && temp->data != pos ){
            temp = temp->next;
        }
        if (temp == nullptr){
            cout << "Node not found";
        }
        else{
            Node *temp2 = temp->next;
            temp->next = new Node(val);
            temp->next->next = temp2;}
    }
    void DeleteStart(){
        if (head == nullptr){
            cout << "Alreqady empty";
        }
        else{
            Node *temp = head;
            head = head->next;
            delete temp;}
    }
    void DeleteEnd(){
        if (head == nullptr){
            cout << "alrewady empty";
        }
        else if (head->next == nullptr){
            delete head;
            head = nullptr;
        }
        else{
            Node *temp = head;
            while (temp->next->next != nullptr){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;}
    }
    void Delete(int val){
        if (head  == nullptr){
            cout << "Empty";
        }
        else if( head-> data == val){
            delete head;
            head = nullptr;
        }
        else{
           Node *temp = head;
           while ( temp->next != nullptr && temp->next->data != val){
               temp = temp -> next;
           }
           if (temp -> next == nullptr){
               cout << "Element not found";
           }
           else{
               Node *temp2 = temp->next;
               temp -> next = temp2->next;
               delete temp2;
           }
        }

    }
    void Search(int val){
        int n = 0;
        Node *temp = head;
        if (head == nullptr){
            cout << "empty";
        }
        else{
            while (temp != nullptr && temp->data != val ){
                temp = temp -> next;
                n+=1;
            }
            if (temp == nullptr){
                cout << "Elementy not foudn";
            }
            else{
                cout << "Position from head = " << n;
            }
        }
    }
   
   
};
int main(){
    LinkedList list;

    list.InsertEnd(1);
    list.InsertEnd(2);
    list.InsertEnd(3);
    list.InsertEnd(4);
    list.InsertEnd(5);

    list.Display();

    int count = 0;
    Node* temp = list.head;
    while (temp != nullptr){
        count++;
        temp = temp->next;
    }


    int m = count / 2;
    temp = list.head;
    for (int i = 0; i < m; i++){
        temp = temp->next;
    }

    cout << "Middle element- " << temp->data << endl;

    return 0;
}
