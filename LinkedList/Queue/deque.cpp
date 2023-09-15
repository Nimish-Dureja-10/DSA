/*
deque is double sided queue. Here we can do addition and 
removal from the front as well as from then back.
*/

#include <iostream>
#include <deque>
using namespace std;


int main() {
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(40);
    dq.push_front(0);
    dq.push_front(5);
    while(!dq.empty()) {
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    cout<<endl;
    return 0;
}