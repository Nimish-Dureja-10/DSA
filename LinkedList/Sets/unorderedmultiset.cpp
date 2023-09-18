//Unordered_multiset can store duplicate values and values are stored in unordered fashion

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_multiset<int> ms;
    //time complexity - O(N), average time complexity - O(1)
    ms.insert(3);
    ms.insert(4);
    ms.insert(2);
    ms.insert(3);
    ms.insert(1);
    ms.insert(1);
    // time complexity - O(n)
    ms.erase(1);
    unordered_multiset<int>::iterator itr;
    for(itr=ms.begin();itr!=ms.end();itr++) {
        cout<<*itr<<" ";
    }
    cout<<endl;
    unordered_multiset<int>::iterator itr1;
    // itr1 = ms.find(2);
    itr1 = ms.find(1);
    cout<<ms.count(3)<<endl;
    return 0;
}