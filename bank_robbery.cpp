#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef set<int> si;

#define pb push_back
#define mp make_pair
#define fori(a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second

int main(){

	ll a, b, c, y;
	int n, startt, endd;
	vll x;

	cin>>a>>b>>c;

	cin>>n;

	fori(0, n){
		cin>>y;
		x.pb(y);
	}

	// sort(x.begin(), x.end() );

	endd = 0;

	fori(0, n){
		if( x[i] > b && x[i] < c ){
			endd += 1;
		}
	}

	cout<<endd<<"\n";

	return 0;
}