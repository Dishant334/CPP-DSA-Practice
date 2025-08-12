#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Node{
    public:
    unordered_map<char,Node*>children;
    bool endOfWord;

    Node(){
        endOfWord=false;
    }
};

class Trie{
    Node * root;
    public:
    Trie(){
        root=new Node();
    }
};

int main(){
    vector<string>words={"the","a","there","their","any","thee"};
     Trie trie;
    
    return 0;
}