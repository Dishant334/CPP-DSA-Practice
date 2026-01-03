#include<iostream>
#include<list>
#include<vector>
using namespace std;
class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int V){ //graph of size V
        this->V=V;
        l = new list<int>[V]; //new list of size V
    }
   void addEdge(int src,int v){
      l[src].push_back(v);  //src position pe v add hogya in a list
      l[v].push_back(src);   //v position pe src add hogya in a list 
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
   bool hasPath(int src,int dest,vector<bool>&vis){
   if(src==dest){
    return true;
   }
    vis[src]=true;
    list<int>neighbours=l[src];

    for(int v:neighbours ){
        if(!vis[v]){   // this is the base case for it
            return hasPath(v,dest,vis);
        }
    }
     return false;
   }
};

int main(){
 Graph graph(5);

 graph.addEdge(0,1);
 graph.addEdge(1,2);
 graph.addEdge(1,3);
 graph.addEdge(2,3);
 graph.addEdge(2,4); 

vector<bool>vis(7,false);
 cout<<graph.hasPath(0,4,vis);


    return 0;
}