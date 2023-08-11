//Doubly Linked List.
//Insertion and Deletion at any point.
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }

    ~Node(){
        int val = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
    cout<<"Memory free for node with data "<<val<<endl;
    }
};

void insertAtHead(Node* &head,Node* &tail,int val){
    //Empty List.
    if(head == NULL){
        Node* temp = new Node(val);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(val);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &head,Node* &tail,int val){
    if(tail == NULL){
        Node* temp = new Node(val);
        tail = temp;
        head = temp;
    }
    Node* temp = new Node(val);
    tail -> next = temp;
    temp ->next = NULL;
    tail = temp;
    
}

void insertAtPosition(Node* &head,Node* &tail,int pos,int val){
    int count = 1;
    if(pos == 1){
        insertAtHead(head,tail,val);
        return;
    }
    Node* temp = head;
    while(count<pos-1){
        temp = temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertAtTail(head,tail,val);
        return;
    }
    Node* nodeToInsert = new Node(val);
    nodeToInsert->next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next  = nodeToInsert;
    nodeToInsert -> prev = temp;

}

//Traversing Linked List
void print(Node* & head){
    Node* temp = head;
    // cout<<"NULL<=>";
    while(temp!=NULL){
        cout<<temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

//Deleting value in Doubly Linked List.
void deleteNode(Node* &head,Node* &tail,int pos){
    if(pos==1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        //deleting a node at middle or at last/tail.
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while(count < pos){
            prev = curr;
            curr = curr -> next;
            count++;
        }  
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        tail = prev;
        delete curr;
    }

}

//Finding length of Linked List.
int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

int main(){
    /*
    Node* newNode = new Node(10);
    Node* head = newNode;
    Node* tail = newNode;
    */
    Node* head = NULL;
    Node* tail = NULL;
    print(head);
    // cout<<getLength(head)<<endl;
    insertAtHead(head,tail,5);
    print(head);
    // cout<<"Length after inserting at head: "<<getLength(head)<<endl;
    cout<<"Value of head: "<<head->data<<endl;
    cout<<"Value of tail: "<<tail->data<<endl;
    insertAtTail(head,tail,20);
    print(head);
    cout<<"Value of head: "<<head->data<<endl;
    cout<<"Value of tail: "<<tail->data<<endl;
    insertAtTail(head,tail,30);
    print(head);
    cout<<"Value of head: "<<head->data<<endl;
    cout<<"Value of tail: "<<tail->data<<endl;
    insertAtTail(head,tail,35);
    print(head);
    cout<<"Value of head: "<<head->data<<endl;
    cout<<"Value of tail: "<<tail->data<<endl;
    insertAtPosition(head,tail,5,100);
    print(head);
    cout<<"Value of head: "<<head->data<<endl;
    cout<<"Value of tail: "<<tail->data<<endl;
    insertAtHead(head,tail,1);
    print(head);
    // cout<<"Length after inserting at head: "<<getLength(head)<<endl;
    cout<<"Value of head: "<<head->data<<endl;
    cout<<"Value of tail: "<<tail->data<<endl;
    cout<<getLength(head)<<endl;
    cout<<endl;
    cout<<"Linked List before deletion"<<endl;
    print(head);
    cout<<"Linked List before deletion"<<endl;
    deleteNode(head,tail,6);
    print(head);
    cout<<"Value of head: "<<head->data<<endl;
    cout<<"Value of tail: "<<tail->data<<endl;
    deleteNode(head,tail,5);
    print(head);
    cout<<"Value of head: "<<head->data<<endl;
    cout<<"Value of tail: "<<tail->data<<endl;

    return 0;
}