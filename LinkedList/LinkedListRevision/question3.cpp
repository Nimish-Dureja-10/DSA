/*
Q3) Given head of linked list, need to delete kth node from the end of 
the linked list.
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

int getLength(Node* head) {
    Node* temp = head;
    int len = 0;
    while(temp != NULL) {
        len++;
        temp = temp -> next;
    }
    return len;
}

void deleteHead(Node* &head) {
    Node* temp = head;
    head = head -> next;
    free(temp);
}

void deleteKNodeFromEnd(Node* &head,int k) {
    int len = getLength(head);
    int diff = len - k;
    if(diff == 0) {
        deleteHead(head);
        return;
    }
    Node* temp = head;
    int counter = 0;
    while(counter < diff-1) {
        temp = temp -> next;
        counter++;
    }
    Node* nodeToDelete = temp -> next;
    temp -> next = temp -> next -> next;
    free(nodeToDelete);
}

int main() {
    Node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);
    display(head);
    deleteKNodeFromEnd(head,8);
    display(head);
    cout<<head-> val<<endl;
    return 0;
}