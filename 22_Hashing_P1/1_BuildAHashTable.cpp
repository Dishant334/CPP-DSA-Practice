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

    Node(int key,int val){
        next=NULL;
        this->key=key;
        this->val=val;
    }
};

class HashTable {
    int totSize;
    int currSize;
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
};

int main(){
    HashTable ht(6);

    return 0;
}