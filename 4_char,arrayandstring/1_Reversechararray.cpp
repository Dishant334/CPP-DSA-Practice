#include<iostream>
using namespace std;
void printst(char str1[],int n){
    for(int i=0;i<n;i++){
        cout<<str1[i]<<" ";
    }
}
void reverse(char str1[],int n){
    int si=0;
    int ei=n-1;
    while(si<=ei){
         swap(str1[si++],str1[ei--]);
    }
}

int main(){
    char str1[]="code";
    int n=4;
    cout<<"the string before is"<<endl;
    printst(str1,n);
    reverse(str1,n);
    cout<<endl;
    cout<<"the string after is"<<endl;
    printst(str1,n);

}