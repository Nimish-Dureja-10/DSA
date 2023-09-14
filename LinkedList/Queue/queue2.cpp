/*
Queue implementation using arrays.
Implementing queue in linked list is more efficient because it does not waste 
any space while dequeue.
*/

#include <iostream>
using namespace std;

class Queue {
    int front;
    int back;
    vector<int> v;
    public:
    Queue() {
        this -> front = -1;
        this -> back = -1;
    }

    void enqueue(int d) {
        this -> v.push_back(d);
        this -> back++;
        if(this -> back == 0) this -> front = 0;
    }

    void dequeue() {
        if(this -> front == this -> back) {
            this -> front = -1;
            this -> back = -1;
            this -> v.clear();
        }
        else this -> front++;
    }

    int getFront() {
        if(this -> front == -1) {
            return -1;
        }
        return this -> v[this -> front];
    }

    bool isEmpty() {
        return this -> front == -1;
    }
};

int main() {
    Queue qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.dequeue();
    qu.enqueue(40);
    qu.enqueue(50);
    while(!qu.isEmpty()) {
        cout<<qu.getFront()<<" ";
        qu.dequeue();
    }
    cout<<endl;
    return 0;
}