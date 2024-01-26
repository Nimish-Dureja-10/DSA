// Check two strings are isomorphic
#include <iostream>
#include <unordered_map>
using namespace std;

bool checkOneToMany(string s1,string s2) {
    unordered_map<char,char> m;
    for(int i=0;i<s1.length();i++){
        if(m.find(s1[i])!=m.end()) {
            if(m[s1[i]] != s2[i]) {
                return false;
            }
        }else{
            m[s1[i]] = s2[i];
        }
    }
    m.clear();
    return true;
}

bool checkIsomorphic(string s1,string s2) {
    if(s1.length() != s2.length()) {
        return false;
    }

    // Checking one-to-many mapping for s1 -> s2
    bool s1s2 = checkOneToMany(s1,s2);

    // checking one-to-many mapping for s2 -> s1
    bool s2s1 = checkOneToMany(s2,s1);
    return s1s2 && s2s1;

}

int main() {

    string s1,s2;
    cin>>s1>>s2;
    cout<<(checkIsomorphic(s1,s2) ? "Isomorphic" : "Not Isomorphic")<<endl;
    return 0;
}