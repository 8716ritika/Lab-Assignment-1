#include <iostream>
using namespace std;

#define MAX 100

class ArrayOperations {
    int arr[MAX];
    int size;

public:
    ArrayOperations() {
        size = 0;
    }

    void create() {
        cout << "Enter number of elements: ";
        cin >> size;
        if (size > MAX) {
            cout << "Size exceeds maximum limit.\n";
            size = 0;
            return;
        }
        cout << "Enter " << size << " elements:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
        cout << "Array created successfully!\n";
    }

    void display() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Array elements are: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insert() {
        if (size == MAX) {
            cout << "Array is full, cannot insert.\n";
            return;
        }
        int pos, element;
        cout << "Enter position (1 to " << size + 1 << "): ";
        cin >> pos;
        if (pos < 1 || pos > size + 1) {
            cout << "Invalid position!\n";
            return;
        }
        cout << "Enter element to insert: ";
        cin >> element;

        // shifting
        for (int i = size; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos - 1] = element;
        size++;
        cout << "Element inserted successfully!\n";
    }

    void deleteElement() {
        if (size == 0) {
            cout << "Array is empty, nothing to delete.\n";
            return;
        }
        int pos;
        cout << "Enter position to delete (1 to " << size << "): ";
        cin >> pos;
        if (pos < 1 || pos > size) {
            cout << "Invalid position!\n";
            return;
        }
        // shifting
        for (int i = pos - 1; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Element deleted successfully!\n";
    }

    void linearSearch() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        int key, found = 0;
        cout << "Enter element to search: ";
        cin >> key;
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                cout << "Element found at position " << i + 1 << endl;
                found = 1;
            }
        }
        if (!found)
            cout << "Element not found.\n";
    }
};

int main() {
    ArrayOperations obj;
    int choice;

    do {
        cout << "\n---- MENU ----\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: obj.create(); break;
            case 2: obj.display(); break;
            case 3: obj.insert(); break;
            case 4: obj.deleteElement(); break;
            case 5: obj.linearSearch(); break;
            case 6: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
