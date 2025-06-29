#include<iostream>
using namespace std;
void trappingWater(int height[],int n,int leftmax[],int rightmax[]){
    int watertrapped,totaltrapped=0;
    int i;
leftmax[0]=height[0];
rightmax[n-1]=height[n-1];
for( i=1;i<n;i++){
    leftmax[i]=max(leftmax[i-1],height[i-1]);
}
for( i=n-2;i>0;i--){
    rightmax[i]=max(rightmax[i+1],height[i+1]);
}
for(int i=0;i<n;i++){
watertrapped= min(leftmax[i],rightmax[i])-height[i];
if(watertrapped>0){
totaltrapped+=watertrapped;
}}
cout<<totaltrapped<<endl;

}
int main(){
    int height[]={4,1,0,6,3,2,5};
    int n=sizeof(height)/sizeof(int);
    int leftmax[20000];
    int rightmax[20000];
 trappingWater(height,n,leftmax,rightmax);
}