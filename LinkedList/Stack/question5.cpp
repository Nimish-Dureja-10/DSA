/*
Remove element from stack from given index.
*/

#include <iostream>
#include <stack>
using namespace std;

//time complexity - O(n)
void deleteAtPosition(stack<int> &st,int pos) {
    int size = st.size();
    int counter = size - pos;
    stack<int> temp;
    while(counter) {
        int curr = st.top();
        st.pop();
        temp.push(curr);
        counter--;
    }
    st.pop();
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
    deleteAtPosition(st,2);
    while(!st.empty()) {
        int curr = st.top();
        st.pop();
        cout<<curr<<" ";
    }
    cout<<endl;
    return 0;
}