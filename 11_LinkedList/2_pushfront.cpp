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
    void push_front(int val){
        node *newNode=new node(val);
        if(tail==head){
            tail=head=newNode=NULL;
        }
        else{
            newNode->next=head;
            head=newNode;
        } 
    }
};
int main(){
    list ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
}