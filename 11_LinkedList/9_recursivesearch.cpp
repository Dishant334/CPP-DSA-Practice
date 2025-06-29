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
        if(head==NULL){
            tail=head=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        } 
    }
    void printll(){
        node *temp=head;
        while(temp != NULL){
           cout<<temp->data<<"->";
           temp=temp->next;     //updation
        }
        cout<<"Null";
    }
    int helper(int key,node *temp,int idx){
      if(temp==NULL){
        cout<<"key not found";
        return -1;
      }
        if(temp->data==key){
         cout<<"key is found"<<endl;
         return idx;
      }
     
     return helper(key,temp->next,idx+1);
    }
    int searchrec(int key){
        return helper(key,head,0);
    }
};
int main(){
    list ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printll();
    cout<<ll.searchrec(3);
    cout<<ll.searchrec(32);
}