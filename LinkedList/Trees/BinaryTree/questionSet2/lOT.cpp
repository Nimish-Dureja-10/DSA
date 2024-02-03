#include <iostream>
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

void levelOrderTraversal(Node* root) {
    if(root==NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int nodesAtCurrNode = q.size();
        while(nodesAtCurrNode--) {
            Node* currNode = q.front();
            q.pop();
            cout<<currNode->value<<" ";
            if(currNode->left) {
                q.push(currNode->left);
            }
            if(currNode->right) {
                q.push(currNode->right);
            }
        }
        cout<<"\n";
    }
}

int main() {
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->right->right = new Node(11);
    root->right->left = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    levelOrderTraversal(root);
    return 0;
}