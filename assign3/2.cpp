#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    void push(char c) {
        if (top == MAX-1) {
            cout << "Stack Overflow\n";
        } else {
            arr[++top] = c;
        }
    }

    char pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return '\0';
        } else {
            return arr[top--];
        }
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    char str[MAX];
    cout << "Enter a string: ";
    cin >> str;

    Stack s;

    
    for (int i = 0; i < strlen(str); i++) {
        s.push(str[i]);
    }

    cout << "Reversed string: ";
    
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;

    return 0;
}
