#include<iostream>
using namespace std;


void check(int arr[],int i){
    int n=sizeof(arr)/sizeof(int);
    if(arr[i]<=arr[i+1])  {
        cout<<"the arrat is sorted";
        return;
    }
    if(i=n-1);
  check(arr,i+1);
}
int main(){
    int arr[]={1,2,3,4,6};
    check(arr,0);
}