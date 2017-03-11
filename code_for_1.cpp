#include<iostream>

using namespace std;

typedef long long int ll;

ll sum;

void find(ll n, ll m, ll l, ll r ){
	if(l>r){
		return;
	}
	ll mid;
	mid = ( 1+m )/2;

	if( l <= mid && r >= mid ){
		// cout<< mid <<" "<<n<<" "<l<<<" "<<r<<"\n";
		sum += (n%2);
		if( n > 1){
			if( l < mid ){
				find(n/2, mid-1, l, mid-1);
			}
			if( r > mid ){
				find(n/2, mid-1, 1, r-mid);
			}
		}
	}
	else{
		if( n > 1 ){
			if( l > mid && r > mid ){
				find(n/2, mid-1, l-mid, r-mid);
			}
			else{
				find(n/2, mid-1, l, r);
			}
		}
	}

}

int main(){

	ll l,r,n,p;
	int i;

	cin>>n>>l>>r;

	p=1;
	i=0;

	while( p <= n ){
		p=p*2;
		i++;
	}

	// cout<<p<<"\n";
	sum = 0;
	find(n,p-1,l,r);

	cout<<sum<<"\n";

	return 0;
}