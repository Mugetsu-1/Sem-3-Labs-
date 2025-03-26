#include <iostream>
using namespace std;

int main()
{
    int demo[10] = {2, 5, 3, 1, 8, 93, 7, 55, 11, 0};
    int curr_min;
    int temp;

    cout << "Original array: ";
    for (int i = 0; i < 10; i++) {
        cout << demo[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 10; i++) {
        curr_min = i;
        for (int j = i + 1; j < 10; j++) {
            if (demo[j] < demo[curr_min]) {
                curr_min = j;
            }
        }
        temp = demo[curr_min];
        demo[curr_min] = demo[i];
        demo[i] = temp;
    }

    cout << "Sorted array: ";
    for (int k = 0; k < 10; k++) {
        cout << demo[k] << " ";
    }
    cout << endl;

    return 0;
}

