//WAP to LinkList as ADT.
#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(NULL) {}
};

class LinkedList {
private:
    Node* head = NULL;

public:
    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        display(); // Display list after insertion
    }

    void deleteNode(int value) {
        Node** cur = &head;
        while (*cur && (*cur)->data != value)
            cur = &(*cur)->next;
        if (*cur) {
            Node* temp = *cur;
            *cur = (*cur)->next;
            delete temp;
        }
        display(); // Display list after deletion
    }

    void display() const {
        for (Node* cur = head; cur; cur = cur->next)
            std::cout << cur->data << " ";
        std::cout << std::endl;
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    int choice, value;

    do {
        std::cout << "Menu:\n"
                     "1. Insert\n"
                     "2. Delete\n"
                     "3. Display\n"
                     "4. Exit\n"
                     "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            list.insert(value);
            break;
        case 2:
            std::cout << "Enter value to delete: ";
            std::cin >> value;
            list.deleteNode(value);
            break;
        case 3:
            list.display();
            break;
        case 4:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

