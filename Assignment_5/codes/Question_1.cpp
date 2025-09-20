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
    Node* head;
    public:
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

int main()
{
    LinkedList list;
    int n = -1;

    while (n != 0) {
        cout << "Enter 1: Insert begin, 2: Insert end, 3: Insert in between, 4: Delete from beginning, 5: Delete from end, 6: Search, 7: Display, 8:Delete a secific node,  0: Exit\n";
        cin >> n;

        switch (n) {
            case 1: {
                int val;
                cout << "Enter value to insert at beginning";
                cin >> val;
                list.InsertStart(val);
                break;
            }
            case 2: {
                int val;
                cout << "Enter value to insert at end";
                cin >> val;
                list.InsertEnd(val);
                break;
            }
            case 3: {
                int val, pos;
                cout << "Enter value to insert";
                cin >> val;
                cout << "Enter node value after which to insert";
                cin >> pos;
                list.Insert(val, pos);
                break;
            }
            case 4: {
                list.DeleteStart();
                break;
            }
            case 5: {
                list.DeleteEnd();
                break;
            }
            case 6: {
                int val;
                cout << "Enter value to search";
                cin >> val;
                list.Search(val);
                cout << endl;
                break;
            }
            case 7: {
                list.Display();
                break;
            }
            case 8: {
            	int val;
            	cout << "\nEnter val to delete";
            	cin >> val;
            	list.Delete(val);
				break;
			}
			

           
        }
    }

    return 0;
}

