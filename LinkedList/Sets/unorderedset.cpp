//Unordered set - values are stored in unordered fashion. But all values will be unique.
// Values cannot be modified when inside a set.
// Here average time complexity for insertion, deletion and searching is O(1).

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> s1;
    s1.insert(2);
    s1.insert(1);
    s1.insert(3);
    s1.insert(6);
    s1.insert(3);
    // for(int val:s1) {
    //     cout<<val<<" ";
    // }
    // cout<<endl;
    unordered_set<int>::iterator itr;
    for(itr = s1.begin(); itr!=s1.end(); itr++) {
        //itr holds the position so to get value we need * to access its value
        cout<<*itr<<" ";
    }
    cout<<endl;

    return 0;
}