#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ActivitySelection(int start[],int end[],int n){ 
int currEnd=end[0];
int count=1;
for(int i=1;i<=n;i++){
   if(start[i]>=currEnd){
    count ++;
    currEnd=end[i];
   }
} 
return count;
}

int main(){
    int start[]={1,3,0,5,8,5};
    int end[]={9,7,9,6,2,4};
    int n=sizeof(start)/sizeof(int);
cout<<ActivitySelection(start,end,n);
}