/*
Check a string has all the alphabets from a - z.
*/

#include <iostream>
#include <set>
using namespace std;

bool checkAlphabets(string s) {
    if(s.length()!=26) {
        return false;
    }

    transform(s.begin(),s.end(),s.begin(),::tolower);

    set<char> alphabets;
    for(auto ch:s) {
        alphabets.insert(ch);
    }

    return (alphabets.size()==26);
}

int main() {
    string s;
    cin>>s;
    if(checkAlphabets(s)) {
        cout<<"All alphabets are present"<<endl;
    }else{
        cout<<"All alphabets are not present"<<endl;
    }
    return 0;
}

/*
Best approach for this question is that we should store the string in set so that we
get all the unique values and we can check if the length is 26. If length is 26 then
we have all the elemets present. And first we need to convert the string in lower
or upper case.
*/