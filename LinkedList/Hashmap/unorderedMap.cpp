/*
unordered_map is a stl container that stores key value pairs.
elements are not stored in ordered manner.
keys will be unique.
It is implemented using hashing.
Insertion, deletion and retrieval or search is done in O(1) time complexity

Member functions
insert(),erase(),find(),begin(),end(),count()
*/
#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<int,string> mp;
    mp.insert(make_pair(1,"animesh"));
    mp[3] = "vijay";
    mp[2] = "payal";

    for(auto pair:mp) {
        cout<<"Roll no- "<<pair.first<<" Name- "<<pair.second<<endl;
    }
    return 0;
}