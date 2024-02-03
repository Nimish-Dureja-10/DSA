#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int value;
    Node* left;
    Node* right;

    Node(int v){
        value = v;
        left = right = NULL;
    }
};

void levelOrderTraversal(Node* rootNode){
    // Base condition - terminate when rootNode is null
    if(rootNode == NULL) {
        return;
    }
    // create a queue to store node at different levels
    queue<Node*> q;
    q.push(rootNode);
    // this will iterate till at the nodes are covered for level order traversal.
    while(!q.empty()){
        // it will iterate for all the nodes at a level
        int nodesAtCurrentLevel = q.size();
        while(nodesAtCurrentLevel--) {
            Node* currNode = q.front();
            q.pop();
            cout<<currNode->value<<" ";
            // storing the left child of current node in the queue.
            if(currNode->left){
                q.push(currNode->left);
            }
            // storing the right child of current node in the queue.
            if(currNode->right) {
                q.push(currNode->right);
            }
        }
        cout<<endl;
    }
}

int main(){
    Node* rootNode = new Node(2);
    rootNode->left = new Node(4);
    rootNode->right = new Node(10);
    rootNode->left->left = new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right->right = new Node(11);
    cout<<"Level Order Traversal"<<endl;
    levelOrderTraversal(rootNode);
    return 0;
}