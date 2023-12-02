// Given the root of a binary tree, return the no of leaf nodes present in it
// A leaf node is a node which do not have left and right node.

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
    if(root==NULL){
        return 0;
    }
    if(root->left == NULL && root->right==NULL) {
        return 1;
    }
    // recursive call
    int leftSubtreeLeafNodes = leafNode(root->left);
    int rigthSubtreeLeafNodes = leafNode(root->right);

    return leftSubtreeLeafNodes+rigthSubtreeLeafNodes;

}

int main() {
    Node* rootNode = new Node(2);
    rootNode->left = new Node(4);
    rootNode->right = new Node(10);
    rootNode->left->left = new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right->right = new Node(11);
    cout<<leafNode(rootNode)<<endl;
    return 0;
}