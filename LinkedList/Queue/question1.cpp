// Reverse elements of queue
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

//time complexity - O(n)
void reverseQueue(queue<int> &q) {
    stack<int> temp;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        temp.push(curr);
    }
    while(!temp.empty()) {
        int curr = temp.top();
        temp.pop();
        q.push(curr);
    }
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    reverseQueue(q);
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}
