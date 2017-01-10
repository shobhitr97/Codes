#include <iostream>

using namespace std;

void multiply(int *a,int *b){
    int c[4];
    c[0]=a[0]*b[0]+a[1]*b[2];
    c[1]=a[0]*b[1]+a[1]*b[3];
    c[2]=a[2]*b[0]+a[3]*b[2];
    c[3]=a[2]*b[1]+a[3]*b[3];
    for(int i=0;i<4;i++){
        a[i]=c[i];
    }
}

int main()
{
   int m_arr[4],x[4];
   int n,i;
   cin>>n;
   
   m_arr[0]=m_arr[1]=m_arr[2]=1;
   m_arr[4]=0;
   for(i=0;i<4;i++){
       x[i]=1;
   }
   n=n-2;
   while(n){
       if(n%2==1){
           multiply(x,m_arr);
       }
       multiply(m_arr,m_arr);
       n=n/2;
   }
   cout<<x[0]<<"\n";
   return 0;
}
