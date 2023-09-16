/*
-> Set can store only unique elements. No duplicate values are stored in set.
-> Set is a STL container used to store unique values
-> It stores value in ordered state. (values will be either in increasing or
decreasing order)
-> No indexing in set, elements are identified by their own value.
-> Once value is added to set it cannot be modified.
-> Set are of dynamic size. No need to specify its size. No overflow in set.
-> Faster as insertion, deletion and search as time complexity is O(logn)
it uses binary search for search operation.
Disadvantage - It uses more memory than array. It is not suitable for large datasets.
it is because for insertion/deletion the time complexity is O(logN) and if the we are 
doing insertion/deletion frequently it will be very time costly.
*/

#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s1;
    // it will store values of set in decreasing order
    // set<int,greater<int> > s1;

    //time complexity - O(logN) for insert function
    s1.insert(3);
    s1.insert(2);
    s1.insert(4);
    s1.insert(1);
    //Here values will stored in increasing order. Here insert function will create
    // an iterator for each value.
    cout<<s1.size()<<endl;
    s1.insert(1);
    cout<<s1.size()<<endl; // size will be 4 only as it will not store duplicate value.

    //traversal in set with the help of begin and end iterators.
    //begin is the position of first element of the set.
    //end is the position+1 of last element of the set.

    // for creating a iterator of any stl container we need to specify 
    //the container with its datatype and name for it.
    set<int>::iterator itr;
    for(itr = s1.begin(); itr!=s1.end(); itr++) {
        //itr holds the position so to get value we need * to access its value
        cout<<*itr<<" ";
    }
    cout<<endl;

    //deletion in set
    s1.erase(4); //deleting value 4
    for(int value:s1) {
        cout<<value<<" ";
    }
    cout<<endl;

    s1.insert(4);

    //deleting at position
    auto itr1 = s1.begin();
    advance(itr1,3);
    s1.erase(itr1);
    for(int value:s1) {
        cout<<value<<" ";
    }
    cout<<endl;

    s1.insert(4);
    s1.insert(5);

    for(int value:s1) {
        cout<<value<<" ";
    }
    cout<<endl;

    //deleting a range of elements from set
    auto start_itr = s1.begin();
    start_itr++;
    auto end_itr = s1.begin();
    advance(end_itr,3);
    s1.erase(start_itr,end_itr);
    for(int value:s1) {
        cout<<value<<" ";
    }
    cout<<endl;
    return 0;
}