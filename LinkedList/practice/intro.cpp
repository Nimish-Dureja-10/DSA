/*
    Linear Data Structure, it is collection of nodes.
    node consist of data and address of next node.
    dynamic data structure, it can grow/shrink during runtime.
    no memory wastage
    easy shifting of elemnets.
    no requirement of continuous memory.
*/
//Insertion and Deletion at any position in Singly Linked List.
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    //destructor
    ~Node(){
        int val = this -> data;
        //memory free
        if(this->next!=NULL){
            delete next;
            this -> next = NULL;
        }
    cout<<"Memory free for node with data "<<val<<endl;
    }
};

//we are taking reference because we don't want to make copy of linked list.
void insertAtHead(Node* &head,Node* &tail,int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }else{
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node* &head,Node* &tail,int d){
    if(tail==NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }else{
        Node* temp = new Node(d);
        tail->next= temp;
        tail = tail->next;
    }
}

void insertAtPosition(Node* &head,Node* &tail,int pos,int d){
    //Insert at starting
    if(pos == 1){
        insertAtHead(head,tail,d);
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
    //Inserting at Last.
    if(temp->next==NULL){
        insertAtTail(head,tail,d);
        return;
    }
    //Inserting at mid postion.
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head,Node* &tail,int pos){
    // deleting a node at starting or head
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        //memory free start node
        temp->next = NULL;
        delete temp;
    }else{
        //deleting a node at middle or at last/tail.
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while(count < pos){
            prev = curr;
            curr = curr -> next;
            count++;
        }
        if(curr -> next == NULL){
            tail = prev;
        }  
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* newNode = new Node(10);
    // cout<<newNode->data<<endl;
    // cout<<newNode->next<<endl;
    Node* head = newNode;
    Node* tail = newNode;
    /*If Linked List is empty.
    Node* head = NULL;
    Node* tail = NULL;
    */
    insertAtHead(head,tail,6);
    print(head);
    insertAtTail(head,tail,12);
    print(head);
    insertAtTail(head,tail,15);
    print(head);
    insertAtPosition(head,tail,1,20);
    print(head);
    insertAtPosition(head,tail,5,25);
    print(head);
    deleteNode(head,tail,6);
    print(head);
     deleteNode(head,tail,5);
    print(head);
    cout<<"Length of Linked List: "<<getLength(head)<<endl;
    cout<<"head-> "<<head->data<<endl;
    cout<<"tail-> "<<tail->data<<endl;
    /*
    deleteNode(head,4);
    cout<<"Length of Linked List after deleting a node: "<<getLength(head)<<endl;
    print(head);
    */

    return 0;
}