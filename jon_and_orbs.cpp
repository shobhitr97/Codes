#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

vector< int > fact;

double poww(double a, int b){
	double x = 1;
	double y = a;
	while(b){
		if( b%2 == 1){
			x = x*y;
		}
		y = y*y;
		b = b/2;
	}
	return x;
}

int main(){

	int k,q,i,y;

	cin>>k>>q>>y;
	
	fact.resize(k+2);

	fact[0] = 1;
	fact[1] = -k;

	int j;
	for( j=2 ; j<k ; i++ ){
		fact[j] = (-1)*(fact[j-1]*(k-j+1))/(j);
	}

	double p=0.0,t,r,s,x;
	t=k;
	for( i=0 ; i<k ; i++ ){
		r=i;
		x = (t-r)/t  ;
		cout<<x<<" "<<poww(x,y)<<" ";
		
		cout<<fact[i]<<"\n";
		p += poww( x,y)*((double)fact[i]);
	}
	cout<<p<<"\n";

	return 0;
}