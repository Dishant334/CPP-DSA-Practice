#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
class Node{
    public:
    int data;
    Node *left;    //for left child
    Node *right;   //for right child
 
    Node(int data){
        this->data=data;
         left=right=NULL;
    }
};

     static int idx = -1;
    Node *buildTrees(vector<int> &nodes){
      idx++;
      if(nodes[idx]==-1){
        return NULL;
      }
    Node*currNode=new Node(nodes[idx]);
    currNode->left=buildTrees(nodes);
    currNode->right=buildTrees(nodes); 

    return currNode;
    }

void TopView(Node *root){
queue<pair<Node *,int>>q;
map<int,int>m;

q.push(make_pair(root,0));

while(!q.empty()){
    pair<Node*,int>curr=q.front();
    q.pop();

    Node* currNode=curr.first;
    int currHd=curr.second;

    if(!m.count(currHd)){
      m[currHd]=currNode->data;    
    }

    if(currNode->left!=NULL){
        q.push(make_pair(currNode->left,currHd-1));
    }
    if(currNode->right!=NULL){
        q.push(make_pair(currNode->right,currHd+1));
    }
}
for(auto itr:m){
    cout<<itr.second<<" ";
}
}
    

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node *root=buildTrees(nodes);
 cout << "Root (head) of the tree: " << root->data << endl;
 TopView(root);     
}