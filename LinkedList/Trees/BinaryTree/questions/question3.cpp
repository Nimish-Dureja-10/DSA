// Given the root of Binary tree, imagine yourself standing at the right side of it
// return the values of the nodes you can see from top to bottom.
// We need to print the right most element at each level.

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

vector<int> rightViewBinaryTree(Node* root) {
    vector<int> ans;
    if(root==NULL) {
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int nodesAtCurrLevel = q.size();
        while(nodesAtCurrLevel) {
            Node* currNode = q.front();
            q.pop();
            if(nodesAtCurrLevel==1) {
                ans.push_back(currNode->value);
            }
            if(currNode->left) {
                q.push(currNode->left);
            }
            if(currNode->right) {
                q.push(currNode->right);
            }
            nodesAtCurrLevel--;
        }
    }
    return ans;
}

int main() {
    Node* rootNode = new Node(2);
    rootNode->left = new Node(4);
    rootNode->right = new Node(10);
    rootNode->left->left = new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right->right = new Node(11);
    rootNode->left->left->right = new Node(12);
    vector<int> ans = rightViewBinaryTree(rootNode);
    for(int i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}