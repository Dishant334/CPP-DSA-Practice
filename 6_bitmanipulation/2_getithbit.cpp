#include<iostream>
using namespace std;
void ith(int num,int pos){
 if(num & 1<<pos==0){
  cout<<"the bit is 0";
 }   else{
    cout<<"the bit is 1";
 }

}
int main(){
int num=6;
int pos=2;
ith(num,pos);
}