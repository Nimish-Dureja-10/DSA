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

void insertAtTail(Node* &head,Node* &tail,int val){
    if(head == NULL) {
        Node* newNode = new Node(val);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* temp = new Node(val);
        tail -> next = temp;
        tail = tail -> next;
    }
}

int getLength(Node* &head) {
    int len = 0;
    if(head==NULL) {
        return 0;
    }else if(head -> next == NULL) {
        len = 1;
        return len;
    }else{
        Node* temp = head;
        while(temp != NULL) {
            len++;
            temp = temp -> next;
        }
        return len;
    }
}

//time complexity of this solution is o(n)
void getMiddleElement(Node* &head,int total) {
    if(total == 0) {
        cout<<"Linked List is empty"<<endl;
        return;
    }
    int mid = (total/2)+1;
    int cnt = 1;
    Node* temp = head;
    while(cnt<mid) {
        temp = temp -> next;
        cnt++;
    }
    cout<<"Value of middle element of Linked list is: "<<temp -> data <<endl;
}

void print(Node* head) {
    if(head==NULL) {
        cout<<"Linked List is empty"<<endl;
    }else{
        Node* temp = head;
        while(temp != NULL) {
            cout<<temp -> data << "->";
            temp = temp -> next;
        }
        cout<<"NULL"<<endl;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);
    cout<<"Orginal Linked List: ";
    print(head);
    int z = getLength(head);
    getMiddleElement(head,z);
    return 0;
}