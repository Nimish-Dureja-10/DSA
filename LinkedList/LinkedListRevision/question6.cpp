/*
Q6) detect whether there is a cycle in linked list or not
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

bool detectCycle(Node* head) {
    
    if(!head) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast) {
            cout<<"Value at which cycle is found: "<<slow -> val<<endl;
            return true;
        }
    }

    return false;
}

/*
Q6 b) remove cycle from linked list time complexity - O(n)
*/
void removeCycle(Node* &head) {
    Node* slow = head;
    Node* fast = head;

    do
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    } while (slow != fast);

    fast = head;
    while(slow -> next != fast -> next) {
        slow = slow -> next;
        fast = fast -> next;
    }

    slow -> next = NULL;
}

int main() {
    Node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    head -> next -> next -> next -> next -> next = head -> next -> next -> next ;
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    display(head);
    cout<<detectCycle(head)<<endl;
    return 0;
}