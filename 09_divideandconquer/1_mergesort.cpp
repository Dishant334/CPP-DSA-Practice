#include<iostream>
#include<vector>
using namespace std;
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void merge(int arr[],int si,int ei,int mid){
 vector<int>temp;
    int i=si;
 int j=mid+1;
while(i<=mid && j<=ei){
 if(arr[i]>arr[j]){
    temp.push_back(arr[j]);
    j++;
 }else{
    temp.push_back(arr[i]);
    i++;
 }}
 while(i<=mid){
    temp.push_back(arr[i]);
    i++;
 }
 while(j<=ei){
    temp.push_back(arr[j]);
    j++;
 }
 int x=0;
for(int idx=si;idx<=ei;idx++){
    arr[idx]=temp[x++];
}
}

void  mergeSort(int arr[],int si,int ei){
   int mid=(si+ei)/2;
   if(si>=ei){
      return;
   }

   mergeSort(arr,si,mid);
  mergeSort(arr,mid+1,ei);

  merge(arr,si,ei,mid);
   
}

int main(){
    int arr[]={1,3,4,2,6};
    int n=sizeof(arr)/sizeof(int);
    mergeSort(arr,0,n-1);
    print(arr,n);
}