#include<iostream>
#include<cmath>

using namespace std;

typedef long long int ll;

#define MOD 1000000007

ll min( ll a, ll b){
	if( a<b ){
		return a;
	}
	return b;
}

ll max( ll a, ll b){
	if( a>b ){
		return a;
	}
	return b;
}

int main(){
	int n, i, m;
	ll x, y, x1min, x1max, y1min, y1max, x2min, x2max, y2min, y2max;

	cin>>n;

	cin>>x>>y;
	x1max = x;
	x1min = x;
	y1max = y;
	y1min = y;
	for( i=1 ; i<n ; i++ ){
		cin>>x>>y;
		x1max = max( x, x1max);
		x1min = min( x, x1min);
		y1min = min( y, y1min);
		y1max = max( y, y1max);
	}

	cin>>m;

	cin>>x>>y;
	x2max = x;
	x2min = x;
	y2max = y;
	y2min = y;	
	for( i=1 ; i<m ; i++ ){
		cin>>x>>y;
		x2max = max( x, x2max);
		x2min = min( x, x2min);
		y2min = min( y, y2min);
		y2max = max( y, y2max);		
	}
	// cout<<x1min<<" "<<x1max<<" "<<y2max<<" "<<y2min<<"\n";
	ll asn = max( x1max - y2min , x2max - y1min  );
	asn = max(0,asn);
	cout<<asn<<"\n";
	return 0;
}