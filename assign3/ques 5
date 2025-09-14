#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool canBeSorted(vector<int>& A) {
    stack<int> S;
    int n = A.size();
    int expected = 1;  // smallest element expected in sorted B

    for (int i = 0; i < n; i++) {
        // Push current element into stack
        S.push(A[i]);

        // Keep popping if top of stack is the expected number
        while (!S.empty() && S.top() == expected) {
            S.pop();
            expected++;
        }
    }

    // Finally, stack should also be empty after popping
    return S.empty();
}

int main() {
    int n;
    cout << "Enter size of array A: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter elements of array A: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    if (canBeSorted(A)) {
        cout << "Yes, array B can be sorted in ascending order." << endl;
    } else {
        cout << "No, array B cannot be sorted in ascending order." << endl;
    }

    return 0;
}
