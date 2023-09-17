/*
We are given two vectors v1 and v2. We need to find the common elements an give their
sum.
*/

#include <iostream>
#include <set>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    int v1[n],v2[m];
    set<int> s1;
    for(int i=0;i<n;i++) {
        cin>>v1[i];
        s1.insert(v1[i]);
    }
    for(int i=0;i<m;i++) {
        cin>>v2[i];
    }
    int sum = 0;
    for(int ele:s1) {
        if(s1.find(ele)!=s1.end()) {
            sum += ele;
        }
    }
    cout<<"Ans: "<<sum<<endl;
    return 0;
}