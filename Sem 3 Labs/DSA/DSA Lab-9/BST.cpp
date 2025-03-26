#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *left = NULL, *right = NULL;
    Node(int val) : data(val) {}
};

class BST {
    Node* root = NULL;
    vector<int> elements;

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        (val < node->data ? node->left : node->right) = insert(val < node->data ? node->left : node->right, val);
        return node;
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    void insert(int val) { root = insert(root, val); elements.push_back(val); }
    void display() { inorder(root); cout << endl; }
    void displayUnsorted() { for (size_t i = 0; i < elements.size(); i++) cout << elements[i] << " "; cout << endl; }
};

int main() {
    BST tree;
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    while (n-- && cin >> val) tree.insert(val);

    cout << "Unsorted list: "; tree.displayUnsorted();
    cout << "Inorder traversal: "; tree.display();
}

