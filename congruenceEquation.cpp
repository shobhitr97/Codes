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

// Intersection of 2 AP's
int findIntersection(ll a, ll b, ll c, ll d, ll x){
	if(a < c){
		a = ((c-a)/b)*b + a;
		if(a < c)	a += b;
	}
	ll s = a + (a-c)*b;
	if(s > x)	return 0;
	return ((x-s)/(b*d) + 1);
}

int main(){

	vll primes;
	ll a, b, x, temp, ans, p;
	int k, ps;

	cin>>a>>b>>p>>x;
	ps = p;

	if( a == 1 ){
		if(x >= b)	cout<<((x-b)/p + 1)<<"\n";
		else	cout<<0<<"\n";
		return 0;
	}

	primes.resize(ps+1);
	temp = a;
	fori(1, ps){
		if(temp == b)	k = i;
		cout<<temp<<"\n";
		primes[i] = temp;
		temp = (temp*a)%p;
	}

	// cout<<k<<"\n";

	ans = 0;
	primes[0] = 0;
	fori(1, ps){
		cout<<"----------\n";
		if(i < k)	temp = findIntersection(i, p-1, primes[k-i], p, x);
		else	temp = findIntersection(i, p-1, primes[ps-1-i+k], p, x);
		ans += temp;
	}

	cout<<ans<<"\n";

	return 0;
}