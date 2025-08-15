#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    int freq;

    Node() {
        endOfWord = false;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
        root->freq=-1;
    }

    void insert(string key) {
        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) { // if char not present
                temp->children[key[i]] = new Node();
                 temp->children[key[i]]->freq=1;
            }else{
            temp->children[key[i]]->freq++;
        }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    bool search(string key) {
        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) {
                return false; // char not found
            }
            temp = temp->children[key[i]];
        }
        return temp->endOfWord; // true if end of word
    }

    string getPrefix(string key){
Node * temp=root;
string prefix="";

for(int i=0;i<key.size();i++){
    prefix+=key[i];
    if(temp->children[key[i]]->freq==1){
        return prefix;
    }
    temp=temp->children[key[i]];
}
return prefix;
}
};


void PrefixSum(vector<string>words){
    Trie trie;
    for(int i=0;i<words.size();i++){
    trie.insert(words[i]);
}

for(int i=0;i<words.size();i++){
    cout<<trie.getPrefix(words[i])<<endl;
}
}


int main() {
    vector<string> words = {"zebra", "dog", "duck", "dove"};

PrefixSum(words);
    }