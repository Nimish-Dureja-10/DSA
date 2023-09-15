/*
We are given a stack data structure with push and pop functionality 
the task is to implement queue data structure using instance of stack
data structure and operations on them.

-> "Push efficient way"
*/

#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> st;
    public:
    Queue() {}

    //time complexity - O(1)
    void push(int x) { //queue enqueue
        this -> st.push(x);
    }

    //time complexity - O(n)
    void pop() {
        if(this->st.empty()) {
            cout<<"Underflow\n";
            return;
        }
        stack<int> temp;
        while(!this->st.empty()) {
            int curr = st.top();
            this -> st.pop();
            temp.push(curr);
        }
        temp.pop();
        while(!temp.empty()) {
            int curr = temp.top();
            temp.pop();
            this->st.push(curr);
        }
    }

    //time complexity - O(1)
    bool empty() {
        return this->st.empty();
    }

    //time complexity - O(n)
    int front() {
        stack<int> temp;
        while(!this->st.empty()) {
            int curr = st.top();
            this -> st.pop();
            temp.push(curr);
        }
        int result = temp.top();
        while(!temp.empty()) {
            int curr = temp.top();
            temp.pop();
            this->st.push(curr);
        }
        return result;
    }
};


int main() {
    Queue qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.pop();
    qu.push(50);
    qu.pop();
    qu.push(10);
    while(!qu.empty()) {
        cout<<qu.front()<<" ";
        qu.pop();
    }
    return 0;
}