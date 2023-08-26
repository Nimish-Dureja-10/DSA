/*
Q4) two sorted linked list are given, we need to merge them in such a manner
that the merged linked list is all sorted.
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

void sortedMergedLL(Node* head1,Node* head2) {
    Node* head=NULL;
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while(ptr1 != NULL && ptr2 != NULL) {
        if(ptr1 -> val < ptr2 -> val) {
            int data = ptr1 -> val;
            insertAtTail(head,data);
            ptr1 = ptr1 -> next;
        }else {
            int data = ptr2 -> val;
            insertAtTail(head,data);
            ptr2 = ptr2 -> next;
        }
        
    }

    while(ptr1 != NULL) {
        int data = ptr1 -> val;
        insertAtTail(head,data);
        ptr1 = ptr1 -> next;
    }

    while(ptr2 != NULL) {
        int data = ptr2 -> val;
        insertAtTail(head,data);
        ptr2 = ptr2 -> next;
    }

    display(head);
}

int main() {
    cout<<"Sorted Linked List 1"<<endl;
    Node* head1 = NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,5);
    insertAtTail(head1,7);
    insertAtTail(head1,11);
    display(head1);
    cout<<"Sorted Linked List 2"<<endl;
    Node* head2 = NULL;
    insertAtTail(head2,3);
    insertAtTail(head2,4);
    insertAtTail(head2,6);
    insertAtTail(head2,9);
    insertAtTail(head2,10);
    display(head2);
    cout<<"Sorted List after merging both the lists"<<endl;
    sortedMergedLL(head1,head2);
    // display(new_head);
    return 0;
}