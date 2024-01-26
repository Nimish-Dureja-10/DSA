// Check two strings are anagram of each other
// anagram means two strings have same set of characters but can be in diff orders

#include <iostream>
#include <unordered_map>
using namespace std;

bool checkAnagram(string s1,string s2){
    unordered_map<char,int> mp;
    for(auto c:s1){
        mp[c]++;  // Storing character and frequency of s1
    }

    for(auto c:s2){
        mp[c]--;
    }

    for(auto pair:mp) {
        if(pair.second !=0){
            return false;
        }
    }
    return true;
}

int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    bool ans = checkAnagram(s1,s2);
    if(ans) {
        cout<<"Anagram"<<endl;
    }else{
        cout<<"Not Anagram"<<endl;
    }
    return 0;
}