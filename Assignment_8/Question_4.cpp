#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};


Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


Node* insert(Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data) 
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}


bool isBSTUtil(Node* root, Node* &prev) {
    if (root == NULL)
        return true;


    if (!isBSTUtil(root->left, prev))
        return false;


    if (prev != NULL && root->data <= prev->data)
        return false;

    prev = root;

    return isBSTUtil(root->right, prev);
}


bool isBST(Node* root) {
    Node* prev = NULL;
    return isBSTUtil(root, prev);
}

int main() {
    Node* root = NULL;


    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);

    if (isBST(root))
        cout << "The tree is a BST\n";
    else
        cout << "The tree is NOT a BST\n";

    return 0;
}

