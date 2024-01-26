// Given array of strings check whether we can make strings equal by tranferring 
// some chars to different strings.

#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool checkStrings(vector<string> v,int size){
    map<char,int> mp;
    for(int i=0;i<size;i++){
        for(int j=0;j<v[i].length();j++){
            char y = v[i].at(j);
            mp[y]++;
        }
    }
    for(auto pair:mp) {
        if(pair.second%size!=0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        v.push_back(x);
    }
    bool ans = checkStrings(v,n);
    if(ans){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}

// test case1 - collegeee coll collegge
// test case2 - wall ah wallahah