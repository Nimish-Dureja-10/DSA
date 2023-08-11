#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        this -> data = val;
        this -> next = NULL;
    }    
};

//Approach 1
//time complexity - O(n)
//space complexity - O(1)
//Iterative approach
void reverseLL(Node* &head){
    if(head == NULL){
        cout<<"Linked list is empty";
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward; 
        head = prev;
    }
}

//Approach 2(recursive approach).
void recReverse1(Node* &head,Node* curr,Node* prev){
    //base case
    if(curr == NULL){
        head = prev;
        return;
    }
    Node* forward = curr -> next;
    recReverse1(head,forward,curr);
    curr -> next = prev;
}

Node* recReverseLL1(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    recReverse1(head,curr,prev);
    return head;
}

//Approach 3

Node* reverse2(Node* head){
    //base case
    //If linked list is empty or have only one node.
    if(head == NULL || head->next == NULL){
        return head;
    }

    //chotaHead woh pehle element ko chord kr jo LL banti hai uska head hai.
    Node* chotaHead = reverse2(head->next);
    head -> next -> next = head;
    head -> next = NULL;

    return chotaHead;

}


Node* recReverseLL2(Node* &head){
    return reverse2(head);
}


void insertAtTail(Node* &head,Node* &tail,int d){
    if(tail==NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }else{
        Node* temp = new Node(d);
        tail -> next = temp;
        tail = tail -> next;
    }

}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}


int main(){
    Node* tail = NULL;
    Node* head = NULL;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);
    cout << "Original Linked List: ";
    print(head);
    Node* prev = NULL;
    Node* curr = head;
    recReverse1(head,curr,prev);
    cout << "Reversed Linked List: ";
    print(head);
    head = recReverseLL2(head);
    cout << "Reversed Linked List: ";
    print(head);
    head = recReverseLL1(head);
    cout << "Reversed Linked List: ";
    print(head);
    reverseLL(head);
    cout << "Reversed Linked List: ";
    print(head);
    return 0;
}