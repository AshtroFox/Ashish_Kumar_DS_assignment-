#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList() {
        head = nullptr;
    }

    void InsertLast(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
            n->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = n;
        n->next = head;
    }

    void Display() {
        if (!head) {
            cout << "empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << "." << endl; 
    }
};

int main() {
    CircularLinkedList cll;
    cll.InsertLast(20);
    cll.InsertLast(100);
    cll.InsertLast(40);
    cll.InsertLast(80);
    cll.InsertLast(60);

    cll.Display();

    return 0;
}

