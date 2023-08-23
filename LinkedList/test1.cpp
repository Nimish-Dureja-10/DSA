// Reversing a linked list
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val) {
        this -> data = val;
        this -> next = NULL;
    }
};

void insertAtTail(Node* &head,Node* &tail,int d) {
    if(head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }else {
        Node* temp = new Node(d);
        tail -> next = temp;
        tail = temp;
    }
}

void print(Node* &head) {
    if(head == NULL) {
        cout<<"Linked List is empty"<<endl;
    }
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp -> data<<"->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

void reversingKGroupElem(Node* head,int k) {
    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL) {
        int count = 0;
        Node* start = curr;
        Node* end = NULL;

        while(curr != NULL && count < k) {
            Node* forward = curr -> next;
            curr -> next = end;
            end = curr;
            curr = forward;
            count++;
        }

        if(prev != NULL) {
            prev -> next = end;
        }else {
            head = end;
        }

        prev = start;
    }

    print(head);
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);
    print(head);
    cout<<"Head value -> "<<head->data<<endl;
    cout<<"Tail value -> "<<tail->data<<endl;
    int k;
    cout<<"Value of k ";cin>>k;
    reversingKGroupElem(head,k);
    return 0;
}