// Max Sum equal to zero subArray
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countMaxLengthSubArray(vector<int> v) {
    int prefixSum = 0;
    int maxLen = 0;

    unordered_map<int,int> m;
    for(int i=0;i<v.size();i++){
        prefixSum += v[i];
        if(prefixSum==0){
            maxLen++;
        }
        if(m.find(prefixSum)!=m.end()) {
            maxLen = max(maxLen,i-m[prefixSum]);
        }else{
            m[prefixSum] = i ;
        }
    }
    return maxLen;
}

int main() {
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<countMaxLengthSubArray(v)<<endl;
    return 0;
}