#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nearestSmallerToLeft(vector<int>& arr) {
    stack<int> st;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        // Remove all elements greater or equal to arr[i]
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // If stack is empty → no smaller element
        if (st.empty()) {
            result.push_back(-1);
        } else {
            result.push_back(st.top());
        }

        // Push current element into stack
        st.push(arr[i]);
    }

    return result;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> ans = nearestSmallerToLeft(arr);

    cout << "Nearest Smaller to Left: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
