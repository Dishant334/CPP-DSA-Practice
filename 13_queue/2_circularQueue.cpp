#include<iostream>
using namespace std;

class circular{
    int *arr;
    int capacity;
    int currsize;
    int f,r;

    public:
    circular(int capacity){
     this->capacity=capacity;
     arr=new int(capacity);
     currsize=0;
     f=r=-1;
    }
    void push(int value){
        if(currsize==capacity){
            cout<<"queue is full"<<endl;
            return;
        }
        r=(r+1)%capacity;
        arr[r]=value;
        currsize++;
    }
    
    void pop(){
        if(empty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        f=(f+1)%capacity;
        currsize--;
    }
    int front(){
        if(empty()){
          cout<<"Queue is empty"<<endl;
           return -1;
        }
        return arr[f];
    }
    bool empty(){
        return currsize==0;
    }
};