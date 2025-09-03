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
    int size() {
        if (rear >= front)
            return rear - front + 1;
        return MAX - front + rear + 1;
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
    Queue q;
    int n, x;

    cout << "Enter number of elements to push";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        int sz = q.size();
        q.enqueue(x);
        for (int j = 0; j < sz; j++) {
            q.enqueue(q.dequeue());
        }
    }

    cout << "Stack";
    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;

    return 0;
}

