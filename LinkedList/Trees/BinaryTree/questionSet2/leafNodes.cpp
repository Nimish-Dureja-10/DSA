#include <iostream>
using namespace std;

class Node {
    public:
    int value;
    Node* left;
    Node* right;

    Node(int v) {
        value = v;
        left = right = NULL;
    }
};

int leafNode(Node* root) {
    if(root==NULL) {
        return 0;
    }
    if(root->left == NULL && root->right == NULL) {
        return 1;
    }

    int leftLeafNodes = leafNode(root->left);
    int rightLeafNodes = leafNode(root->right);
    return leftLeafNodes+rightLeafNodes;
}

int main() {
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->right->right = new Node(11);
    root->right->left = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    root->left->right->right = new Node(16);
    cout<<leafNode(root)<<endl;
    return 0;
}