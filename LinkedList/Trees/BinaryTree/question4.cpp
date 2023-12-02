// Given the binary tree, print the top view of the binary tree.
// Top view of the binary tree is the set of nodes visible when the 
// tree is viewed from top.

// To solve this problem we need to consider this tree column wise.
// and we need to print the first element of each column.

#include <iostream>
#include <vector>
#include <queue>
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



int main() {
    Node* rootNode = new Node(2);
    rootNode->left = new Node(4);
    rootNode->right = new Node(10);
    rootNode->left->left = new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right->right = new Node(11);
    rootNode->left->left->right = new Node(12);
    // vector<int> ans = rightViewBinaryTree(rootNode);
    // for(int i : ans) {
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    return 0;
}