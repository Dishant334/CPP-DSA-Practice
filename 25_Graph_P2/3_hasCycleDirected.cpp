#include<iostream>
#include<list>
#include<vector>
using namespace std;
class Graph{
    int V;
    list<int> *l;
    bool isUndir;
    public:
    Graph(int V,bool isUndir=true){ //graph of size V
        this->V=V;
        l = new list<int>[V]; //new list of size V
        this->isUndir=isUndir;
    }
   void addEdge(int u,int v){
      l[u].push_back(v);  //u position pe v add hogya in a list
      if(isUndir){
        l[v].push_back(u);
      }
   }
   void print(){
   for(int i=0;i<V;i++){
    list<int>neighbours=l[i];  //its the content of neightbour in vertex
    cout<<i<<" : ";
    for(int v:neighbours){
     cout<<v<<" ";
    }
    cout<<endl;
   }    
   }
   bool dirCycleHelper(int src,vector<bool>vis,vector<bool>recPath){
     vis[src]=true;
     recPath[src]=true;
     list<int>neighbours=l[src];

     for(int v:neighbours){
        if(!vis[v]){
            if(dirCycleHelper(v,vis,recPath)){
            return true;
            }
        }
     }
     recPath[src]=false;
     return false;
   }

  bool isCycleDir(){
  vector<bool>vis(V,false);
  vector<bool>recPath(V,false);
  for(int i=0;i<V;i++){
    if(!vis[i]){
        if(dirCycleHelper(i,vis,recPath)){
            return true;
        }
    }
  }
  return false;
  }
};

int main(){
 Graph graph(5,false);

 graph.addEdge(1,0);
 graph.addEdge(0,2);
 graph.addEdge(2,3);
 graph.addEdge(3,0); 

 graph.print();

 cout<<graph.isCycleDir()<<endl;

    return 0;
}