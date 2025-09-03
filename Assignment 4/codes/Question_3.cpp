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
void interleaveQueue(Queue &q,int n) {

    Queue firstHalf;
    for (int i = 0; i < n / 2; i++) {
        firstHalf.enqueue(q.dequeue());
    }

    while (!firstHalf.isEmpty()) {
        q.enqueue(firstHalf.dequeue()); 
        q.enqueue(q.dequeue());        
    }
}

int main() {
    Queue q;
    int n, x;

    cout << "Enter number of elements  ";
    cin >> n;

	cout << "\nEnter elements";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
    }



    interleaveQueue(q,n);

    q.display();

    return 0;
}
