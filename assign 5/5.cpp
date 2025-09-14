a) 
#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2;

public:
    // Push element onto stack
    void push(int x) {
        // Push x into q2
        q2.push(x);

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);
    }

    // Remove top element
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Popped: " << q1.front() << endl;
        q1.pop();
    }

    // Get top element
    void top() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Top element: " << q1.front() << endl;
    }

    // Check if stack is empty
    bool isEmpty() {
        return q1.empty();
    }
};

b)
class StackOneQueue {
    queue<int> q;

public:
    // Push element
    void push(int x) {
        q.push(x);
        int size = q.size();

        // Rotate queue to make last inserted element at front
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Pop element
    void pop() {
        if (q.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    // Get top element
    void top() {
        if (q.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Top element: " << q.front() << endl;
    }

    // Check empty
    bool isEmpty() {
        return q.empty();
    }
};
int main() {
    cout << "--- Stack using Two Queues ---\n";
    StackTwoQueues s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.top();   // 30
    s1.pop();   // remove 30
    s1.top();   // 20

    cout << "\n--- Stack using One Queue ---\n";
    StackOneQueue s2;
    s2.push(100);
    s2.push(200);
    s2.push(300);
    s2.top();   // 300
    s2.pop();   // remove 300
    s2.top();   // 200

    return 0;
}
