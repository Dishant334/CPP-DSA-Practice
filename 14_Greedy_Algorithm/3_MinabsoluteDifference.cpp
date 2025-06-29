#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void AbDiff(vector<int>first,vector<int>second){
    int diff=0;
    int ans=0;
    sort(first.begin(),first.end());
    sort(second.begin(),second.end());
    for(int i=0;i<first.size();i++){
        diff=first[i]-second[i];
        ans+=diff;
    }
    cout<<ans;
}


int main(){
    vector<int> first={4,1,8,7};
    vector<int>second={2,3,6,5};
    AbDiff(first,second);
}