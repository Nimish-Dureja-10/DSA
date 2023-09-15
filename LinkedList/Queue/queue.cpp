/*
Queue is a linear data structure.
Queue if fifo/fcfs(first in first out/first come first serve)
Queue implementation using Linked List.
Queue implementation using Linked list is space efficient
*/

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int d) {
        this -> data = d;
        this -> next = NULL;
    }
};

class Queue {
    Node* head;
    Node* tail;
    int size;
    public:
    Queue() {
        this -> head = NULL;
        this -> tail = NULL;
        this -> size = 0;
    }

    //time complexity - O(1)
    void enqueue(int d) {
        Node* newNode = new Node(d);
        //Linked list is empty
        if(this -> head == NULL) {
            this -> head = this -> tail = newNode;
        }else {
            this -> tail -> next = newNode;
            this -> tail = newNode; 
        }
        this -> size++;
    }

    //time complexity - O(1)
    void dequeue() {
        if(this -> head == NULL) {
            cout<<"Underflow\n";
            return;
        }else {
            Node* oldHead = this -> head;
            Node* newHead = this -> head -> next;
            this -> head = newHead;
            if(this -> head == NULL) this -> tail = NULL;
            oldHead -> next = NULL;
            delete oldHead;
            this -> size--;
        }
    }

    //time complexity - O(1)
    int getSize() {
        return this->size;
    }

    //time complexity - O(1)
    bool isEmpty() {
        return this -> head == NULL;
    }

    //time complexity - O(1)
    int front() {
        if(this -> head != NULL) {
            return this->head->data;
        }
        return -1;
    }
};

int main() {
    Queue qu;
    qu.dequeue();
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.dequeue();
    qu.enqueue(40);
    qu.enqueue(50);
    while(!qu.isEmpty()) {
        cout<<qu.front()<<" ";
        qu.dequeue();
    }
    cout<<endl;
    return 0;
}