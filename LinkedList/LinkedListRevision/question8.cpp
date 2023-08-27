/*
Q8) rotate k node of linked list
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

int getLen(Node* head) {
    int len = 0;
    Node* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp -> next;
    }
    return len;
}

void rotateKNodes(Node* &head,int k) {
    int diff = getLen(head) - k;
    Node* temp = head;
    Node* curr = head;
    int counter = 0;
    while(counter < diff-1) {
        temp = temp -> next;
        counter++;
    }
    
    Node* prev = temp -> next;

    while(curr -> next != NULL) {
        curr = curr -> next;
    }

    curr -> next = head;

    temp -> next = NULL;
    head = prev;
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
    rotateKNodes(head,2);
    display(head);
    return 0;
}