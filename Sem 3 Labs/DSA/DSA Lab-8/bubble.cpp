#include <iostream>
using namespace std;

int main() {
    int demo[10] = {2, 5, 3, 1, 8, 93, 7, 55, 11, 0};

    cout << "Original array: ";
    for (int i = 0; i < 10; i++) {
        cout << demo[i] << " ";
    }
    cout << endl;

    // Sorting the array
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (demo[i] > demo[j]) {
                swap(demo[i], demo[j]);
            }
        }
    }

    cout << "Sorted array: ";
    for (int k = 0; k < 10; k++) {
        cout << demo[k] << " ";
    }
    cout << endl;

    return 0;
}

