/*
Reverse a stack at same memory address.(reverse same stack)
*/

#include <iostream>
#include <stack>
using namespace std;

//time complexity - O(n^2)
//space complexity - O(n)
void reverseStack(stack<int> &st) {
    stack<int> temp1;
    stack<int> temp2;
    while(!st.empty()) {
        int curr = st.top();
        st.pop();
        temp1.push(curr);
    }

    while(!temp1.empty()) {
        int curr = temp1.top();
        temp1.pop();
        temp2.push(curr);
    }

    while(!temp2.empty()) {
        int curr = temp2.top();
        temp2.pop();
        st.push(curr);
    }
    
}

//Approach 2.
void insertAtBottom(stack<int> &st,int val) {
    stack<int> temp;
    while(!st.empty()) {
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(val);
    while(!temp.empty()) {
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
}

//Approach 2.
void reverse(stack<int> &st) {
    if(st.empty()) return;
    int curr = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,curr);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(4);
    st.push(8);
    // reverseStack(st); Approach 1
    // reverse(st); Approach 2
    while(!st.empty()) {
        int curr = st.top();
        st.pop();
        cout<<curr<<" ";
    }
    cout<<endl;
    return 0;
}