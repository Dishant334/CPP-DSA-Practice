#include<iostream>
#include<list>

using namespace std;

class Queue{
    public:
    list<int>q;

void push(int value){
    q.push_back(value);
}
void pop(){
    q.pop_front();
}
int front(){
    return q.back();
}
}; 