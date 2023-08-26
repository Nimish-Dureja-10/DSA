/*
Q5) find the middle element of linked list using slow and fast pointer
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
    Node* temp = head;
    int len = 0;
    while(temp != NULL) {
        len++;
        temp = temp -> next;
    }
    return len;
}

void middleElem(Node* &head) {
    Node* slow = head;
    Node* fast = head;
    int len = getLen(head);
    
    while(fast != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
    }
    if(len % 2 == 0) {
        cout<<"Value of middle element of Linked List "<<slow -> next -> val<<endl;
    }else{
        cout<<"Value of middle element of Linked List "<<slow -> val<<endl;
    }
}

int main() {
    Node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);
    middleElem(head);
    return 0;
}