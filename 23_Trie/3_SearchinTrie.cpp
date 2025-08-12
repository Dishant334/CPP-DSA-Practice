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
};


int main() {
    vector<string> words = {"the", "a", "there", "their", "any"};
    Trie trie;
    }