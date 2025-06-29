#include<iostream>
using namespace std;
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void bubbleSort(int arr[],int n){

      for(int i=0;i<n;i++){
        for( int j=0;j<n-i-1;j++){
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
      }
}
int main(){
    int arr[]={1,3,4,1,3,4};
    int n=sizeof(arr)/sizeof(int);
    bubbleSort(arr,n);
    printarr(arr,n);
}