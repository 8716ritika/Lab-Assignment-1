#include <iostream>
using namespace std;

#define MAX 5  

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    
    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << val << endl;
        } else {
            arr[++top] = val;
            cout << val << " pushed into stack.\n";
        }
    }

    
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop.\n";
        } else {
            cout << arr[top--] << " popped from stack.\n";
        }
    }

    
    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX - 1);
    }

    
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
        } else {
            cout << "Stack elements (top to bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element.\n";
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, val;

    do {
        cout << "\n---- STACK MENU ----\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                if (s.isEmpty()) cout << "Stack is Empty.\n";
                else cout << "Stack is NOT Empty.\n";
                break;
            case 4:
                if (s.isFull()) cout << "Stack is Full.\n";
                else cout << "Stack is NOT Full.\n";
                break;
            case 5:
                s.display();
                break;
            case 6:
                s.peek();
                break;
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
