#include<iostream>
using namespace std;
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void Selection(int arr[],int n){
     for(int i=0;i<n;i++){
        int minIdx=i;
        for(int j=i+1;j<n;j++){
            if(arr[minIdx]>arr[j]){
                minIdx=j;
            }
        }
        swap(arr[i],arr[minIdx]);
     }
}
int main(){
    int arr[]={2,5,4,1,2};
    int n=sizeof(arr)/sizeof(int);
    Selection(arr,n);
    print(arr,n);
}