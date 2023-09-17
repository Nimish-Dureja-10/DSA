/*
Cherry wants to invite her friends at her bday party. She want to create list 
of her friends with the help of her friend arshii, but arshii is writing repeated
names. Cherry dont want any redundancy so she need a list with no repeated names.
*/

#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin>>n;
    set<string> invitelist;
    while(n--) {
        string name;
        cin>>name;
        invitelist.insert(name);
    }
    for(string value:invitelist) {
        cout<<value<<endl;
    }
    return 0;
}