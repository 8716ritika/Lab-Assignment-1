#include <iostream>
#include <stack>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

// Function to check if operator is right associative
bool isRightAssociative(char op) {
    return (op == '^');  // only ^ is right-associative
}

// Function to convert Infix to Postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            // Operand → directly to output
            postfix += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            // Pop till '('
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // remove '('
        }
        else {
            // Operator
            while (!s.empty() && precedence(s.top()) > precedence(c) ||
                   (!s.empty() && precedence(s.top()) == precedence(c) && !isRightAssociative(c))) {
                if (s.top() == '(') break;
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop all remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter Infix expression: ";
    cin >> infix;

    cout << "Postfix expression: " << infixToPostfix(infix) << endl;

    return 0;
}
