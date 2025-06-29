#include<iostream>
using namespace std;
void firstoccurence(int arr[],int target,int i,int n){
    if(arr[i]==target){
        cout<<"target is found at idx "<<i;
        return;
    }
    if(i==n-1){
        return;
    }
    firstoccurence(arr,target,i+1,n);
}

int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    int i=0;
    int target=5;
    firstoccurence(arr,target,i,n);
}