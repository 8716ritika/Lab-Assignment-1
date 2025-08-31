a)
#include <iostream>
using namespace std;

int main() {
    int n, arr[100];
    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Reverse logic
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
b)
#include <iostream>
using namespace std;

int main() {
    int m, n, p;
    cout << "Enter rows and columns of Matrix A: ";
    cin >> m >> n;
    cout << "Enter columns of Matrix B: ";
    cin >> p;

    int A[50][50], B[50][50], C[50][50] = {0};

    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            cin >> B[i][j];

    // Multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Resultant Matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
c)
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows and columns of Matrix: ";
    cin >> m >> n;

    int A[50][50], T[50][50];

    cout << "Enter elements of Matrix:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    // Transpose
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            T[j][i] = A[i][j];

    cout << "Transpose Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << T[i][j] << " ";
        cout << endl;
    }

    return 0;
}


