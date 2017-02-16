#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define num 1000000007

void multiply(ll *a,ll *b){
    ll c[4];
    c[0]=( (a[0]*b[0])%num + (a[1]*b[2])%num )%num;
    c[1]=( (a[0]*b[1])%num + (a[1]*b[3])%num )%num;
    c[2]=( (a[2]*b[0])%num + (a[3]*b[2])%num )%num;
    c[3]=( (a[2]*b[1])%num + (a[3]*b[3])%num )%num;
    for(int i=0;i<4;i++){
        a[i]=c[i];
    }
}

int main()
{
    ll marr[4],x[4],n;
    int i,t;
    cin>>t;
    while(t--){
      cin>>n;
      if(n==0){
        cout<<"0\n";
        continue;
      }
      marr[0]=marr[1]=marr[2]=1;
      marr[3]=0;
      for(i=0;i<4;i++){
          x[i]=1;
      }
      n=n-2;
      while(n){
          if(n%2==1){
              multiply(x,marr);
          }
          multiply(marr,marr);
          n=n/2;
      }
      cout<<x[0]<<"\n";
    }
    return 0;
}