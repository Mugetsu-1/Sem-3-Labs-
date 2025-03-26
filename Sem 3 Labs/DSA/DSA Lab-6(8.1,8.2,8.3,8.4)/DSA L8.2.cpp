//WAP to CircularLinkedList as ADT.
#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(NULL) {}
};

class CircularLinkedList {
private:
    Node* head = NULL;

public:
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        display();
    }

    void deleteNode(int value) {
        if (!head) return;
        if (head->data == value) {
            if (head->next == head) {
                delete head;
                head = NULL;
            } else {
                Node* temp = head;
                while (temp->next != head)
                    temp = temp->next;
                Node* toDelete = head;
                head = head->next;
                temp->next = head;
                delete toDelete;
            }
        } else {
            Node* cur = head;
            while (cur->next != head && cur->next->data != value)
                cur = cur->next;
            if (cur->next->data == value) {
                Node* toDelete = cur->next;
                cur->next = cur->next->next;
                delete toDelete;
            }
        }
        display();
    }

    void display() const {
        if (!head) return;
        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }

    ~CircularLinkedList() {
        if (!head) return;
        Node* cur = head;
        do {
            Node* nextNode = cur->next;
            delete cur;
            cur = nextNode;
        } while (cur != head);
    }
};

int main() {
    CircularLinkedList list;
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

