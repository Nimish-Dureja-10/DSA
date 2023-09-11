/*
Insert value at a given index in stack
*/

#include <iostream>
#include <stack>
using namespace std;

//bottom position index is 0.
void insertAtIndex(stack<int> &st,int val,int pos) {
    stack<int> temp;
    int size = st.size();
    int counter = size - pos; 
    while(counter) {
        int curr = st.top();
        st.pop();
        temp.push(curr);
        counter--;
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
    insertAtIndex(st,10,4);
    while(!st.empty()) {
        int curr = st.top();
        st.pop();
        cout<<curr<<" ";
    }
    cout<<endl;
    return 0;
}