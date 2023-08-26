#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    }
};

//time complexity - O(1)
void insertAtHead(Node* &head,int val) {
    Node* new_node = new Node(val);
    new_node -> next = head;
    head = new_node;
}

//time complexity - O(n)
void insertAtTail(Node* &head,int val) {
    if(head == NULL) {
        insertAtHead(head,val);
    }else{
        Node* new_node = new Node(val);
        Node* temp = head;
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = new_node;
    }
}

//time complexity - O(n)
void insertAtPosition(Node* &head,int val,int pos) {
    if(pos == 0) {
        insertAtHead(head,val);
        return;
    }

    Node* new_node = new Node(val);
    Node* temp = head;
    int current_pos = 0;
    while(current_pos < pos-1) {
        temp = temp -> next;
        current_pos++;
    }
    new_node -> next  = temp -> next;
    temp -> next = new_node;
}

//time complexity - O(n)
void updateAtPosition(Node* &head,int val,int pos) {
    Node* temp = head;
    int curr_pos = 0;
    while(curr_pos != pos) {
        temp = temp -> next;
        curr_pos++;
    }
    temp -> val = val;
}

//time complexity - O(1)
void deleteAtHead(Node* &head) {
    Node* temp = head;
    head = head -> next;
    free(temp);
}

//time complexity - O(n)
void deleteAtTail(Node* &head) {
    Node* second_last = head;
    while(second_last -> next -> next != NULL){
        second_last = second_last -> next;
    }
    Node* temp = second_last -> next;
    second_last -> next = NULL;
    free(temp);
}

//time complexity - O(n)
void deleteAtPosition(Node* &head,int pos) {
    if(pos == 0) {
        deleteAtHead(head);
        return;
    }

    Node* prev = head;
    int curr_pos = 0;
    while(curr_pos != pos-1) {
        prev = prev -> next;
        curr_pos++;
    }

    //pointing at the node whose next node needs to be deleted
    Node* temp = prev -> next; // node to be deleted
    prev -> next = prev -> next -> next;
    free(temp);
}

// time complexity - O(n/2)
void deleteAlternativeNodes(Node* &head) {
    Node* curr = head;
    while(curr != NULL && curr->next != NULL) {
        Node* temp = curr -> next;
        curr -> next = curr -> next -> next;
        free(temp);
        curr = curr -> next;
    }
}

//time complexity - O(n)
void deleteDuplicateNodes(Node* &head){
    Node* curr = head;
    while(curr!=NULL && curr -> next != NULL){
        if(curr -> val == curr -> next -> val) {
            Node* temp = curr -> next;
            curr -> next = curr -> next -> next;
            free(temp);
        }else{
            curr = curr -> next;
        }
    }
}

void reversePrint(Node* head) {
    //base case
    if(head == NULL) {
        return;
    }

    //recursive case
    reversePrint(head -> next);
    cout<<head -> val<<" ";
}

void reverseLL(Node* &head) {
    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL) {
        Node* forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    head= prev;
}

Node* reverseLLRecursion(Node* &head) {

    //base case
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    //recursive case
    Node* new_head = reverseLLRecursion(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return new_head;
}


Node* reverseKLL(Node* &head,int k) {
    Node* curr = head;
    Node* prev = NULL;

    int counter = 0;

    //reversing first k nodes
    while(curr!=NULL && counter < k) {
        Node* forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        counter++;
    }

    // revering next k group of nodes only if nodes are last
    //here curr will give us (k+1)th node
    if(curr != NULL) {
        Node* new_head = reverseKLL(curr,k);
        head -> next = new_head;
    }

    return prev;
}

void display(Node* head) {
    Node* temp = head;
    while(temp!=NULL) {
        cout<<temp -> val<<"->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = NULL;
    /*
    insertAtHead(head,2);
    display(head);
    insertAtHead(head,1);
    display(head);
    insertAtTail(head,3);
    display(head);
    insertAtTail(head,4);
    display(head);
    insertAtTail(head,5);
    display(head);
    insertAtTail(head,6);
    display(head);
    insertAtTail(head,7);
    display(head);
    */
    // insertAtPosition(head,5,3);
    // display(head);
    // updateAtPosition(head,10,1);
    // display(head);
    // deleteAtHead(head);
    // display(head);
    // deleteAtHead(head);
    // display(head);
    // deleteAtTail(head);
    // display(head);
    // deleteAtTail(head);
    // display(head);
    // deleteAtPosition(head,3);
    // display(head);
    // deleteAtPosition(head,4);
    // display(head);
    // deleteAlternativeNodes(head);
    // display(head);
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,3);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);
    deleteDuplicateNodes(head);
    display(head);
    // reversePrint(head);
    // reverseLL(head);
    // cout<<endl;
    // display(head);
    // cout<<head -> val <<endl;
    // head = reverseLLRecursion(head);
    // display(head);
    Node* new_head = reverseKLL(head,4);
    display(new_head);
    return 0;
}