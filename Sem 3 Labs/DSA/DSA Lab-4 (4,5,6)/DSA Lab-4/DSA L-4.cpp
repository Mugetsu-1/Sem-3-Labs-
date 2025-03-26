#include <iostream>
using namespace std;

#define MAX 10

class Queue {
private:
    int front, rear;
    int arr[MAX];

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueue(int x) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
        cout << x << " enqueued into queue\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int x = arr[front++];
        if (front > rear) front = rear = -1; // Reset the queue when empty
        return x;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++)
            cout  << "Elements in Linear Queue are : " << arr[i] ;
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;
	cout<<" Memu :- \n";
    while (true) {
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: \n";
                cin >> value;
                q.enqueue(value);
                q.displayQueue();
                break;
            case 2:
                value = q.dequeue();
                if (value != -1)
                    cout << value << " dequeued from queue\n\n";
                    q.displayQueue();
                break;
            case 3:
                q.displayQueue();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

