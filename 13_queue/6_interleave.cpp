#include<iostream>
#include<queue>

using namespace std;

void Interleave(queue<int> &org){
   queue<int>key;
for(int i=1;i<=10;i++){
    org.push(i);
}
  int n=org.size();

for(int i=1;i<=n/2;i++){
    key.push(org.front());
    org.pop();
}

while(!key.empty()){
   org.push(key.front());
   key.pop();

   org.push(org.front());
   org.pop();
}

for(int i=1;i<=n;i++){
    cout<<org.front()<<" ";
    org.pop();
}
}
int main(){
    queue<int>org;
    Interleave(org);
}