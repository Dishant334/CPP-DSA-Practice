#include <iostream>
using namespace std;

void binSearch(int arr[],int key,int n){
    int si=0,ei=n-1;
    
    while(si<=ei){
        int mid=(si+ei)/2;
    if(arr[mid]==key){
        cout<<"key is found at "<<mid<<endl;
        return;
    }
    if(arr[mid]<key){
        si=mid+1;
    }
    if(arr[mid]>key){
        ei=mid-1;
    }
    }
    cout<<"not found";
}
int main(){
 int arr[]={1,2,3,4,5,6};
 int key;
 cin >>key;
int n=sizeof(arr)/sizeof(int);
binSearch(arr,key,n);
}
