// Permuatation of array in lexicographical order using backtracking.
#include <iostream>
#include <vector>
using namespace std;

void permutation(vector<int> &arr,int i,vector<vector<int> > &ans) {
    // Base case
    if(i >= arr.size()) {
        ans.push_back(arr);
        return;
    }

    for(int j=i;j<arr.size();j++) {
        swap(arr[i],arr[j]);
        permutation(arr,i+1,ans);
        swap(arr[i],arr[j]);
    }
}

int main() {
    vector<int> arr;
    for(int i=0;i<3;i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<vector<int> > ans;
    permutation(arr,0,ans); 

    return 0;
}