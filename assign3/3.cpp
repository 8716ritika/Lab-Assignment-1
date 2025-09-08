#include <iostream>
#include <stack>
using namespace std;

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(string expr) {
    stack<char> s;

    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c); 
        } 
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty() || !isMatchingPair(s.top(), c)) {
                return false;
            }
            s.pop(); 
        }
    }

    return s.empty()
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Balanced Expression\n";
    else
        cout << "Unbalanced Expression\n";

    return 0;
}
