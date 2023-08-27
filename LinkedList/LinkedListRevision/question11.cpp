/*
Q11) swap adjacent nodes of linked list
*/

#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int d){
        val = d;
        next = NULL;
    }
};

void insertAtTail(Node* &head,int d) {
    Node* new_node = new Node(d);
    if(head == NULL) {
        head = new_node;
    }else{
        Node* temp = head;
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = new_node;
    }
}

void display(Node* head) {
    if(head == NULL) {
        cout<<"Linked List is empty"<<endl;
    }else{
        Node* temp = head;
        while(temp != NULL) {
            cout<<temp->val<<"->";
            temp = temp -> next;
        }
        cout<<"NULL"<<endl;
    }
}

Node* swapAdjacent(Node* &head) {
    //base case
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    //recursive case
    Node* secondNode = head -> next;
    head -> next = swapAdjacent(secondNode -> next);
    secondNode -> next = head;
    return secondNode;
}

int main() {
    Node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head); 
    Node* new_head = swapAdjacent(head);
    display(new_head);
    return 0;
}