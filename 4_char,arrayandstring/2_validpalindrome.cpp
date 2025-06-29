#include<iostream>
using namespace std;

bool palindrome(char str[],char str2[],char str3[],int n){
    int i=0;
    int si=0,ei=n-1;
       while(si<ei){
          str2[si++]=str[ei--];
          str3[i++]+=str2[si];
       } 
       if(str3[i++]==str[si++]){
        cout<<"this is a palindrome number"<<endl;
        return true;
       }
       else{
        return false;

       }   
 }
int main(){
    char str[]="lakd";
    char str2[]="",str3[]="";
    int n=sizeof(str)/sizeof(char);
    cout<<palindrome(str,str2,str3,n);
}    
