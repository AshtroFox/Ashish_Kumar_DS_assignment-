#include <iostream>
using namespace std;

class Queue {
    int MAX = 100;
    int arr[100];
    int front, rear;
public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front == (rear + 1) % MAX;
    }

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    void enqueue(int x) {

	    rear = (rear + 1) % MAX;
	    arr[rear] = x;
    }

    int dequeue() {

        int val = arr[front];
        front = (front + 1) % MAX;
        return val;
    }

    void peek() {
        cout << endl << arr[front];
    }

    void display() {
        int i = front;
        while (i != (rear + 1) % MAX) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    int choice, val;
    do {
        cout << "\n1- enqueue 2-dequeue  3- peek  4- display  5-exit\n";
        cout << "enter choice";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "enter value ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                break;
        }
    } while (choice != 5);

    return 0;
}

