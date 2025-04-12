#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Queue {
    Node *front, *rear;
public:
    Queue() : front(NULL), rear(NULL) {}

    void enqueue(int x) {
        Node* temp = new Node(x);
        if (!temp) return;
        rear ? rear->next = temp : front = temp;
        rear = temp;
        display();
    }

    void dequeue() {
        if (!front) return;
        Node* temp = front;
        front = front->next;
        if (!front) rear = NULL;
        delete temp;
        display();
    }

    int peek() const {
        return front ? front->data : (cout << "Queue is empty\n", -1);
    }

    bool isEmpty() const { return !front; }

    void display() const {
        if (!front) return void(cout << "Queue is empty\n");
        for (Node* temp = front; temp; temp = temp->next)
            cout << temp->data << " ";
        cout << "\n";
    }
};

int main() {
    Queue queue;
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Check if Empty\n5. Display Queue\n6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; queue.enqueue(value); break;
            case 2: queue.dequeue(); break;
            case 3: cout << "Front element: " << queue.peek() << "\n"; break;
            case 4: cout << (queue.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n"); break;
            case 5: queue.display(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

