#include <iostream>
using namespace std;

class Queue {
    int MAX = 100;
    char arr[100];
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

    void enqueue(char x) { 
        rear = (rear + 1) % MAX;
        arr[rear] = x;
    }

    char dequeue() {
        char val = arr[front];
        front = (front + 1) % MAX;
        return val;
    }

    char peek() { 
        return arr[front];
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
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    Queue q;
    int freq[256] = {0}; 

    for (char ch : s) {


        freq[ch]++;       
        q.enqueue(ch);
    }

    while (!q.isEmpty() && freq[q.peek()] > 1) {
        q.dequeue();
        }

    cout << q.peek() << " ";
    

    return 0;
}

