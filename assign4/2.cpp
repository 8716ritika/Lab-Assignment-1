#include <iostream>
using namespace std;
#define MAX 5

class CircularQueue {
    int arr[MAX];
    int front, rear;
public:
    CircularQueue() { front = rear = -1; }

    bool isEmpty() { return (front == -1); }
    bool isFull() { return ((rear + 1) % MAX == front); }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue Overflow!\n"; return; }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = x;
        cout << x << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Underflow!\n"; return; }
        cout << arr[front] << " dequeued.\n";
        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is empty.\n";
        else cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is empty.\n"; return; }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    int choice, val;
    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cin >> choice;
        switch (choice) {
        case 1: cout << "Enter value: "; cin >> val; cq.enqueue(val); break;
        case 2: cq.dequeue(); break;
        case 3: cq.peek(); break;
        case 4: cq.display(); break;
        case 5: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}
