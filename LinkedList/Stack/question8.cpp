/*
Next greater element, find the immediate greater element and store it in 
array else return -1.
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nge(vector<int> &arr) {
    int n = arr.size();
    vector<int> output(n,-1);
    stack<int> st;
    st.push(0);
    for(int i=1;i<arr.size();i++) {
        while(!st.empty() && arr[i] > arr[st.top()]) {
            output[st.top()] = arr[i];
            st.pop();
        }
        //pushing that index whose greater value not found right now to stack.
        st.push(i);
    }
    // not mandatory while loop as we have already initialize the output vector with -1
    // this while loop updated the value at left out indices.
    while(!st.empty()) {
        output[st.top()] = -1;
        st.pop();
    }

    return output;
}

int main() {
    int n; // 10
    cin>>n;
    vector<int> v1;
    // v1 = {4,6,3,0,1,9,5,6,7,3,2};
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        v1.push_back(x);
    }
    vector<int> result =  nge(v1);
    for(int i =0;i<result.size();i++) {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}