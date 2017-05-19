#include<iostream>

using namespace std;

typedef long long int ll;

#define num 100007
#define fori(a, b) for( int i=a ; i<b ; i++ )

int main(){

	int n, j;
	ll k, count, w[num], ans;

	cin>>n>>k;

	fori(0, n){
		cin>>w[i];
	}

	count = 0;

	fori(0, n){
		count += ( w[i]/k + 1*( (w[i]%k) > 0 ) );
	}

	ans = count/2 + 1*( count%2 > 0 );

	cout<<ans<<"\n";

	return 0;
}