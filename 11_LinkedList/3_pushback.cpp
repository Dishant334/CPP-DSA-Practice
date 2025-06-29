#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;
    public:
    node(int val){
        data=val;
        next=NULL;
    }
};

class list{
    node* head;
    node* tail;
    public:
    list(){
        head=NULL;
        tail=NULL;
    }
    void push_back(int val){
        node *newNode=new node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }

    }
    
};
int main(){
    list ll;
    ll.push_back(3);

}