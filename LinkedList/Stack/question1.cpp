/*
Copy values of stack to another stack in same order
like - 1 2 3 4 to 1 2 3 4
*/

#include <iostream>
#include <stack>
using namespace std;

//time complexity - O(n)
stack<int> copyStack(stack<int> &input) {
    stack<int> temp;
    while(!input.empty()) {
        int curr = input.top();
        input.pop();
        temp.push(curr);
    }
    stack<int> result;
    while(!temp.empty()) {
        int curr = temp.top();
        temp.pop();
        result.push(curr);
    }
    return result;
}

// time complexity - O(n)
void f(stack<int> &st,stack<int> &result) {
    if(st.empty()) return;
    int curr = st.top();
    st.pop();
    f(st,result);
    result.push(curr);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(4);
    st.push(8);
    // while(!st.empty()) {
    //     int curr = st.top();
    //     st.pop();
    //     cout<<curr<<" ";
    // }
    // cout<<endl;
    // stack<int> res = copyStack(st);
    stack<int> res;
    f(st,res);
    while(!res.empty()) {
        int curr = res.top();
        res.pop();
        cout<<curr<<" ";
    }
    cout<<endl;
    return 0;
}