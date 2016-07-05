#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define F(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define mod 1000000007
using namespace std;

long long int M[2][2]={{1,1},{1,0}};

void print_a(long long int a[2][2]){
    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"--------------\n";
}

void multiply(long long int a[2][2],long long int b[2][2]){
	long long int x[4];
	int k=0;
	F(i,0,2){
		F(j,0,2){
			x[k]=((a[i][0]*b[j][0])%mod+(a[i][1]*b[j][1]%mod))%mod;
			k++;
		}
	}
	a[0][0]=x[0];
	a[0][1]=x[1];
	a[1][0]=x[2];
	a[1][1]=x[3];
}

void power(long long int a[2][2],long long int n){
	if(n==1){
		return ;
	}
	power(a,n/2);
	multiply(a,a);
	if(n%2){
		multiply(a,M);
	}
}

int main(){
	int t,F[2];
	long long int r,s,A[2][2],B[2][2],l;
	F[1]=1;
	F[0]=0;
	cin>>t;
	while(t--){
		cin>>r>>s;
		F(i,0,2){
			F(j,0,2){
				A[i][j]=1;
				B[i][j]=1;
			}
		}
		A[1][1]=0;
		B[1][1]=0;
		if(r>=2){
			power(A,s-r+1);
			power(B,r);
			A[0][0]=(A[0][0]-1)%mod;
			A[1][1]=(A[1][1]-1)%mod;
			multiply(B,A);
			cout<<B[0][0]<<"\n";
		}
		else{
			if(s>=2){
				power(A,s+1);
				cout<<(A[0][0]-1)%mod<<"\n";
			}
			else{
				cout<<F[s]-F[r]<<"\n";
			}
		}
	}

	return 0;
}