//we just have to push it everytime and check it next time and pop accordingly
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void greatestright(vector<int>element,vector<int>&ans,int n){
    stack<int>s;
    ans[n-1]=-1;
    s.push(element[n-1]);
    for(int i=n-2;i>=0;i--){
      int currelement=element[i];
      while(!s.empty() && currelement>=s.top()){
        s.pop();
      }
     
     ans[i]=s.empty()?-1:s.top();
     s.push(element[i]);
    }

for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
}
}
int main(){
    vector<int>element={6,8,0,1,3};
    vector<int>ans={0,0,0,0,0};
    int n=element.size();
    greatestright(element,ans,n);
}