#include <iostream>
#define MAX 5
using namespace std;

class CircularQueue {
    int front, rear, arr[MAX];
public:
    CircularQueue() : front(-1), rear(-1) {  }
    
    bool isFull() {
	 return ((rear + 1) % MAX == front);       }
	 
    bool isEmpty() {
	 return (front == -1);         }
	 
    void enqueue(int x) {
        if (isFull()) {
		 cout << "Queue Overflow\n"; return;      }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX; arr[rear] = x;
        cout << x << " enqueued\n";
    }
    int dequeue() {
        if (isEmpty()) { cout << "Queue Underflow\n"; return -1; }
        int x = arr[front];
        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
        return x;
    }
    void displayQueue() {
        if (isEmpty()) { cout << "Queue is empty\n"; return;   }
        cout << "Queue: ";
        if (rear >= front) for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        else { 
		for (int i = front; i < MAX; i++) cout << arr[i] << " "; 
		for (int i = 0; i <= rear; i++) cout << arr[i] << " ";      }
        cout << endl;
    }
};

int main() {
    CircularQueue q; int choice, value;
    while (true) {
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; 
			cin >> value;
			 q.enqueue(value); break;
            case 2: value = q.dequeue(); 
			if (value != -1) cout << value << " dequeued\n"; break;
            case 3: q.displayQueue(); break;
            case 4: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}

