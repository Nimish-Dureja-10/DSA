#include <iostream>
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

int main() {
    Node* root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(4);
    cout<<"Root Node: "<<root->value<<endl;
    cout<<"Left Child: "<<root->left->value<<"\n";
    cout<<"Right Child: "<<root->right->value<<"\n";
    return 0;
}