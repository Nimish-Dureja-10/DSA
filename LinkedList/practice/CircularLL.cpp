//Circular Linked List.
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    ~Node(){
        int val = this -> data;
        if(this->next!=NULL){
            delete next;
            next = NULL;
        }
        cout<<" memory is free for node with value: "<<val<<endl;
    }
};

void insertNode(Node* &tail,int element,int d){
    //List is empty
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    //assuming the element is present in the list.
    else{
        Node* curr = tail;
        while(curr -> data != element){
            curr = curr -> next;   
        }
        //element found and pointed by current(curr)
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }

}

void deleteNode(Node* &tail,int val){
    //empty list
    if(tail==NULL){
        cout<<"List is empty."<<endl;
        return;
    }else{
          Node* prev = tail;
          Node* curr = prev -> next;
          while(curr->data!=val){
              prev = curr;
              curr = curr -> next;
          }
          prev -> next = curr -> next;
          
          //Only 1 node is present in Linked list
          if(curr == prev){
              tail = NULL;
          }

          //2 or more then 2 nodes are present in Linked list
          else if(tail == curr){
              tail = prev;
          }
          
          curr -> next = NULL;
          delete curr; 
    }
}

void print(Node* tail){
    Node* temp = tail;
    if(tail == NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }
    do{
        cout<<tail->data<<" ";
        tail = tail ->next;
    }while(tail!=temp);
    cout<<endl;
}

int main(){
    Node* tail = NULL;
    insertNode(tail,3,2);
    print(tail);
    insertNode(tail,2,6);
    print(tail);
    insertNode(tail,2,4);
    print(tail);
    insertNode(tail,6,9);
    print(tail);
    deleteNode(tail,4);
    print(tail);
    deleteNode(tail,2);
    print(tail);
    
    return 0;
}