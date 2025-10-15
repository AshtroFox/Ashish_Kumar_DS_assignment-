#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(char val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void InsertLast(char val) {
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

    bool IsPalindrome() {
        if (!head || !head->next)
            return true;
        Node* start = head;
        Node* end = head;
        while (end->next)
            end = end->next;
        while (start != end && end->next != start) {
            if (start->data != end->data)
                return false;
            start = start->next;
            end = end->prev;
        }
        return true;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.InsertLast('r');
    dll.InsertLast('a');
    dll.InsertLast('d');
    dll.InsertLast('a');
    dll.InsertLast('r');

    if (dll.IsPalindrome())
        cout << "The doubly linked list is a palindrome." << endl;
    else
        cout << "The doubly linked list is not a palindrome." << endl;

    return 0;
}

