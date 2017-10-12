#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>

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
#define fornn(i, a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define INF 1000000007

int main(){
	vector<pair<ll, ll> >input;
	ll l, r;
	int n;
	cin>>n;
	fori(0, n){
		cin>>l>>r;
		input.pb(mp(l, r));
	}
	sort(input.begin(), input.end());
	bool flag=true;
	ll max1=0;
	fori(2, n){
		l=input[i].fi;
		max1=max(max1, input[i-2].se);
		if(l<=max1&&l<=input[i-1].se)	flag=false;
	}
	if(flag==false)	cout<<"NO\n";
	else	cout<<"YES\n";
	return 0;
}