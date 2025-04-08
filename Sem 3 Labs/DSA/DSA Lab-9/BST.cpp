#include <iostream>

class BST {
private:
    class Node {  // Using class instead of struct
    public:
        int data;
        Node* left;
        Node* right;

        Node(int value) {
            data = value;
            left = right = NULL;
        }
    };

    Node* root;

    Node* insert(Node* node, int value) {
        if (node == NULL) return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        return node;
    }

    bool search(Node* node, int value) {
        if (node == NULL) return false;
        if (node->data == value) return true;
        if (value < node->data) return search(node->left, value);
        return search(node->right, value);
    }

    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() { root = NULL; }

    void insert(int value) { root = insert(root, value); }

    bool search(int value) { return search(root, value); }

    void inorder() {
        inorder(root);
        std::cout << std::endl;
    }
};

int main() {
    BST tree;
    int choice, value;

    do {
        std::cout << "\n1. Insert\n2. Search\n3. Inorder Traversal\n4. Exit\nEnter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                tree.insert(value);
                break;
            case 2:
                std::cout << "Enter value to search: ";
                std::cin >> value;
                if (tree.search(value)) std::cout << "Found\n";
                else std::cout << "Not Found\n";
                break;
            case 3:
                std::cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

