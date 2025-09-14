#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);  // default -1
    stack<int> st;  // will store indices

    for (int i = n - 1; i >= 0; i--) {
        // Remove all elements smaller or equal to arr[i]
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        // If stack not empty, top is the next greater
        if (!st.empty()) {
            result[i] = arr[st.top()];
        }

        // Push current index
        st.push(i);
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

    vector<int> ans = nextGreaterElement(arr);

    cout << "Next Greater Elements: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
