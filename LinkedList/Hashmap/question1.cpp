// sum of Repetetive elements
#include <iostream>
#include <map>
using namespace std;

// Time complexity - O(n)
// Space complexity - O(k) where k is number of unique elements.
int main() {
    int arr[7] = {1,1,2,1,3,3,3};
    map<int,int> m;
    for(int i=0;i<7;i++){
        m[arr[i]]++;
    }
    map<int,int>::iterator itr;
    int sum = 0;
    for(itr=m.begin();itr!=m.end();itr++){
        if(itr->second>1){
            int x = itr->first;
            sum +=x;
        }
    }
    cout<<sum<<endl;
    return 0;
}