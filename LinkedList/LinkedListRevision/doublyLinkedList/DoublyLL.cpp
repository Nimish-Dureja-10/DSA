#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* prev;
    Node* next;

    Node(int data) {
        val = data;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtHead(Node* &head,int val) {
        Node* temp = new Node(val);
        if(head == NULL) {
            head = temp;
            tail = temp;
        }else{
            head -> prev = temp;
            temp -> next = head;
            head = temp;
        }
    } 

    void insertAtTail(Node* &head,Node* &tail,int val) {
        Node* temp = new Node(val);
        if(head == NULL) {
            head = temp;
            tail = temp;
        }else{
            Node* curr = head;
            while(curr -> next != NULL) {
                curr = curr -> next;
            }
            curr -> next = temp;
            temp -> prev = curr;
            tail = temp;
        }
    }

    void insertAtPosition(Node* &head,Node* &tail,int val,int pos) {
        int counter = 1;
        Node* temp = head;
        if(pos == 1){
            insertAtHead(head,val);
            return;
        }
        while(counter < pos -1) {
            temp = temp -> next;
            counter++;
        }
        if(temp -> next == NULL) {
            insertAtTail(head,tail,val);
            return;
        }
        Node* new_node = new Node(val);
        new_node -> next = temp -> next;
        temp -> next = new_node;
        temp -> next -> prev = new_node; 
        new_node -> prev = temp;
        
    }

    void deleteHead(Node* &head) {
        Node* temp = head;
        temp = temp -> next;
        free(head);
        temp -> prev = NULL;
        head = temp;
    }

    void deleteTail(Node* &head,Node* &tail) {
        Node* temp = head;
        while(temp -> next !=NULL) {
            temp = temp -> next;
        }
        Node* new_tail = temp -> prev;
        new_tail -> next = NULL;
        free(temp);
        tail = new_tail;
    }

    void deleteAtPosition(Node* &head,Node* &tail,int pos) {
        int counter = 1;
        if(pos == 1) {
            deleteHead(head);
            return;
        }else{
            Node* temp = head;
            while(counter < pos-1) {
                temp = temp -> next;
                counter++;
            }
            if(temp -> next -> next == NULL) {
                deleteTail(head,tail);
                return;
            }else {
                Node* nodeToDelete = temp -> next;
                temp -> next = temp -> next -> next;
                temp -> next -> next -> prev = temp;
                nodeToDelete -> prev = NULL;
                nodeToDelete -> next = NULL;
                free(nodeToDelete);
            }
        }
    }

    void display(Node* head) {
        Node* temp = head;
        cout<<"NULL<=>";
        while(temp!=NULL) {
            cout<<temp -> val<<"<=>";
            temp = temp -> next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    Node* new_node = new Node(3);
    DoublyLinkedList dll;
    dll.head = new_node;
    dll.tail = new_node;
    // cout<<dll.head->val<<endl;
    dll.insertAtHead(dll.head,2);
    dll.insertAtHead(dll.head,1);
    // dll.display(dll.head);
    dll.insertAtTail(dll.head,dll.tail,4);
    dll.insertAtTail(dll.head,dll.tail,5);
    dll.insertAtTail(dll.head,dll.tail,6);
    // dll.display(dll.head);
    dll.insertAtPosition(dll.head,dll.tail,10,7);
    dll.display(dll.head);
    /*
    cout<<dll.tail -> val<<endl;
    dll.deleteHead(dll.head);
    dll.display(dll.head);
    cout<<dll.head -> val <<endl;
    dll.deleteTail(dll.head,dll.tail);
    dll.display(dll.head);
    cout<<dll.tail -> val<<endl;
    dll.deleteTail(dll.head,dll.tail);
    dll.display(dll.head);
    cout<<dll.tail -> val<<endl;
    dll.deleteAtPosition(dll.head,dll.tail,7);
    dll.display(dll.head);
    cout<<dll.tail -> val<<endl;
    dll.deleteAtPosition(dll.head,dll.tail,3);
    dll.display(dll.head);
    cout<<dll.tail -> val<<endl;
    */
    return 0;
}