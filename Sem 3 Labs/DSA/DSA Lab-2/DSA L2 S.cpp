#include <iostream>
#define SIZE 5

class Stack {
    private:
        int arr[SIZE];
        int top;

    public:
        Stack() {
            top = -1;
        }

        bool isEmpty() {
            return top == -1;
        }

        bool isFull() {
            return top == SIZE - 1;
        }

        void clear() {
            top = -1;
            std::cout << "Stack cleared.\n";
            show();
        }

        void push(int value) {
            if (isFull()) {
                std::cout << "Stack Overflow.\n";
            } else {
                arr[++top] = value;
                std::cout << value << " pushed onto stack.\n";
            }
            show();
        }

        void pop() {
            if (isEmpty()) {
                std::cout << "Stack Underflow.\n";
            } else {
                std::cout << arr[top--] << " popped from stack.\n";
            }
            show();
        }

        void traverse() {
            if (isEmpty()) {
                std::cout << "Stack is empty.\n";
            } else {
                std::cout << "Stack elements:\n";
                for (int i = top; i >= 0; i--) {
                    std::cout << arr[i] << " ";
                }
                std::cout << "\n";
            }
        }

        void peek() {
            if (isEmpty()) {
                std::cout << "Stack is empty.\n";
            } else {
                std::cout << "Top element: " << arr[top] << "\n";
            }
        }

        void show() {
            std::cout << "Current Stack: ";
            if (isEmpty()) {
                std::cout << "empty\n";
            } else {
                for (int i = top; i >= 0; i--) {
                    std::cout << arr[i] << " ";
                }
                std::cout << "\n";
            }
        }
};

int main() {
    Stack s;
    int choice, value;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Clear stack\n";
        std::cout << "2. PUSH\n";
        std::cout << "3. POP\n";
        std::cout << "4. Traverse\n";
        std::cout << "5. Peek\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                s.clear();
                break;
            case 2:
                std::cout << "Enter value to push: ";
                std::cin >> value;
                s.push(value);
                break;
            case 3:
                s.pop();
                break;
            case 4:
                s.traverse();
                break;
            case 5:
                s.peek();
                break;
            case 6:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    }
    return 0;
}

