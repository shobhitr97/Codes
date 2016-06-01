#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

class PowerDigit{
  public:
    int digitK(int x,int y,int k);
    
};

int main(){
  PowerDigit obj;
  int a,b,k,t;
  cin>>t;
  while(t--){
    cin>>a>>b>>k;
    cout<<obj.digitK(a,b,k+1)<<"\n";
  }
  return 0;
}

int PowerDigit::digitK(int x,int y,int k){
  int a=1,b=x,check=0,num;
  num=pow(10,k);
  while(y>0){
    if(y%2==1){
      a=(a*b)%num;
      if(a/num>=1){
          check=1;
      }
    }
    b=(b*b)%num;
    y/=2;
  }

  num/=10;
  if(a/num){
      return a/num;
  }
  if(check){
      return 0;
  }
  return -1;
}
  
