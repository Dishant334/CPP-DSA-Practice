#include<iostream>
#include<list>
using namespace std;
template <class T>
class Stack{
    public:
    list<T> ll;
    void push(T val){
        ll.push_front(val);
    }
    void pop(){
        ll.pop_front();
    }
    T top(){
      return ll.front();    //head         
    }
    bool isEmpty(){
        if(ll.size()==0){
            return true;
        }
        return false;
    }

};
int main(){
    Stack<int>s1;
    s1.push(3);
    s1.push(2);
    s1.push(1);
    
    while(! s1.isEmpty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
}