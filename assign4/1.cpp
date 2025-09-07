#include <iostream>
using namespace std;
#define MAX 5

class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue() { front = -1; rear = -1; }

    bool isEmpty() { return (front == -1); }
    bool isFull() { return (rear == MAX - 1); }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
        cout << x << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << arr[front] << " dequeued.\n";
        if (front == rear) { // last element removed
            front = rear = -1;
        } else {
            front++;
        }
    }

    void peek() {
        if (isEmpty()) cout << "Queue is empty.\n";
        else cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, val;
    do {
        cout << "\n--- Simple Queue Menu ---\n";
        cout << "1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cin >> choice;
        switch (choice) {
        case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
        case 2: q.dequeue(); break;
        case 3: q.peek(); break;
        case 4: q.display(); break;
        case 5: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}
