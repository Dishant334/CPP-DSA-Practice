#include<iostream>
using namespace std;

void BSP(int n,string ans,int lastoccur){
if(n==0){
    cout<<ans<<"";
    return;
}
if(lastoccur==0){
    BSP(n-1,ans+'0',0);
    BSP(n-1,ans+'1',1);
}
else{
    BSP(n-1,ans+'0',0);
}
}
int main(){
    string ans=" ";
    BSP(2,ans,0);
}