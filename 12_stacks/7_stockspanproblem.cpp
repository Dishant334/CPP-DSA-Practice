//finding left highest and then the span bw them
#include<iostream>
using namespace std;
#include<vector>
#include<stack>
void stockspan(vector<int>stock,vector<int>span){
stack<int>s;
span[0]=1;
s.push(0);
for(int i=1;i<stock.size();i++){
    int currprice=stock[i];
   while(!s.empty()&&currprice>=stock[s.top()]){
   s.pop(); 
}
if(s.empty()){
    span[i]=i+1;
}else{
    int prevHigh=s.top();
    span[i]=i-prevHigh;
}
s.push(i);
}
for(int i=0;i<span.size();i++){
    cout<<span[i]<<" ";
}
}
int main(){
    vector<int>stock={100,80,60,70,60,85,100};
    vector<int>span={0,0,0,0,0,0,0};
stockspan(stock,span);
}