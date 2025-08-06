#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std;

class Node{
    public:
    Node * next;
    int val;
    string key;

    Node(string key,int val){
        next=NULL;
        this->key=key;
        this->val=val;
    }
    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};

class HashTable {
    int totSize;
    int currSize;  //for rehashing
    Node ** table;
    public:
    HashTable(int size=5){   //default=5
        totSize=size;
        currSize=0;

        table=new Node * [totSize];   //creates a table
    for(int i=0;i<totSize;i++){
        table[i]=NULL;    //initializing all with null
    }
    }

    int hashFunction(string key){
         int idx=0;

         for(int i=0;i<key.size();i++){
            idx=(idx+ (key[i]*key[i])%totSize)%totSize;   //we take mod on each step to prevent overflow
         }
         return idx;
     }
     void rehash(){    //O(n)
          Node** oldTable=table;
          int olSize=totSize;

          totSize=2*totSize;
          currSize=0;
          table=new Node *[totSize];
          
          for(int i=0;i<totSize;i++){
            table[i]=NULL;
          }

          for(int i=0;i<totSize;i++){
            Node * temp= oldTable[i];
            while(temp !=NULL){
                insert(temp->key,temp->val);
                temp=temp->next;
            }

            if(oldTable[i]!=NULL){
                delete oldTable[i];
            }
          }
          delete[] oldTable;
     }
void insert(string key,int val){
    int idx=hashFunction(key);   //returns idx in int for a key

    Node* newNode=new Node(key,val); 
    Node* head=table[idx];  //it is null

    newNode->next=table[idx];
    table[idx]=newNode;
    currSize++;

    double lambda=currSize/(double)totSize;
    if(lambda >1){
        rehash();  //O(n)
    }
}

bool exists(string key){
    int idx=hashFunction(key);

    Node*temp=table[idx];
    while(temp!=NULL){
        if(temp->key==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
int search(string key){
     int idx=hashFunction(key);

    Node*temp=table[idx];
    while(temp!=NULL){
        if(temp->key==key){
            return temp->val;
        }
        temp=temp->next;
    }
    return -1;
}
void remove(string key){
    int idx=hashFunction(key);

    Node*temp=table[idx];
    Node* prev=temp;
    while(temp!=NULL){
        if(temp->key==key){
          if(prev==temp){
            table[idx]=temp->next;
          }else{
            prev->next=temp->next;
          }
        }
        prev=temp;
        temp=temp->next;
    }
}
};


int main(){
    HashTable ht(6);

    ht.insert("India",150);
    ht.insert("China",150);
    ht.insert("US",50);
    ht.insert("Nepal",10);
    ht.insert("UK",20);

    if(ht.exists("India")){
        cout<<"india population :"<<ht.search("India")<<endl;
    }

    return 0;
}