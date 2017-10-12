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
#define forn(i, a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define num 100005

int main(){

	int n, f;
	ll x, y;
	ll cost;
	vector<pair<ll, ll> >lk;
	vector<ll> p;
	cin>>n>>f;
	fori(0, n){
		cin>>x>>y;
		lk.pb(mp(y, x));
	}
	cost=0;
	fori(0, n){
		// cout<<min(lk[i].fi, lk[i].se)<<"\n";
		cost+=min(lk[i].se, lk[i].fi);
		lk[i].fi=lk[i].fi-min(lk[i].se, lk[i].fi);
	}
	int j=0;
	fori(0, n){
		p.pb(min(lk[i].fi, lk[i].se));
	}
	sort(p.begin(), p.end());
	reverse(p.begin(), p.end());
	fori(0, min(n, f)){
		cost+=p[i];
		// j++;
		// if(j==f)	break;
	}
	cout<<cost<<"\n";

	return 0;
}