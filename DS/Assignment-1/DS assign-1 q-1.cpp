#include <iostream>
using namespace std;

class ArrayOps {
    int size = 0;
    int arr[100];

public:
    int i, j, k, n, p, m;
    bool found = false;

    ArrayOps() { size = 0; }

    // 1. CREATE
    void create() {
        cout << "Enter no of elements = ";
        cin >> size;

        cout << "Enter " << size << " elements: ";
        for (i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // 2. DISPLAY
    void display() {
        cout << "Array elements:\n";
        for (i = 0; i < size; i++) {
            cout << "Element " << i + 1 << " = " << arr[i] << endl;
        }
    }

    // 3. INSERT
    void insert() {
        cout << "Enter position=";
        cin >> n;
        cout << "Enter element to be inserted=";
        cin >> j;
        for (i = size; i >= n; i--) {
            arr[i] = arr[i - 1];
        }
        arr[n - 1] = j;
        size++;
        cout << "Array elements:\n";
        for (i = 0; i < size; i++) {
            cout << "Element " << i + 1 << " = " << arr[i] << endl;
        }
    }

    // 4. DELETE
    void remove() {
        int c = 0; // ? reset counter for every delete call
        cout << "\nElement to be deleted=";
        cin >> k;
        for (i = 0; i < size - c; i++) {
            if (k == arr[i]) {
                p = i;
                c++;
                for (j = p; j < size - c; j++) {
                    arr[j] = arr[j + 1];
                }
                i--; // re-check same index
            }
        }
        size -= c; // update size
        for (i = 0; i < size; i++) {
            cout << "\n" << arr[i];
        }
    }

    // 5. SEARCH
    void search() {
        cout << "\nEnter element to be searched=";
        cin >> m;
        found = false;
        for (i = 0; i < size; i++) {
            if (arr[i] == m) {
                cout << "\nValue found at position:" << i + 1 << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "\nValue not found";
        }
    }
};

int main() {
    ArrayOps obj;
    int choice;

    do {
        cout << "\n MENU \n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: obj.create(); break;
        case 2: obj.display(); break;
        case 3: obj.insert(); break;
        case 4: obj.remove(); break;
        case 5: obj.search(); break;
        case 6: cout << "Exiting program...\n"; break;
        default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

