#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
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

    int Size() {
        if (!head)
            return 0;
        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void InsertLast(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    int Size() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.InsertLast(10);
    dll.InsertLast(20);
    dll.InsertLast(30);

    CircularLinkedList cll;
    cll.InsertLast(5);
    cll.InsertLast(15);
    cll.InsertLast(25);
    cll.InsertLast(35);

    cout << "Size of Doubly Linked List: " << dll.Size() << endl;
    cout << "Size of Circular Linked List: " << cll.Size() << endl;

    return 0;
}

