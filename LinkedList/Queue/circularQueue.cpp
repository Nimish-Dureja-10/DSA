/*
Circular Queue 
to make a circular queue we can add element at (i+1)%n element.
*/

#include <iostream>
using namespace std;

class Queue {
    int front;
    int back;
    vector<int> v;
    int curr_size;
    int total_size;
    public:
    Queue(int n) {
        v.resize(n);
        this -> total_size = n;
        this -> front = 0;
        this -> back = n-1;
        this -> curr_size = 0;
    }

    void enqueue(int d) {
        if(isFull()) return ;
        this -> back = (this -> back + 1) % this -> total_size;
        this -> v[this->back] = d;
        this -> curr_size++;
    }

    void dequeue() {
        if(isEmpty()) return;
        this -> front = (this -> front + 1) % this -> total_size;
        this ->curr_size--;
    }

    int getFront() {
        if(this -> front == -1) {
            return -1;
        }
        return this -> v[this -> front];
    }

    bool isEmpty() {
        return this -> curr_size == 0;
    }

    bool isFull() {
        return this->curr_size == this->total_size;
    }
};

int main() {
    Queue qu(4);
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