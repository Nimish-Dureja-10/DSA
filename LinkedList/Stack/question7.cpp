/*
Check whether the paranthesis are balanced of not.
*/

#include <iostream>
#include <stack>
using namespace std;

bool checkParanthesis(string str) {
    stack<char> st;
    for(int i=0;i<str.length();i++) {
        char ch = str[i];
        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }else {
            if(ch == ')' && !st.empty() && st.top() == '(') {
                st.pop();
            }else if(ch == '}' && !st.empty() && st.top() == '{') {
                st.pop();
            }else if(ch == ']' && !st.empty() && st.top() == '[') {
                st.pop();
            }else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string str = "[{(())}]";
    cout<<checkParanthesis(str)<<endl;
    return 0;
}