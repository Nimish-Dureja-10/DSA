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

int maxDepth(Node* root) {
    if(root==NULL) {
        return 0;
    }

    int maxDepthLeft = maxDepth(root->left);
    int maxDepthRight = maxDepth(root->right);
    return max(maxDepthLeft,maxDepthRight)+1;
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
    cout<<maxDepth(root)<<endl;
    return 0;
}