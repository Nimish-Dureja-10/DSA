// Two linked list are given and need to check that both the linked list have 
// same value and same arrangement
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

int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp -> next;
    }
    return len;
}

void checkBothLL(Node* head1,Node* head2){
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    if(len1 != len2) {
        cout<<"Both Linked List are not same in length"<<endl;
    }else{
        Node* temp1 = head1;
        Node* temp2 = head2;
        bool flag = false;
        while(temp1 != NULL) {
            if(temp1-> val == temp2 -> val){
                flag = true;
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }else{
                flag = false;
                break;
            }
        }
        if(flag) {
            cout<<"Linked List are same"<<endl;
        }else{
            cout<<"Linked List are of same length but not values or arrangement"<<endl;
        }
    }
}

//maam's method (more optimized way) time complexity - O(n)
bool checkBothLL2(Node* head1,Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1!=NULL && temp2!=NULL) {
        if(temp1->val != temp2->val){
            return false;
        }
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }

    return (temp1 == NULL && temp2 == NULL);
}

// Question 2 - Two linked list are give, need to find intersection point between
// two linked list if exists otherwise return -1

Node* moveAhead(Node* head, int k) {
    Node* ptr = head;
    while(k--){
        ptr = ptr -> next;
    }
    return ptr;
}

Node* intersectionPoint(Node* headA,Node* headB) {
    // calculate length of both linked list
    int l1 = getLength(headA);
    int l2 = getLength(headB);

    Node* ptr1,*ptr2;
    //find difference between both linked list and move ptr of longer LL
    if(l1>l2) {
        int k = l1-l2;
        ptr1 = moveAhead(headA,k);
        ptr2 = headB;
    }else{
        int k = l2 - l1;
        ptr1 = headA;
        ptr2 = moveAhead(headB,k);
    }
    
    while(ptr1) {
        if(ptr1 == ptr2) {
            return ptr1;
        }
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    return NULL;
}

int main(){
    cout<<"First Linked List"<<endl;
    Node* head1 = NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    display(head1);
    cout<<"Second Linked List"<<endl;
    Node* head2 = NULL;
    insertAtTail(head2,1);
    insertAtTail(head2,2);
    insertAtTail(head2,3);
    insertAtTail(head2,4);
    insertAtTail(head2,5);
    /*
    Q1)
    checkBothLL(head1,head2);
    cout<<checkBothLL2(head1,head2)<<endl;
    */
    /*
    Q2)
    insertAtTail(head2,6);
    insertAtTail(head2,7);
    head2 -> next -> next = head1 -> next -> next -> next;
    display(head2);
    Node* intersection =  intersectionPoint(head1,head2);
    if(intersection) {
        cout<<intersection -> val<<endl;
    }else{
        cout<<"-1"<<endl;
    }
    */
   
    return 0;
}