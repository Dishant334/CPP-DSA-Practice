#include<iostream>
#include<vector>
using namespace std;

void IndianCoin(vector<int>coins,int n,int V){
    int ans=0;
    for(int i=n-1;i>=0 && V>=0;i++){
     if(V>=coins[i]){
      ans+=V/coins[i];
      V=V%coins[i];
    }}
cout<<"the answer is "<<ans;
}
int main(){
    vector<int>coins={1,2,5,10,20,50,100,200,500,1000,2000};
    int n=coins.size();
    IndianCoin(coins,n,121);
}