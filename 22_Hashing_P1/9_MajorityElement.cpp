#include<iostream>
#include<unordered_map>
using namespace std;

void MajorityElement(int arr[],int n){
    unordered_map<int,int>m;    //key as the particular element and value as its freq
  for(int i=0;i<n;i++){
    if(m.count(arr[i])==0){
        m[arr[i]]=1;
    }else {
        m[arr[i]]+=1;
    }
  }
    for(pair<int,int> p: m){
        if(p.second>n/3){
            cout<<p.first<<" ";
        }
    }
  

}

int main(){
    int arr[]={1,2,2,5,1,1,5,1,2,2};
    int n=sizeof(arr)/sizeof(int);
    MajorityElement(arr,n);
}