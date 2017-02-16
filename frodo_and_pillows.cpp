#include<iostream>
#include<stdio.h>

using namespace std;

typedef long long int ll;
#define num 1000000000

ll n,m,k,x1,x2;

ll ans(ll y){

	ll sum = y;
	if( y-1 <= x1 ){
		sum += ( (y-1)*y )/2;
		sum += ( x1 - (y-1) );
	}
	else{
		sum += ( x1 * ( 2*(y-x1) + (x1-1) ) )/2;
	}

	if( y-1 <= x2 ){
		sum += ( (y-1)*y )/2;
		sum += ( x2 - (y-1) );
	}
	else{
		sum += ( x2 * ( 2*(y-x2) + (x2-1) ) )/2;
	}
	return sum;

}

int main(){
	ll l,r,mid,sum;
	int flag;
	cin>>n>>m>>k;
	x1 = k-1;
	x2 = n-k;
	l=1;
	r=m;
	sum=0;
	flag=0;

	while( !flag ){

		mid = (l+r)/2;
		sum = ans(mid);
		//cout<<mid <<" "<<sum<<"\n";
		if( sum == m || mid == l || mid == r ){
			flag=1;
			continue;
		}

		if(sum > m ){
			r = mid-1;
		} 
		else{
			l = mid+1;
		}
	}
	if( m > ans(mid) ){
		cout<< mid+1 <<"\n";
	}
	else{
		cout<<mid<<"\n";	
	}

	

	return 0;
}