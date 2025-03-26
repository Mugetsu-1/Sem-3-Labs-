#include <iostream>
#define MAX 10
using namespace std;

class PriorityQueue {
    int pq[MAX], size;
public:
    PriorityQueue() : size(0) {}
    void enqueue(int x) {
        if (size == MAX) { 
		cout << "Queue Overflow\n"; return;     }
        int i = size - 1; 
        while (i >= 0 && pq[i] > x) pq[i + 1] = pq[i--];
        pq[i + 1] = x; size++;
        cout << x << " enqueued\n";
    }
    int dequeue() {
        if (isEmpty()) { 
		cout << "Queue Underflow\n"; return -1; }
        int x = pq[0]; 
        for (int i = 0; i < size - 1; i++) pq[i] = pq[i + 1];
        size--; return x;
    }
    bool isEmpty() { return size == 0; }
    void displayQueue() {
        if (isEmpty()) {
		 cout << "Queue is empty\n"; return; }
        for (int i = 0; i < size; i++) cout << pq[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq; int choice, value;
    while (true) {
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; 
			cin >> value; pq.enqueue(value);
			 pq.displayQueue(); break;
            case 2: value = pq.dequeue();
			 if (value != -1) cout << value << " dequeued\n";
			  pq.displayQueue(); break;
            case 3: pq.displayQueue(); break;
            case 4: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}

