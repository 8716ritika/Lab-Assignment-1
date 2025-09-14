#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    stack<long long> st;
    long long minEle;

public:
    void push(long long x) {
        if (st.empty()) {
            st.push(x);
            minEle = x;
        }
        else if (x >= minEle) {
            st.push(x);
        }
        else {
            // Store modified value
            st.push(2 * x - minEle);
            minEle = x;
        }
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        long long t = st.top();
        st.pop();

        if (t < minEle) {
            // Popped value was a special marker
            minEle = 2 * minEle - t;
        }
    }

    long long top() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        long long t = st.top();
        if (t < minEle) return minEle; // special value, return actual min
        return t;
    }

    long long getMin() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return minEle;
    }

    bool isEmpty() {
        return st.empty();
    }
};

int main() {
    SpecialStack s;
    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);

    cout << "Min: " << s.getMin() << endl; // 2
    s.pop();
    cout << "Min: " << s.getMin() << endl; // 3
    s.pop();
    cout << "Top: " << s.top() << endl;    // 3
    cout << "Min: " << s.getMin() << endl; // 3

    return 0;
}
