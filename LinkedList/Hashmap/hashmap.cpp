/*
Hashmap help us to perform insertion, deletion and searching in efficient time.
Time complexity for all these operation in O(1).
Finding a unique index for all elements to store them is known as hashing.
Unique index is called hash value.
Hash Funtions - 
a) division method - h(k) = k mod m , where m is the number of buckets(no of elements).
b) mid square method - h(k) = k^2 and extract middle digits
c) digit folding method - Here we fold our key into equal size parts.
eg - to store 12345 we will add 12+34+5 = 51(Hash Value). At 51 we will store 12345.
d) multiplication method - h(k) = floor(M(kA mod 1)). M is the size of hash table.
k is the element we are hashing and A is a value 0 < A < 1.
Collision - when two elements have same hashed value. 
There are two methods to tackle collision. a) Open Hashing b) Closed Hashing
*/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Hashing {

    vector<list<int> > hashtable;
    int buckets;

    public:
    Hashing(int size) {
        buckets = size;
        hashtable.resize(size);
    }

    int hashValue(int key) {
        return key%buckets; //division method for hash function
    }

    void addValue(int key) {
        int index = hashValue(key);
        hashtable[index].push_back(key);
    }

    list<int>::iterator searchKey(int key) {
        int index = hashValue(key);
        return find(hashtable[index].begin(),hashtable[index].end(),key);
    }

    void deleteValue(int key) {
        int index = hashValue(key);
        //this condition will check whether the value is present or not.
        if(searchKey(key)!=hashtable[index].end()){
            hashtable[index].erase(searchKey(key));
            cout<<key<<" is deleted"<<endl;
        }else {
            cout<<key<<" is not present in the hash table"<<endl;
        }
    }
};

int main() {
    Hashing h(10);
    h.addValue(5);
    h.addValue(3);
    h.addValue(6);
    h.addValue(4);
    h.addValue(15);
    h.deleteValue(3);
    return 0;
}