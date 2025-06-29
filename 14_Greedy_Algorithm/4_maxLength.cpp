#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2){
return p1.second<p2.second;
}
void maxLength(vector<int>first,vector<int>second,int n){
    vector<pair<int,int>>length(n,make_pair(0,0));

for(int i=0;i<n;i++){
length[i]=make_pair(first[i],second[i]);
}
sort(length.begin(),length.end(),compare);

int currSec=length[0].second;
int ans=1;
for(int i=1;i<first.size();i++){
if(currSec<=length[i].first){                      //non overlapping
    ans++;
    currSec=length[i].second;
}
}
cout<<ans;
}
int main(){
    vector<int>first={5,39,5,27,50};
    vector<int>second={24,60,28,40,90};
    int n=first.size();
    maxLength(first,second,n);
}