#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (!root || key == root->data) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key) {
    while (root) {
        if (key == root->data) return root;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* target = searchIterative(root, key);
    if (!target) return NULL;

    if (target->right)
        return findMin(target->right);

    Node* succ = NULL;
    while (root) {
        if (key < root->data) {
            succ = root;
            root = root->left;
        } else if (key > root->data)
            root = root->right;
        else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* target = searchIterative(root, key);
    if (!target) return NULL;

    if (target->left)
        return findMax(target->left);

    Node* pred = NULL;
    while (root) {
        if (key > root->data) {
            pred = root;
            root = root->right;
        } else if (key < root->data)
            root = root->left;
        else break;
    }
    return pred;
}

int main() {
    Node* root = NULL;
    int arr[] = {20, 10, 30, 5, 15};
    for (int x : arr) root = insert(root, x);

    cout << "Min = " << findMin(root)->data << endl;
    cout << "Max = " << findMax(root)->data << endl;

    Node* s = inorderSuccessor(root, 10);
    cout << "Successor of 10 = " << (s ? s->data : -1) << endl;

    Node* p = inorderPredecessor(root, 10);
    cout << "Predecessor of 10 = " << (p ? p->data : -1) << endl;
}

