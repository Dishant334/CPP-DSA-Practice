#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node() {
        endOfWord = false;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string key) {
        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) { // if char not present
                temp->children[key[i]] = new Node();
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
    void longestStringHelper(Node * root,string &ans,string temp){
    for(pair<char,Node*>child : root->children){
if(child.second->endOfWord){        
        temp+=child.first;

        if((temp.size()==ans.size() && temp<ans)  || (temp>ans)){
            ans=temp;
        }
        longestStringHelper(child.second,ans,temp);
        temp=temp.substr(0,temp.size()-1);
    }
    }}
    string logestStringWithEOW(){
        string ans="";
        longestStringHelper(root,ans,"");
        return ans;
    }
};
string longestString(vector<string>dict){
    Trie trie;

    for(int i=0;i<dict.size();i++){
        trie.insert(dict[i]);
    }

    return trie.logestStringWithEOW();
}


int main() {
    vector<string> dict = { "a","banana", "ap", "appl", "apply","apple"};
    cout<<longestString(dict)<<endl;
    }