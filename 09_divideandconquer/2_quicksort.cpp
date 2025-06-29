#include<iostream>
using namespace std;
void  print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int partition(int arr[],int si,int ei){
    int pivotIdx=ei-1;

    for(int i=si;i<ei-1;i++){
        while(arr[i]>arr[pivotIdx]){
            swap(arr[i],arr[pivotIdx]);
            pivotIdx--;
        }
    }
    return pivotIdx;
}
void  QuickS(int arr[],int si,int ei){
    if(si>=ei){
        return;
    }
    int pivotIdx=partition(arr,si,ei);
    QuickS(arr,si,pivotIdx-1);
    QuickS(arr,pivotIdx+1,ei);
}

int main(){
    int arr[]={2,3,4,1,6};
    int n=sizeof(arr)/sizeof(int);
    QuickS(arr,0,n-1);
    print(arr,n);
}