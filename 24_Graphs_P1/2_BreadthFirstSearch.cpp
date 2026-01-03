#include<iostream>
#include<list>
#include<queue>
using namespace std;
class Graph{
    int V;
    list<int> *l;  //it is a array of list rep int by list* ->int *l
    public:
    Graph(int V){ //graph of size V
        this->V=V;
        l = new list<int>[V]; //new list of size V
    }
   void addEdge(int u,int v){
      l[u].push_back(v);  //u position pe v add hogya in a list
      l[v].push_back(u);   //v position pe u add hogya in a list 
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

   void bfs(){
   queue<int>q;
   vector<bool>vis(V,false);
   q.push(0);
   vis[0]=true;

   while(!q.empty()){
    int current=q.front();
    q.pop();
    cout<<current<<" , ";
    list<int>neighbours=l[current];

    for(int v:neighbours){
        if(!vis[v]){
        vis[v]=true;
        q.push(v);
        }
    }
   }
   cout<<endl;
   }

};

int main(){
 Graph graph(7);
 //undirected
 graph.addEdge(0,1);
 graph.addEdge(0,2);
 graph.addEdge(1,3);
 graph.addEdge(2,4);
 graph.addEdge(3,4);
 graph.addEdge(3,5);
 graph.addEdge(4,5);
 graph.addEdge(5,6); 

 graph.print();
 graph.bfs();

    return 0;
} 