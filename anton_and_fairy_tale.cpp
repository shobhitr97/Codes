#include<iostream>
#include<cmath>

using namespace std;

typedef long long int ll;

int main(){
	ll n,m;
	cin>>n>>m;
	
	if( m >= n ){
		cout<<n<<"\n";
		return 0;
	}

	ll c;

	c = (ll)(sqrt(2)*sqrt(n-m));

	while( c*(c+1) < 2*(n-m) ){
		c++;
	}

	cout<<m+c<<"\n";

	return 0;
}
