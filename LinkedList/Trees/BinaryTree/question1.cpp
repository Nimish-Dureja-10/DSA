// Given the root of binary tree, return its maximum depth.
// The maximum depth of binary tree is the number of nodes along the longest
// path from root node to leaf node.

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
    //recursive call
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (max(leftDepth,rightDepth)+1);
} 

int main() {
    Node* rootNode = new Node(2);
    rootNode->left = new Node(4);
    rootNode->right = new Node(10);
    rootNode->left->left = new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right->right = new Node(11);
    int depth = maxDepth(rootNode);
    cout<<depth<<endl;
    return 0;
}