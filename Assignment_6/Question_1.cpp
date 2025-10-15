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

    void InsertStart(int val) {
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
        head = n;
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

    void InsertAt(int pos, int val) {
        if (pos <= 1) {
            InsertStart(val);
            return;
        }
        Node* n = new Node(val);
        Node* temp = head;
        int count = 1;
        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }
        n->next = temp->next;
        temp->next = n;
    }

    void DeleteNode(int val) {
        if (!head) return;
        Node* curr = head;
        Node* prev = nullptr;


        if (curr->data == val) {
            if (curr->next == head) {
                delete curr;
                head = nullptr;
                return;
            }
            Node* last = head;
            while (last->next != head)
                last = last->next;
            last->next = head->next;
            head = head->next;
            delete curr;
            return;
        }

        do {
            prev = curr;
            curr = curr->next;
        } while (curr != head && curr->data != val);

        if (curr->data == val) {
            prev->next = curr->next;
            delete curr;
        }
    }

    Node* SearchNode(int val) {
        if (!head) return nullptr;
        Node* temp = head;
        do {
            if (temp->data == val)
                return temp;
            temp = temp->next;
        } while (temp != head);
        return nullptr;
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
        cout << endl;
    }
};


class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void InsertStart(int val) {
        Node* n = new Node(val);
        n->next = head;
        if (head)
            head->prev = n;
        head = n;
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

    void InsertAt(int pos, int val) {
        if (pos <= 1) {
            InsertStart(val);
            return;
        }
        Node* temp = head;
        int count = 1;
        while (count < pos - 1 && temp->next) {
            temp = temp->next;
            count++;
        }
        Node* n = new Node(val);
        n->next = temp->next;
        if (temp->next)
            temp->next->prev = n;
        n->prev = temp;
        temp->next = n;
    }

    void DeleteNode(int val) {
        if (!head) return;
        Node* temp = head;

        if (temp->data == val) {
            head = head->next;
            if (head)
                head->prev = nullptr;
            delete temp;
            return;
        }

        while (temp && temp->data != val)
            temp = temp->next;
        if (!temp) return;

        if (temp->next)
            temp->next->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = temp->next;

        delete temp;
    }

    Node* SearchNode(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void Display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    CircularLinkedList clist;
    DoublyLinkedList dlist;
    int listType, choice, val, pos;

    cout << "1. Circular Linked List\n";
    cout << "2. Doubly Linked List\n";
    cout << "Choose which list";
    cin >> listType;

    while (true) {

        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete a Node\n";
        cout << "5. Search a Node\n";
        cout << "6. Display List\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 7) break;

        if (listType == 1) {
            switch (choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    clist.InsertStart(val);
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin >> val;
                    clist.InsertLast(val);
                    break;
                case 3:
                    cout << "Enter position and value: ";
                    cin >> pos >> val;
                    clist.InsertAt(pos, val);
                    break;
                case 4:
                    cout << "Enter value to delete: ";
                    cin >> val;
                    clist.DeleteNode(val);
                    break;
                case 5:
                    cout << "Enter value to search: ";
                    cin >> val;
                    if (clist.SearchNode(val))
                        cout << "Node found\n";
                    else
                        cout << "Node not found\n";
                    break;
                case 6:
                    clist.Display();
                    break;
                default:
                    cout << "Invalid choice\n";
            }
        } 
        else if (listType == 2) {  
            switch (choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    dlist.InsertStart(val);
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin >> val;
                    dlist.InsertLast(val);
                    break;
                case 3:
                    cout << "Enter position and value: ";
                    cin >> pos >> val;
                    dlist.InsertAt(pos, val);
                    break;
                case 4:
                    cout << "Enter value to delete: ";
                    cin >> val;
                    dlist.DeleteNode(val);
                    break;
                case 5:
                    cout << "Enter value to search: ";
                    cin >> val;
                    if (dlist.SearchNode(val))
                        cout << "Node found\n";
                    else
                        cout << "Node not found\n";
                    break;
                case 6:
                    dlist.Display();
                    break;
                default:
                    cout << "Invalid choice\n";
            }
        } 
        else {
            cout << "Invalid list type.\n";
            break;
        }
    }

    return 0;
}

