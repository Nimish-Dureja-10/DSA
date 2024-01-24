/*
map is a stl container which store key value pairs.
map stores keys in ascending/descending orders. By default in asc order.
map cannot store duplicate keys.

Member function
insert(),erase(),swap(),size(),max_size(),clear(),empty(),upper_bound(),
lower_bound(),find(),count(),begin(),end(),rbegin(),rend().
*/

#include <iostream>
#include <map>
using namespace std;

int main(){
    // it will store keys in desc order. 
    // map<string,int,greater<string> > m;
    map<string,int> m;
    m["nimish"] = 323232;
    m["karan"] = 4343;
    //  time complexity is O(log n)
    m.insert(make_pair("ritu",3434));

    map<string,int>::iterator itr;
    for(itr=m.begin();itr!=m.end();itr++){
        cout<<"Key-> "<<itr->first<<",Value-> "<<itr->second<<" "<<endl;
    }    

    cout<<endl;

    // here element is an key value iterator
    for(auto element:m){
        cout<<element.first<<" "<<element.second<<endl;
    }
    return 0;
}