#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>

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

	int t, n, k, ans, T;
	vi x, out;

	cin>>T;

	forn(t, 0, T){
		cin>>n>>k;
		x.resize(k);
		fori(0, k)	scanf("%d", &x[i]);
		ans = 0;
		fori(0, k){
			if(i == 0)	ans = max(ans, x[i]);
			else	ans = max(ans, (x[i]-x[i-1]+1)/2 + 1*((x[i]-x[i-1]+1)%2 == 1));
			if(i == k-1)	ans = max(ans, n+1-x[i]);
		}
		out.pb(ans);
		x.clear();
	}

	fori(0, T)	cout<<out[i]<<"\n";

	return 0;
}