#include <iostream>
using namespace std;

#define SIZE 5  // max size of queue

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if queue is full
    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    // Insert element
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot enqueue.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = x;
        cout << x << " enqueued.\n";
    }

    // Delete element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Cannot dequeue.\n";
            return;
        }
        cout << arr[front] << " dequeued.\n";
        if (front == rear) { // only one element
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    // Peek at front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    // Display elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, val;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
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
                cout << (q.isEmpty() ? "Queue is EMPTY.\n" : "Queue is NOT EMPTY.\n");
                break;
            case 6:
                cout << (q.isFull() ? "Queue is FULL.\n" : "Queue is NOT FULL.\n");
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
