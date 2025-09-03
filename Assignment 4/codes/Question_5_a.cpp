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
    void enqueue(int x) {
        rear = (rear + 1) % MAX;
        arr[rear] = x;
    }
    int dequeue() {
        int val = arr[front];
        front = (front + 1) % MAX;
        return val;
    }
    int peek() {
        return arr[front];
    }
};

int main() {
    Queue q1, q2;
    int n, x;

    cout << "Enter number of elements to push";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        q2.enqueue(x);
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    cout << "Stac";
    while (!q1.isEmpty()) {
        cout << q1.dequeue() << " ";
    }
    cout << endl;

    return 0;
}

