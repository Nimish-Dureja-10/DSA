/*
Q2 - Your are given an array of int numbers, there is a sliding window of size k
which is moving in from very left of the array to very right of the array. You 
can only see k numbers in the window. Each time the sliding window moves right by 
one position. Return the max sliding window which basically contains the max 
element in each window.
*/

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

//time complexity - O(n)
//space complexity - O(k)
vector<int> maxElemWindow(vector<int> &arr,int k) {
    deque<int> dq;
    vector<int> res;
    for(int i=0;i<k;i++) {
        while(!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(arr[dq.front()]);
    for(int i=k;i<arr.size();i++) {
        int curr = arr[i];
        if(dq.front() == (i-k)) dq.pop_front();
        while(!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        res.push_back(arr[dq.front()]);
    }
    return res;
}

int main() {
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> res = maxElemWindow(v,3);
    for(int i=0;i<res.size();i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}