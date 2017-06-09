#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define fori(a, b) for( int i=a ; i<b ; i++ )
#define MAX 100000
#define INF 999999

int ans, n;
vi factors;

int logCal(ll a, ll b){
	int power=0;
	while(a>b){
		b*=2;
		power++;		
	}
	return power;
}

void setAns(ll a, ll b, ll h, ll w, int i){
	// cout<<h<<" "<<w<<"\n";
	if( h>=a && w>=b ){
		ans = min(ans, i);
		return;
	}
	// if( h > MAX || w > MAX )	return;
	if( i==n )	return;
	if( factors[i] == 2 ){
		int x, y;
		x = logCal(a, h);
		y = logCal(b, w);
		if( x+y <= n-i ){
			ans = min(ans, i+x+y);
		}
		return;
	}
	if( h<a )	setAns(a, b, h*factors[i], w, i+1);
	if( w<b )	setAns(a, b, h, w*factors[i], i+1);
}

int main(){

	ll a, b, h, w;
	int x, m, ans1;
	vi pp;

	cin>>a>>b>>h>>w>>m;

	fori(0, m){
		cin>>x;
		pp.pb(x);
	}

	sort(pp.begin(), pp.end() );
	n = min(m, 35);

	fori(0, n){
		factors.pb(pp[m-1-i]);
	}

	// fori(0, n){
	// 	cout<<factors[i]<<"\n";
	// }

	if( ( h>=a && w>=b ) || ( w>=a && h>=b ) ){
		cout<<"0\n";
		return 0;
	}

	ans = INF;
	setAns( a, b, h, w, 0 );
	setAns( a, b, w, h, 0 );

	if( ans == INF ){
		cout<<"-1\n";
	}
	else{
		cout<<ans<<"\n";
	}

	return 0;
}