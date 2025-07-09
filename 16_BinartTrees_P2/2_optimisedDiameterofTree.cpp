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
    int TreeHT(Node* root){
      if(root==NULL){
           return 0;
      }
      int leftHt=TreeHT(root->left);
      int rightHt=TreeHT(root->right);

      int currHt=max(leftHt,rightHt)+1;

      return currHt;
    }

    pair<int,int>Diameter(Node *root){
        if(root==NULL){
            return make_pair(0,0);
        }
       pair<int,int>leftInfo=Diameter(root->left);   //LD,LH
       pair<int,int>rightInfo=Diameter(root->right); //RD,RH
       int currDia=leftInfo.second+rightInfo.second+1;
       int finalDia=max(currDia,max(rightInfo.first,leftInfo.first));
       int finalHeight=max(leftInfo.second,rightInfo.second)+1;
      return make_pair(finalDia,finalHeight);
    }

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node *root=buildTrees(nodes);
 cout << "Root (head) of the tree: " << root->data << endl;
      cout<<"the height of the tree is :"<< TreeHT(root)<<endl;
cout<<"the diameter of the tree is : "<<Diameter(root).first;
}