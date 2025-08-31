#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> s;

    for (char c : postfix) {
        if (isdigit(c)) {
            // Operand → convert char to int and push
            s.push(c - '0');
        }
        else {
            // Operator → pop two values
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(pow(val1, val2)); break;
            }
        }
    }
    return s.top(); // final result
}

int main() {
    string postfix;
    cout << "Enter Postfix expression (single-digit operands): ";
    cin >> postfix;

    cout << "Evaluated result: " << evaluatePostfix(postfix) << endl;
    return 0;
}
