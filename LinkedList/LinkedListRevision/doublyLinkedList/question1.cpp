/*
Q1) given head of doubly linked list, delete the neighbouring nodes whose values are same
*/

#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int data) {
        val = data;
        next = NULL;
        prev = NULL;
    }
};

void insertAtTail(Node* &head,Node* &tail,int val) {
    Node* temp = new Node(val);
    if(head == NULL) {
        head = temp;
        tail = temp;
    }else{
        Node* curr = head;
        while(curr -> next != NULL) {
            curr = curr -> next;
        }
        curr -> next = temp;
        temp -> prev = curr;
        tail = temp;
    }
}

void deleteHead(Node* &head) {
    Node* temp = head;
    temp = temp -> next;
    free(head);
    temp -> prev = NULL;
    head = temp;
}

void deleteSameNeighbour(Node* &head,Node* &tail) {
    Node* temp = tail;
    while(temp -> prev != NULL) {
        if(temp -> val == temp -> prev -> val) {
            if(head == temp -> prev) {
                deleteHead(head);
                return;
            }
            Node* nodeToDelete = temp -> prev;
            temp -> prev = temp -> prev -> prev;
            temp -> prev -> next = temp;
            nodeToDelete -> next = NULL;
            nodeToDelete -> prev = NULL;
            free(nodeToDelete);
        }
        if(temp -> val != temp -> prev -> val) {
            temp = temp -> prev;
        }
    }
}

void display(Node* head) {
        Node* temp = head;
        cout<<"NULL<=>";
        while(temp!=NULL) {
            cout<<temp -> val<<"<=>";
            temp = temp -> next;
        }
        cout<<"NULL"<<endl;
    }

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);
    insertAtTail(head,tail,5);
    display(head);
    cout<<"Doubly Linked list after deleting same value neighbouring nodes"<<endl;
    deleteSameNeighbour(head,tail);
    display(head);
    cout<<head -> val<<endl;
    cout<<tail -> val<<endl;
    return 0;
}