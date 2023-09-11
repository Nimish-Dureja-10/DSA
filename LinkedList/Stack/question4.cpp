/*
Remove element from bottom of stack
*/

#include <iostream>
#include <stack>
using namespace std;

//time complexity - O(n)
void removeFromBottom(stack<int> &st) {
    stack<int> temp;
    while(!st.empty()) {
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    temp.pop();
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
    removeFromBottom(st);
    removeFromBottom(st);
    while(!st.empty()) {
        int curr = st.top();
        st.pop();
        cout<<curr<<" ";
    }
    cout<<endl;
    return 0;
}