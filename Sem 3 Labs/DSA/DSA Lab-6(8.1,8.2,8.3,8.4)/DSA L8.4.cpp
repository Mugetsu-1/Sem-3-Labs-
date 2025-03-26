//WAP DoublyCircularLinklist as ADT.
#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(this), prev(this) {}
};

class DoublyCircularLinkedList {
private:
    Node* head = NULL;

public:
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
        display();
    }

    void deleteNode(int value) {
        if (!head) return;
        Node* cur = head;
        do {
            if (cur->data == value) {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                if (cur == head) {
                    head = (head->next == head) ? NULL : head->next;
                }
                delete cur;
                break;
            }
            cur = cur->next;
        } while (cur != head);
        display();
    }

    void display() const {
        if (!head) return;
        Node* cur = head;
        do {
            std::cout << cur->data << " ";
            cur = cur->next;
        } while (cur != head);
        std::cout << std::endl;
    }

    ~DoublyCircularLinkedList() {
        if (head) {
            Node* cur = head;
            do {
                Node* nextNode = cur->next;
                delete cur;
                cur = nextNode;
            } while (cur != head);
        }
    }
};

int main() {
    DoublyCircularLinkedList list;
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

