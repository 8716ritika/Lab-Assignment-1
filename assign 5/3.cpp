#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even for interleaving!\n";
        return;
    }

    int half = n / 2;
    queue<int> firstHalf;

    // Step 1: Push first half into a new queue
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    // Step 2: Interleave the two halves
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());  // from first half
        firstHalf.pop();

        q.push(q.front());          // from second half
        q.pop();
    }
}

int main() {
    queue<int> q;
    int n, val;
    cout << "Enter number of elements (even size): ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
