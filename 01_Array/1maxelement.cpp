#include<iostream>
using namespace std;

int  maxel(int arr[],int n){
    int maxn=arr[0];
    for(int i=0;i<n;i++){
    maxn=max(maxn,arr[i]);
   }

return maxn;
}
int main(){
    int arr[]={12,5,74,6,8};
    int n=sizeof(arr)/sizeof(int);
    cout<<maxel(arr,n);
}