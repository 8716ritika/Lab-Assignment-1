a)
#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front()); q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) { cout << "Stack Underflow!\n"; return; }
        cout << "Popped: " << q1.front() << endl;
        q1.pop();
    }

    void top() {
        if (q1.empty()) cout << "Stack is empty\n";
        else cout << "Top element: " << q1.front() << endl;
    }

    bool empty() { return q1.empty(); }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.top();
    st.pop();
    st.top();
    return 0;
}


b)


#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;
public:
    void push(int x) {
        int sz = q.size();
        q.push(x);
        for (int i = 0; i < sz; i++) {
            q.push(q.front()); q.pop();
        }
    }

    void pop() {
        if (q.empty()) { cout << "Stack Underflow!\n"; return; }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void top() {
        if (q.empty()) cout << "Stack is empty\n";
        else cout << "Top element: " << q.front() << endl;
    }
};

int main() {
    Stack st;
    st.push(5);
    st.push(15);
    st.push(25);
    st.top();
    st.pop();
    st.top();
    return 0;
}
