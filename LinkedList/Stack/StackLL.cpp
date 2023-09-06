// LIFO - Last in fast out
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

class Stack {
    Node* head;
    int capacity;
    int currSize;
    public:
    Stack(int c){
        this->capacity = c;
        currSize = 0;
        head = NULL;
    }

    // time complexity - O(1)
    bool isEmpty() {
        return this -> head == NULL;
    }

    // time complexity - O(1)
    bool isFull() {
        return this->currSize == this-> capacity-1; 
    }

    // time complexity - O(1)
    void push(int d) {
        if(this->currSize == this->capacity-1) {
            cout<<"Overflow\n";
            return;
        }
        Node* temp = new Node(d);
        temp -> next = this -> head;
        this -> head = temp;
        this -> currSize++;
        
    }

    // time complexity - O(1)
    int pop() {
        if(this->head == NULL) {
            cout<<"Underflow\n";
            return INT_MIN;
        }
        Node* new_head = this->head-> next;
        this-> head-> next = NULL;
        Node* toBeDeleted = this -> head;
        int result = this -> head -> data;
        delete toBeDeleted;
        this -> head = new_head;
        currSize--;
        return result;
    }

    // time complexity - O(1)
    int getTop() {
        if(this-> head ==NULL) {
            cout<<"Underflow\n";
            return INT_MIN;
        }
        return this -> head -> data;
    }

    // time complexity - O(1)
    int size() {
        return this -> currSize;
    }
    
};

int main() {
    Stack st(5);
    cout<<st.isEmpty()<<endl;
    st.push(1);
    st.push(2);
    cout<<st.size()<<endl;
    st.push(3);
    cout<<st.pop()<<endl;
    st.pop();
    st.pop();
    // cout<<st.getTop()<<endl;
    cout<<st.isEmpty()<<endl;

    return 0;
}