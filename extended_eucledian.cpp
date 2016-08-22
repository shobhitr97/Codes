#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int x[2][2];

int main(){
  int a,b,r,r1,r2,t,p,q;
 	int temp;
 	cin>>t;
  while(t--)
    r=1;
    cin>>a>>b;

    if(a<b){
    	temp=a;
    	a=b;
    	b=temp;
    }   
    p=a;
    q=b;
    x[0][0]=1;
    x[0][1]=0;
    x[1][0]=0;
    x[1][1]=1;
    while(r!=0){
      r1=x[0][0]-(p/q)*x[1][0];
      r2=x[0][1]-(p/q)*x[1][1];
      r=r1*a+r2*b;
      x[0][0]=x[1][0];
      x[0][1]=x[1][1];
      x[1][0]=r1;
      x[1][1]=r2;
      p=q;
      q=r;
    }  
  cout<<x[0][0]<<"*"<<a<<"+"<<x[0][1]<<"*"<<b<<"="<<p<<"\n";
  return 0;
}
