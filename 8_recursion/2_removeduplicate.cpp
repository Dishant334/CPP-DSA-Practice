//remove duplicated in string
#include<iostream>
#include<string>
using namespace std;
int occur[26]={0};
void dupstring(string str,string str2,int idx,int n){

if(n==idx){
cout<<str2<<" ";
return; 
} 
if(occur[str[idx]]==0){
    str2+=str[idx];
    occur[str[idx]]++;
}
dupstring(str,str2,idx+1,n);
}
int main(){
    string str="appnacollege";
    int n=str.length();
    dupstring(str," ",0,n);
}