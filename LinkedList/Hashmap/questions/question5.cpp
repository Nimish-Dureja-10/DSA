// Two sum problem. Return the pair whose sum is equal to target else return -1.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> targetSumPair(vector<int> v,int t) {
    unordered_map<int,int> m;
    vector<int> ans(2,-1);
    for(int i = 0;i<v.size();i++) {
        if(m.find(t - v[i])!=m.end()){
            ans[0] = m[t-v[i]];
            ans[1] = i;
            return ans;
        }else{
            m[v[i]] = i;
        }
    }
    return ans;
}

int main() {
    vector<int> v;
    for(int i=0;i<7;i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int target = 13;
    vector<int> ans = targetSumPair(v,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}