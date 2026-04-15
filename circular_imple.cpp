#include<bits/stdc++.h>
using namespace std;

class Queue {
    int arr[100];
    int front, rear;
    int size;

public:
    Queue() {
        front = -1;
        rear = -1;
        size = 100;
    }

    void enqueue(int x) {
        // check overflow
        if ((rear + 1) % size == front) {
            cout << "Queue Overflow\n";
            return;
        }

        // first element
        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }

        arr[rear] = x;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Removed: " << arr[front] << endl;

        // only one element
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
    }

    void peek() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }

        int i = front;

        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }

        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    q.dequeue();
    q.display();

    q.peek();

    return 0;
}