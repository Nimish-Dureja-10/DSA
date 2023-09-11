/*
Insert a value at the bottom of stack or at any index
*/

#include <iostream>
#include <stack>
using namespace std;

//Time complexity - O(n)
//space complexity - O(n)
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

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(4);
    st.push(8);
    insertAtBottom(st,15);
    while(!st.empty()) {
        int curr = st.top();
        st.pop();
        cout<<curr<<" ";
    }
    cout<<endl;
    return 0;
}