/*
multimap is a stl container which store key value pairs.
map stores keys in ascending/descending orders. By default in asc order.
multimap can store duplicate keys.

Member functions time complexity O(log n)
insert(),erase(),swap(),size(),max_size(),clear(),empty(),upper_bound(),
lower_bound(),find(),count(),begin(),end(),rbegin(),rend().
*/

#include <iostream>
#include <map>
using namespace std;

int main(){
    multimap<string,int> mp;
    // time complexity is O(log n)
    mp.insert(make_pair("nimish",343243));
    mp.insert(make_pair("nimish",676543));
    mp.insert(make_pair("abhishek",283847));

    // This is not allowed in multimap
    // mp["vijay"] = 244434;

    for(auto pair:mp){
        cout<<"Name - "<<pair.first<<" Phone no- "<<pair.second<<endl; 
    }
    return 0;
}

/*
We have unordered_multimap which is same as multimap but it is not in ordered
way, but it can store duplicate keys.
Implemented using hashing time complexity for insert,delete and search is O(1).
*/