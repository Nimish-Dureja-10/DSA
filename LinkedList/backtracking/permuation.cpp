// Permutation of all strings in lexicographical order using backstracking.
#include <iostream>
using namespace std;

// Time complexity - O(n!)
void permutation(string &str,int i) {
    // base case
    if(i == str.size()) {
        cout<<str<<endl;
    }
    for(int j=i;j<str.size();j++) {
        swap(str[i],str[j]);
        permutation(str,i+1);
        // backtracking
        swap(str[i],str[j]);
    }
} 

int main() {
    string s = "abc";
    permutation(s,0);
    return 0;
}