#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int value;
    Node* left;
    Node* right;

    Node(int v) {
        value = v;
        left = right = NULL;
    }
};

void preorderTraversal(Node* rootNode){
    //base case
    if(rootNode==NULL) {
        return;
    }
    cout<<rootNode->value<<" ";
    //recursive call for its left and right subtree
    preorderTraversal(rootNode->left);
    preorderTraversal(rootNode->right);
}

void inorderTraversal(Node* rootNode) {
    //base case
    if(rootNode==NULL) {
        return;
    }
    //recursive call for left subtree
    inorderTraversal(rootNode->left);
    cout<<rootNode->value<<" ";
    //recursive call for right subtree
    inorderTraversal(rootNode->right);
}

void postorderTraversal(Node* rootNode) {
    //base case
    if(rootNode==NULL) {
        return;
    }
    //recursive call for left and right subtree
    postorderTraversal(rootNode->left);
    postorderTraversal(rootNode->right);
    cout<<rootNode->value<<" ";
}

void levelOrderTraversal(Node* rootNode) {
    if(rootNode==NULL) {
        return;
    }
    queue<Node*> q;
    q.push(rootNode);

    while(!q.empty()) {
        int nodesAtCurrentLevel = q.size();
        //this while loop helps to print in different lines according to the level.
        while(nodesAtCurrentLevel--) {
            //it will store the current pointing node
            Node* currNode = q.front();
            //poping first element so that we can check for next nodes
            q.pop();
            cout<<currNode->value<<" ";
            //checking for left child of current node. If present pushing in queue.
            if(currNode->left) {
                q.push(currNode->left);
            }
            //checking for right child of current node. If present pushing in queue.
            if(currNode->right) {
                q.push(currNode->right);
            }
        }
        cout<<endl;
    }
}

int main() {
    Node* rootNode = new Node(2);
    rootNode->left = new Node(4);
    rootNode->right = new Node(10);
    rootNode->left->left = new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right->right = new Node(11);
    cout<<"Preorder Traversal"<<endl;
    preorderTraversal(rootNode);
    cout<<endl;
    cout<<"Inorder Traversal"<<endl;
    inorderTraversal(rootNode);
    cout<<endl;
    cout<<"Postorder Traversal"<<endl;
    postorderTraversal(rootNode);
    cout<<endl;
    cout<<"Levelorder Traversal"<<endl;
    levelOrderTraversal(rootNode);
    // cout<<endl;
    return 0;
}