#include<iostream>
using namespace std;
void kadaneSum(int arr[],int n){
int curSum=0;int maxSum=INT16_MIN;
    for(int i=0;i<n;i++){
      curSum+=arr[i];
    if(curSum<0){
         curSum=0;
      }
      maxSum=max(maxSum,curSum);
    }
    cout<<maxSum;
}
int main(){
    int arr[]={1,2,-3,2,5};
    int n=sizeof(arr)/sizeof(int);
    kadaneSum(arr,n);
}