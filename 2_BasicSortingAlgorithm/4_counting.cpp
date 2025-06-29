#include<iostream>
using namespace std;
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void counting(int arr[],int n){
    int minvalue=INT16_MAX,maxvalue=INT16_MIN;
    int freq[10000];
    for(int i=0;i<n;i++){
        minvalue=min(minvalue,arr[i]);
        maxvalue=max(maxvalue,arr[i]);
    }
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    int j=0;
    for(int i=minvalue;i<=maxvalue;i++){
        while(freq[i]>0){
           arr[j++]=i;
           freq[i]--;
        }
    }
}
int main(){
    int arr[]={1,2,8,10,2};
    int n=sizeof(arr)/sizeof(int);
    counting(arr,n);
    print(arr,n);
}