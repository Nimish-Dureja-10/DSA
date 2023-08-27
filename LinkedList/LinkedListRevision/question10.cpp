/*
Q10) reorder linked list in such a way that first node is followed by last node,
similarly second node is followed by second last node.
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

void reorderLL(Node* &head) {
    
    // 1. find middle element
    Node* slow = head;
    Node* fast = head;

    while(fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    // Now slow pointer is our middle node
    // 2. break the linked list in two parts
    Node* curr = slow -> next;
    Node* prev = slow;
    slow -> next = NULL;

    // 3. reverse the second half
    while(curr) {
        Node* forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    // merging two halves of linked list
    Node* ptr1 = head;
    Node* ptr2 = prev;

    while(ptr1 != ptr2) {
        Node* temp = ptr1 -> next;
        ptr1 -> next = ptr2;
        ptr1 = ptr2;
        ptr2 = temp;
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
    insertAtTail(head,7);
    insertAtTail(head,8);
    display(head);
    reorderLL(head);
    display(head);
    return 0;
}