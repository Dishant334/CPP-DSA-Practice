#include<iostream>
#include<vector>
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
bool FindPath(Node *root,int n,vector<int> &path){    //if we pass path by reference then only the changes will be reflected
     if(root==NULL){
         return false;
     }
     path.push_back(root->data);
     if(root->data==n){
         return true;
     }
     int isLeft=FindPath(root->left,n,path);
     int isRight=FindPath(root->right,n,path);
     
     if(isLeft || isRight){
         return true;
     }
     if(!isLeft && !isRight){
     path.pop_back();
     return false;
}
}

    
int LCA(Node* root,int n1,int n2){
vector<int>path1;
vector<int>path2;

 FindPath(root,n1,path1);
 FindPath(root,n2,path2);

 int lca=-1;
 for(int i=0,j=0;i<path1.size() && j<path2.size();i++,j++){
    if(path1[i]!=path2[i]){     //jab uncommon hoyega usse phla wala hi ans hoga
        return lca;
    }
    lca=path2[i];
 }
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node *root=buildTrees(nodes);
 cout << "Root (head) of the tree: " << root->data << endl;
      int n1=4;
      int n2=5;
      cout<<LCA(root,n1,n2);
}