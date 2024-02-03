#include <iostream>
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
        left = right = nullptr;
    }
};

void reverseBinaryTree(Node* root) {
    if(root==NULL) {
        return;
    }
    stack<int> s;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int nodesAtCurrLevel = q.size();
        while(nodesAtCurrLevel--) {
            Node* currNode = q.front();
            q.pop();
            s.push(currNode->value);
            if(currNode->left) {
                q.push(currNode->left);
            }
            if(currNode->right) {
                q.push(currNode->right);
            }
        }
    }
    while(!s.empty()){
        int value = s.top();
        cout<<value<<" ";
        s.pop();
    }
    cout<<endl;
}

int main() {
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->right->right = new Node(11);
    root->right->left = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    reverseBinaryTree(root);
    return 0;
}