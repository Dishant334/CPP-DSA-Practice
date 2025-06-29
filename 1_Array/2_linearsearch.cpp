#include <iostream>
using namespace std;

void linear(int arr[],int key,int n){
    int i=0;
    while( i<n){
        if(arr[i]==key){
            cout<<"key is found and at position "<<i;
            return;
        }
        if(i==n){
            cout<<"key is not present";
        }
        else {
        i++;
    }
    }
    cout<<"key not present";
}

int main(){
    int arr[]={1,33,2,5,6};
    int key;
    cout<<"enter the key you want to access"<<endl;
    cin>>key;
    int n=sizeof(arr)/sizeof(int);
    linear(arr,key,n);
}