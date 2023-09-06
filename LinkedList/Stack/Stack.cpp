/*
Implementing stacks using arrays
*/
// LIFO - Last in fast out
#include <iostream>
using namespace std;

class Stack {
    //We are keeping the array as private so that nobody can access it.
    int capacity; //size of the stack
    int* arr;
    int top; //top index of stack
    public:
    Stack(int c) {
        this -> capacity = c;
        arr = new int[c];
        this -> top = -1;
    }

    //time complexity - O(1)
    void push(int data) {
        if(this->top == this->capacity-1) {
            cout<<"Overflow\n";
            return;
        }
        this->top++;
        this->arr[this->top] = data;
    }

    //time complexity - O(1)
    int pop() {
        if(this->top == -1) {
            cout<<"Underflow\n";
            return INT_MIN;
        }
        return this->top--;
    }

    //time complexity - O(1)
    int getTop() {
        if(this->top==-1) {
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        return this->arr[this->top];
    }

    //time complexity - O(1)
    bool isEmpty() {
        return this->top == -1;
    }

    //time complexity - O(1)
    int size() {
        return this->top+1;
    }

    //time complexity - O(1)
    bool isFull() {
        return this->top == this->capacity-1;
    }
};

int main() {
    Stack st(5);
    cout<<st.isEmpty()<<endl;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    cout<<st.getTop()<<endl;
    cout<<st.isEmpty()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<st.getTop()<<endl;
    
    return 0;
}