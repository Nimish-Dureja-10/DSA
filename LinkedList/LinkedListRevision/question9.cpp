/*
Q9) reaarange the linked list in such a manner that all the odd indices nodes
are arranged at the start followed by even indices nodes.
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

//time complexity - O(n)
void rearrangeNodes(Node* &head) {
    if(!head) {
        return;
    }
    Node* evenHead = head -> next;
    Node* odd = head;
    Node* even = head -> next;

    while(even && even -> next) {
        odd -> next = odd -> next -> next;
        even -> next = even -> next -> next;
        odd = odd -> next;
        even = even -> next;
    }

    odd -> next = evenHead;
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
    rearrangeNodes(head);
    display(head);
    return 0;
}