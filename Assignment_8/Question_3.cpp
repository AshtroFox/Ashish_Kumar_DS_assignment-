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


Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}


Node* deleteNode(Node* root, int key) {
    if (!root) return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* t = root->right;
            delete root;
            return t;
        }
        if (!root->right) {
            Node* t = root->left;
            delete root;
            return t;
        }
        Node* succ = findMin(root->right);
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}


int maxDepth(Node* root) {
    if (!root) return 0;
    int L = maxDepth(root->left);
    int R = maxDepth(root->right);
    return max(L, R) + 1;
}


int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return minDepth(root->right) + 1;
    if (!root->right) return minDepth(root->left) + 1;
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

int main() {
    Node* root = NULL;
    int arr[] = {20, 10, 30, 5, 15};
    for (int x : arr) root = insert(root, x);

    cout << "Max depth = " << maxDepth(root) << endl;
    cout << "Min depth = " << minDepth(root) << endl;

    root = deleteNode(root, 10);
    cout << "Deleted 10. New max depth = " << maxDepth(root) << endl;
}

