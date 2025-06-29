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
    public:
    node* head;
    node* tail;
    
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
        cout<<endl;
    }
    bool removeCycle(node *head){
        node* slow=head;
        node* fast=head;

        while(fast !=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                cout<<"cycle is present"<<endl;
                return true;
                 break;
            }
        }
    
        if(!removeCycle){
            cout<<"cycle doesnt exist\n";
            return;
        }
        slow=head;
        if(slow==fast){
                  while(fast->next!=slow){
                    fast=fast->next;
                  }
                  fast->next=NULL;
        }
        else{
            node*prev=fast;
            while(slow!=fast){
                slow=slow->next;
                prev=fast;
                fast=fast->next;
            }
            prev->next=NULL;
        }
    }

};
int main(){
    list ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.tail->next=ll.head;
    ll.removeCycle(ll.head);
}