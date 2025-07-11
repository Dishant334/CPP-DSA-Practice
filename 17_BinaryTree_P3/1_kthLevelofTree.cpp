#include<iostream>
#include<vector>
#include<queue>
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

void KthLevel(Node *root,int k){
        queue<pair<Node *,int>>q;
q.push(make_pair(root,1));

while(!q.empty()){
    pair<Node *,int>curr=q.front();
    q.pop();

    Node *currNode=curr.first;
    int level=curr.second;

    if(curr.second==k){
        cout<<curr.first->data<<" ";
    }

if(currNode->left !=NULL){
    q.push(make_pair(currNode->left,level+1));
}
if(currNode->right !=NULL){
    q.push(make_pair(currNode->right,level+1));
}
}


    }

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node *root=buildTrees(nodes);
 cout << "Root (head) of the tree: " << root->data << endl;
      KthLevel(root,3);
}
