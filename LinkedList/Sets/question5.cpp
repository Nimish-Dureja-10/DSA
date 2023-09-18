/*
Given the number of question n, and marks for the correct answer as p and q marks
for the incorrect answer. One can either attempt to solve the question in an 
examination and get either p marks if right or q if answer is wrong, or leave the 
question unattempted and get 0. the task is to find the count of all the different 
possible marks that one con score in examination
input n=2 , p=1 , q=-1
output = 5
the different possible outcome 
-2,-1,0,1,2
*/

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n,p,q;
    cin>>n>>p>>q;
    unordered_set<int> s;

    //time complexity - O(n^2)
    //space complexity - O(n)
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            int correct = i;
            int incorrect = j;
            int unattended = n -(i -j);

            if(unattended>=0) {
                int score = correct*p+incorrect*q;
                s.insert(score);
            }else{
                break;
            }
        }
    }
    unordered_set<int>::iterator itr;
    for(itr=s.begin();itr!=s.end();itr++) {
        cout<<*itr<<" ";
    }
    cout<<endl;
    cout<<"Ans: "<<s.size()<<endl;
    return 0;
}