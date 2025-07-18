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
    node* splitAtMid(node*head){
        node *slow=head;
        node *fast=head;
        node* prev=NULL;

        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prev!=NULL){
        prev->next=NULL;    //split at middle
    }
return slow;   //righthead
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
node *merge(node *left,node *right){
    list ans;
    node *i=left;
    node *j=right;

    while(i!=NULL &&j!=NULL){
        if(i->data<=j->data){
            ans.push_back(i->data);
            i=i->next;
        }else{
            ans.push_back(j->data);
            j=j->next;
        }
    }
    while(i!=NULL){
      ans.push_back(i->data);
            i=i->next;
    }
    while(j!=NULL){
       ans.push_back(j->data);
            j=j->next;
    }

return ans.head;
}

    node * mergeSort(node*head){
    if(head==NULL || head->next==NULL){
        return head;}
        node*rightHead=splitAtMid(head);
        node * left=mergeSort(head);     //left hand
        node * right=mergeSort(rightHead);  //right hand
        return merge(left,right);
    }
};
int main(){
    list ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printll();
    ll.head=ll.mergeSort(ll.head);
    ll.printll();
}