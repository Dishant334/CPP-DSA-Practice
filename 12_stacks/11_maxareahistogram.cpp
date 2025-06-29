#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void maxAreaHistogram(vector<int>height,vector<int>nsl,vector<int>nsr){
stack<int>s1;
stack<int>s2;
vector<int>width(height.size());
vector<int>area(height.size());
//next smallest left
for(int i=0;i<height.size();i++){
    while(!s1.empty() && height[i]<=height[s1.top()]){
      s1.pop();
    }
nsl[i]=s1.empty() ?-1:s1.top();
s1.push(i);
}
//next smallest right
for(int i=height.size()-1;i>=0;i--){
    while(!s2.empty() && height[i]<=height[s2.top()]){
        s2.pop();
    }
    nsr[i]=s2.empty()?height.size():s2.top();
    s2.push(i);
}
for(int i=0;i<height.size();i++){
          width[i]=nsr[i]-nsl[i]-1;
          area[i]=height[i]*width[i];
}
int maxArea=INT16_MIN;
for(int i=0;i<height.size();i++){
maxArea=max(maxArea,area[i]);
}
cout<<maxArea;

}

int main(){
    vector<int>height={2,1,5,6,2,3};
    vector<int>nsl(height.size());
    vector<int>nsr(height.size());

    maxAreaHistogram(height,nsl,nsr);
}