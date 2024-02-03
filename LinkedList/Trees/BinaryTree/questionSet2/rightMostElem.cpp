#include <iostream>
#include <queue>
#include <vector>
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

vector<int> rightMostElem(Node* root,vector<int> &ans) {
    if(root==NULL) {
        return ans;
    }

    if(root->left == NULL && root->right==NULL) {
        ans.push_back(root->value);
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
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

vector<int> leftMostElem(Node* root,vector<int> &ans) {
    if(root==NULL) {
        return ans;
    }

    if(root->left == NULL && root->right==NULL) {
        ans.push_back(root->value);
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int nodesAtCurrLevel = q.size();
        while(nodesAtCurrLevel) {
            Node* currNode = q.front();
            q.pop();
            if(nodesAtCurrLevel==1) {
                ans.push_back(currNode->value);
            }
            if(currNode->right) {
                q.push(currNode->right);
            }
            if(currNode->left) {
                q.push(currNode->left);
            }
            nodesAtCurrLevel--;
        }
    }
    return ans;
}

int main() {
    vector<int> ans;
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->right->right = new Node(11);
    root->right->left = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    root->left->right->right = new Node(16);
    ans = rightMostElem(root,ans);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    cout<<"Left Most Nodes"<<endl;
    ans = leftMostElem(root,ans);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}