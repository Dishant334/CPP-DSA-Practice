#include <iostream>
#include <vector>
using namespace std;

void pairSum(vector <int> vec,int n,int target){
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(vec[i]+vec[j]==target){
          cout<<"it is a pair sum with indices ["<<i<<","<<j<<"]"<<endl;

        }
    }
}}
int main(){
    vector <int> vec={2,15,11,7};
    int n=vec.size();
    int target;
    cout<<"give the target"<<endl;
    cin>>target;
    pairSum(vec,n,target);
}