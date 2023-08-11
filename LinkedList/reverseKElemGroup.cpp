//reverse linked list of k element groups.
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int d) {
        this -> data = d;
        this -> next = NULL;
    }
};

void insertAtTail(Node* &head,Node* &tail,int val) {
    if(head == NULL) {
        Node* newNode = new Node(val);
        head = newNode;
        tail = newNode;
    }else{
        Node* temp = new Node(val);
        tail -> next = temp;
        tail = temp;
    }
}

void print(Node* head) {
    if (head == NULL) {
        cout<<"Linked List is empty"<<endl;
    }
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<"->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n,x,k;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>x;
        insertAtTail(head,tail,x);
    }
    print(head);
    cout<<"Enter "
    cin>>k;
    return 0;
}