//Given n integers (can be duplicate), print the secone smallest integer.
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> ms;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
        ms.insert(i);
    }
    auto itr = ms.begin();
    itr++;
    cout<<"Ans: "<<*itr<<endl;
    return 0;
}