#include<iostream>
#include<stdio.h>

using namespace std;

typedef long long int ll;

ll temp[3][3];

void multiply(ll *x,ll *y,ll m){
	int i,j,k;
	ll p;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			p=0;
			for(k=0;k<3;k++){
				p= ( p + ( ( *( x + i*3 + k ) ) * ( *( y + k*3 + j ) )%m ) )%m;
			}
			temp[i][j]=p;
		}
	}

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			*( x + i*3 + j ) = temp[i][j] ;
		}
	}
}

void printt(ll *x){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			cout<<( *( x+ i*3 + j ) )<<" ";
		}
		cout<<"\n";
	}
}

int main(){
	ll m,n,a,b,c,t,x[3][3],y[3][3];
	int i,j;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>n>>m;
		if(n==2||n==1){
			cout<<"1\n";
			continue;
		}

		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				x[i][j]=0;
				y[i][j]=0;
			}
		}

		x[0][0]=x[1][1]=x[2][2]=1;
		y[0][0]=a,y[0][1]=b,y[0][2]=c,y[1][0]=1,y[2][2]=1;
		printt(*x);
		printt(*y);
		n = n-2;
		while(n){
			if(n%2==1){
				multiply(*x,*y,m);
			}
			multiply(*y,*y,m);
			n = n/2;
			printt(*x);
			printt(*y);
		}
	
		cout<<( (x[0][0]+x[0][1]+x[0][2])%m )<<"\n";

	}
	return 0;
}