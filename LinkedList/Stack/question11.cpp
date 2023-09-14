/*
find the Stock span of the given array
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//time complexity - O(n)
//space complexity - O(n)
vector<int> pge(vector<int> &arr) {
    int n = arr.size();
    reverse(arr.begin(),arr.end());
    vector<int> output(n,-1);
    stack<int> st;
    st.push(0);
    for(int i=0;i<n;i++) {
        while(!st.empty() && arr[i] > arr[st.top()]) {
            output[st.top()] = n-i-1;
            st.pop();
        }
        st.push(i);
    }
    reverse(output.begin(),output.end());
    reverse(arr.begin(),arr.end());
    return output;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    } 
    vector<int> res = pge(arr);
    for(int i=0;i<n;i++) {
        cout<<(i-res[i])<<" ";
    }
    cout<<endl;
    return 0;
}