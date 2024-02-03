// Given the binary tree, print the level order traversal of the binary tree in reverse.
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

void reverseOfLevelOrderTraversal(Node* root) {
    if(root==NULL) {
        return;
    }
    queue<Node*> q;
    stack<int> s;
    q.push(root);
    while(!q.empty()){
        int nodesAtCurrLevel = q.size();
        while(nodesAtCurrLevel--) {
            Node* currNode = q.front();
            q.pop();
            s.push(currNode->value);
            if(currNode->right) {
                q.push(currNode->right);
            }
            if(currNode->left) {
                q.push(currNode->left);
            }
        }
    }
    while(!s.empty()){
        int value = s.top();
        cout<<value<<" ";
        s.pop();
    }
}

int main() {
    Node* rootNode = new Node(2);
    rootNode->left = new Node(4);
    rootNode->right = new Node(10);
    rootNode->left->left = new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right->right = new Node(11);
    rootNode->left->left->right = new Node(12);
    reverseOfLevelOrderTraversal(rootNode);
    return 0;
}