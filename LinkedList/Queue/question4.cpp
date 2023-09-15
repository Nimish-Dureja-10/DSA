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

    //time complexity - O(n)
    void push(int x) {
        if(this->st.empty()) {
            this->st.push(x);
        }else{
            stack<int> temp;
            while(!this->st.empty()) {
                int curr = this->st.top();
                st.pop();
                temp.push(curr);
            }
            st.push(x);
            while(!temp.empty()) {
                int curr = temp.top();
                temp.pop();
                st.push(curr);
            }
        }
    }

    //time complexity - O(1)
    void pop() {
        if(this->st.empty()) {
            return;
        }
        this -> st.pop();
    }

    //time complexity - O(1)
    int front() {
        if(this->st.empty()) return -1;
        return this->st.top();
    }

    //time complexity - O(1)
    bool empty() {
        return this->st.empty();
    }

    int queueSize() {
        return this -> st.size();
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