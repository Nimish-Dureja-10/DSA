// Multi set can store duplicate values. Values will remain ordered. 
// Unique values. Value can be identified by itself.

#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> ms;
    //time complexity for insertion in multiset is O(logN)
    ms.insert(1);
    ms.insert(3);
    ms.insert(2);
    ms.insert(3);
    ms.insert(1);
    ms.erase(2);
    multiset<int>::iterator itr;
    for(itr=ms.begin();itr!=ms.end();itr++) {
        cout<<*itr<<" ";
    }
    cout<<endl;
    multiset<int>::iterator itr1;
    itr1 = ms.find(2);
    cout<<*itr1<<endl;
    //time complexity - O(k+logN)
    cout<<ms.count(3)<<endl;
    //lower_bound - it will give an iterator pointing to first occurrance 
    // of value if present, else it will return next greater value.
    //upper_bound - it use to return iterator pointing to the position next
    //greater value
    multiset<int>::iterator itr2;
    itr2 = ms.lower_bound(2);
    cout<<*itr2<<endl;
    return 0;
}