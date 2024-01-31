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

int pathSumHelper(Node* root,int targetSum,long int currSum,unordered_map<long int,int> pathCount){
    if(root==NULL) {
        return 0;
    }
    currSum += root->value;
    int ansCount = pathCount[currSum-targetSum];
    pathCount[currSum]++;
    ansCount += pathSumHelper(root->left,targetSum,currSum,pathCount);
    ansCount += pathSumHelper(root->right,targetSum,currSum,pathCount);
    // while backtracking
    pathCount[currSum]--; // Very Important step. It indicates that this is no longer part of our path.
    return ansCount;
}

int pathSum(Node* root,int targetSum){
    // unordered map holds sum - frequency
    unordered_map<long int,int> pathCount;
    // setting first value as 0.
    pathCount[0] = 1;
    return pathSumHelper(root,targetSum,0,pathCount);

}

int main() {
    Node* rootNode = new Node(10);
    rootNode->left = new Node(5);
    rootNode->right = new Node(-3);
    rootNode->left->left = new Node(3);
    rootNode->left->right = new Node(2);
    rootNode->right->right = new Node(11);
    rootNode->left->left->right = new Node(12);
    rootNode->left->left->left = new Node(3);
    rootNode->left->left->right = new Node(-2);
    rootNode->left->right->right = new Node(1);
    int targetSum = 8;
    int noOfPaths = pathSum(rootNode,targetSum);
    cout<<noOfPaths<<endl;
    return 0;
}