#include <iostream>
using namespace std;
class SimpleQueue {
	int MAX = 100;
    int arr[100];
    int front, rear;
public:
    SimpleQueue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(int x) {
        rear++;
        arr[rear] = x;
    }

    int dequeue() {

        return arr[front++]; 

        
    }

    void peek() {

        cout << endl << arr[front] ;
    }

    void display() {


        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << "\n";
}
};

int main() {
    SimpleQueue q;
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

