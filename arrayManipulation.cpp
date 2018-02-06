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

	vii intervals;

	int n, m, a, b, k;
	ll sum, ans;

	cin>>n>>m;
	fori(0, m){
		cin>>a>>b>>k;
		intervals.pb(mp(a, (-1)*k));
		intervals.pb((mp(b, k)));
	}

	sort(intervals.begin(), intervals.end());

	sum = 0;
	ans = 0;
	fori(0, 2*m){
		sum -= intervals[i].se;
		ans = max(ans, sum);
	}

	cout<<ans<<"\n";

	return 0;
}