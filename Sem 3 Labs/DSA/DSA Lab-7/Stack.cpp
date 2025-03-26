#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() : top(NULL) {}

    void push(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        display();
    }

    void pop() {
        if (!top) return void(cout << "Stack Underflow\n");
        Node* temp = top;
        top = top->next;
        delete temp;
        display();
    }

    int peek() {
        return top ? top->data : (std::cout << "Stack is empty\n", -1);
    }

    bool isEmpty() { return !top; }

    void display() {
        if (!top) return void(std::cout << "Stack is empty\n");
        for (Node* temp = top; temp; temp = temp->next)
            cout << temp->data << " ";
        cout << "\n";
    }
};

int main() {
    Stack stack;
    int choice, value;
    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Display Stack\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2: 
                stack.pop();
                break;
            case 3: 
                cout << "Top element: " << stack.peek() << "\n";
                break;
            case 4: 
                cout << (stack.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
                break;
            case 5: 
                stack.display();
                break;
            case 6: 
                cout << "Exiting...\n";
                break;
            default: 
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

