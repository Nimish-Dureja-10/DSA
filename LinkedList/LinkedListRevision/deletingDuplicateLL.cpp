// Deleting duplicate elements from sorted linked list
#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int data) {
        this -> val = data;
        this -> next = NULL;
    }
};

class LinkedList{
    public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insertAtTail(int val) {
        Node* new_node = new Node(val);
        if(head == NULL) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp -> next;
        }
        temp -> next = new_node;
    }


    void display(Node* head) {
        if(head == NULL) {
            cout<<"Linked List is empty"<<endl;
            return;
        }else {
            Node* temp = head;
            while(temp!=NULL) {
                cout<<temp -> val<<"->";
                temp = temp -> next;
            }
            cout<<"NULL"<<endl;
        }
    }
};

int main() {
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(3);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.display(ll.head);
    return 0;
}