#include<iostream>
#include<vector>
#include<climits>
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
static int idx=-1;
static int maxSize=0;


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
 class Info{
    public:
    bool isBST;
    int min;
    int max;
    int size;

    Info(bool isBst,int min,int max,int size){
        this->isBST=isBST;
        this->min=min;
        this->max=max;
        this->size=size;
    }
 };   

Info *largestBST(Node * root){
    if(root==NULL){       //leaf node
        return new Info(true,INT_MAX,INT_MIN,0);
    }

    Info* leftInfo=largestBST(root->left);
    Info* rightInfo=largestBST(root->right);

    int currMin=min(root->data,min(leftInfo->min,rightInfo->min));
    int currMax=max(root->data,max(leftInfo->max,rightInfo->max));
    int currSize=leftInfo->size +rightInfo->size +1;

    if(leftInfo->isBST && rightInfo->isBST && 
        root->data >leftInfo->max
    && root->data <rightInfo->min){              //checking all four
        maxSize=max(maxSize,currSize);
        return new Info(true,currMin,currMax,currSize);
    }

return new Info(false,currMin,currMax,currSize);
    }


int main(){
    vector<int>nodes={50,30,5,-1,-1,20,60,45,-1,-1,70,65,-1,-1,80,-1,-1};
    Node *root=buildTrees(nodes);
 cout << "Root (head) of the tree: " << root->data << endl;
      largestBST(root);
      cout<<"max size of the tree is "<<maxSize<<endl;
}