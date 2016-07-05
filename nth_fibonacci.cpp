#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
	
using namespace std;

long long int b[2][2]={{1,1},{1,0}};

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

void multiply(long long int a[2][2],long long int b[2][2],long long int m){
	//cout<<"multiply:\n";    
	int i,j,k=0;
	//print_a(a);
	long long int x[4];
	for(i=0;i<=1;i++){
		for(j=0;j<2;j++){
			x[k++]=(a[i][0]*b[0][j]+a[i][1]*b[1][j])%m;
		}

	}
	//print_a(b);
	a[0][0]=x[0];
	a[0][1]=x[1];
	a[1][0]=x[2];
	a[1][1]=x[3];
	
	//cout<<"After:\n";
	//print_a(a);
}

void power(long long int a[2][2],long long int x,long long int m){
	if(x==1){
		return ;
	}
	if(x%2){
		power(a,x/2,m);
	//	cout<<"power  "<<x/2<<":\n";
		multiply(a,a,m);
		multiply(a,b,m);
	}
	else{
		power(a,x/2,m);
		multiply(a,a,m);
	}
	//print_a(a);
}

int main(){
	long long int a[2][2],n,m;
	int t=300;

	while(t--){
		cin>>n>>m;
		if(n<2){
			cout<<n<<"\n";
			continue;
		}
		a[0][0]=a[0][1]=a[1][0]=1;
		a[1][1]=0;
		//print_a(a);
		//M[n]=b^(n-1)
		power(a,n-1,m);
		cout<<a[0][0]<<"\n";
	}
	return 0;
}