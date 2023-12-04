// Given the binary tree, print the top view of the binary tree.
// Top view of the binary tree is the set of nodes visible when the 
// tree is viewed from top.

// To solve this problem we need to consider this tree column wise.
// and we need to print the first element of each column.

#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

vector<int> topViewBinaryTree(Node* root) {
    vector<int> ans;
    if(root == NULL) {
        return ans;
    }
    queue<pair <Node*,int> > q;
    // In this map we will store the first value we get for each column.
    map<int,int> m;

    // Here we added root node to queue and its column number is 0.
    q.push(make_pair(root,0));
    while(!q.empty()) {
        int nodesAtCurrLevel = q.size();
        while(nodesAtCurrLevel--) {
            // this will return Node and column number.
            pair<Node*,int> p = q.front();
            // this holds the value of top node in queue.
            Node* currNode = p.first;
            // this holds the column no of the top node in the queue.
            int currColumn = p.second;
            q.pop();
            // this will check for if a value if already present at currCol No.
            // it yes it will skip else insert it the value in front of the col no.
            if(m.find(currColumn)==m.end()){
                m[currColumn] = currNode->value;
            }
            // check for left child of currNode and insert it in queue with its col no.
            if(currNode->left) {
                q.push(make_pair(currNode->left,currColumn-1));
            }
            // check for right child of currNode and insert it in queue with its col no.
            if(currNode->right) {
                q.push(make_pair(currNode->right,currColumn+1));
            }
        }
    }
    // adding the value at each column in ans vector.
    for(auto it:m) {
        ans.push_back(it.second);
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
    vector<int> ans = topViewBinaryTree(rootNode);
    for(int i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}