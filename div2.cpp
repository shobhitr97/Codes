#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

using namespace std;
int sieve[4109],list[1100];

int *prime(int N){
  int temp,i,j;
  int count;
  memset(sieve,-1,4109);
  i=2;
  list[0]=1;
  count = 1;
  while(i<1001){
    if(sieve[i]==0){
      i++;
      continue;
    }
    list[count]=i;
    count++;
    j = 2*i;
    while(j<=N){
      sieve[j]=0;
      j+=i;
    }
    i++;
  }
  list[count]=0;
  //for(i=0;i<count;i++){
  //  cout<<list[i]<<"\n";
  //}
  
}

int main(){
  prime(1000);
  int n,i,temp,power[2],factor[2],powr,k,sym,in;
  in=0;

  for(n=50;n<1000000;n++){
    i=1;
    power[0]=0;
    power[1]=0;
    k=0;
    temp=n;
    sym=1;

    //cout<<n<<":\n";

    while(list[i]&&list[i]*list[i]<=n&&k<2){
      powr=0;
      
      while(n%list[i]==0){
        powr++;
        n/=list[i];
      }
      if(powr){
        //cout<<list[i]<<"^"<<powr<<"\n";
        if(sieve[powr+1]!=-1){
          sym=0;
          break;
        }
        else{
          power[k]=powr;
          factor[k]=list[i];
          k++;
        }
      }
      i++;

    }
    if(k&&sym){
      if(k==1&&n!=1){
        power[k]=1;
        factor[k]=n;
        k++;
        n=1;
      }
      if(k==2&&n==1){
        if(power[1]!=power[0]){
          if(in%9==0)
          /*cout<<factor[0]<<"^"<<power[0]<<","<<factor[1]<<"^"<<power[1]<<":"*/cout<<temp<<"\n";
          in++;
        }
      }
    }
    n=temp;
  }


  return 0;
}