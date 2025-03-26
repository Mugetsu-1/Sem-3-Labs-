//WAP DoublyLinklist as ADT.
#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(NULL), prev(NULL) {}
};

class DoublyLinkedList {
private:
    Node* head = NULL;

public:
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head) {
            head->prev = newNode;
            newNode->next = head;
        }
        head = newNode;
        display();
    }

    void deleteNode(int value) {
        for (Node* cur = head; cur; cur = cur->next) {
            if (cur->data == value) {
                if (cur->prev) cur->prev->next = cur->next;
                if (cur->next) cur->next->prev = cur->prev;
                if (cur == head) head = cur->next;
                delete cur;
                break;
            }
        }
        display();
    }

    void display() const {
        for (Node* cur = head; cur; cur = cur->next)
            std::cout << cur->data << " ";
        std::cout << std::endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;
    int choice, value;
    do {
        std::cout << "Menu:\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ";
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

