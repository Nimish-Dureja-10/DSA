/*
Q7 Given a head of linked list, check whether it is a palindrome or not.
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

bool palindrome(Node* head) {

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

    // 4. compare both the linked list
    Node* head1 = head;
    Node* head2 = prev;

    while(head2) {
        if(head1 -> val != head2 -> val) {
            return false;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    return true;
}

int main() {
    Node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtTail(head,2);
    insertAtTail(head,1);
    display(head);
    cout<<palindrome(head)<<endl;
    return 0;
}