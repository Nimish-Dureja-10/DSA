#include <iostream>
#include <queue>
#include <vector>
#include <map>
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

vector<int> topViewBT(Node* root,vector<int> &ans) {
    map<int,int> m;
    if(root==nullptr){
        return ans;
    }
    // Node - column
    queue<Node*,int> q;
    q.push(make_pair(root,0));
    while(!q.empty()) {
        int nodesAtCurrLevel = q.size();
        while(nodesAtCurrLevel--){
            pair<Node*,int> p = q.front();
            Node* currNode = p.first;
            int currCol = p.second;
            q.pop();
            if(m.find(currCol)==m.end()) {
                m[currCol] = currNode->value;
            }
            if(currNode->left){
                q.push(make_pair(currNode->left,currCol-1));
            }
            if(currNode->right){
                q.push(make_pair(currNode->right,currCol+1));
            }
        }
    }
    for(auto ele:m) {
        ans.push_back(ele.second);
    }
    return ans;
}


int main() {
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->right->right = new Node(11);
    root->right->left = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    vector<int> ans = topViewBT(root,ans);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}