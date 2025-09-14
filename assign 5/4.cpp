#include <iostream>
#include <queue>
#include <string>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    int freq[26] = {0};  // frequency of characters

    for (char c : str) {
        // step 1: push current character in queue
        q.push(c);
        freq[c - 'a']++;

        // step 2: pop from queue until front is non-repeating
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        // step 3: print answer
        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Enter a string (lowercase letters): ";
    cin >> str;

    cout << "First non-repeating characters: ";
    firstNonRepeating(str);

    return 0;
}
