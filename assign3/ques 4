#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);  // default 0
    stack<int> st;  // stores indices

    for (int i = 0; i < n; i++) {
        // While current temp is warmer than the one at stack top
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int prevDay = st.top();
            st.pop();
            answer[prevDay] = i - prevDay;  // days waited
        }
        st.push(i);  // push current index
    }

    return answer;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> temperatures(n);
    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++) cin >> temperatures[i];

    vector<int> ans = dailyTemperatures(temperatures);

    cout << "Answer: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
