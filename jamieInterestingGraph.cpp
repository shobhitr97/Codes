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
#define INF 1000000000
#define NUM 100005

bool sieve[NUM+5];
vi primes;
vector < vii > graph;

void fillPrimes(){
	int j, i;

	memset(sieve, true, sizeof(sieve));
	sieve[1] = false;

	i = 2;
	while( i <= NUM+3){
		if( sieve[i] == false ){
			i++;
			continue;
		}
		primes.pb(i);
		j = 2*i;
		while( j <= NUM+3 ){
			sieve[j] = false;
			j += i;
		}
		i++;
	}
}

int findPrime(int n){
	int l, r, mid;
	l = 0;
	r = primes.size() - 1;
	while( l <= r ){
		mid = (l+r)/2;
		if( primes[mid] >= n ){
			r = mid-1;
		}
		else	l = mid+1;
	}
	return primes[l];
}

int main(){

	int n, m, p, base, offset, count, w, rem, x, y;

	fillPrimes();

	cin>>n>>m;

	p = findPrime(n-1);

	base = p/(n-1);
	count = p - base*(n-1);
	offset = 1;

	graph.resize(n+1);
	fori(1, n){
		w = 0;
		if(count){
			w += offset;
			count--;
		}
		w += base;
		graph[i].pb(mp(i+1, w));
	}

	rem = m - (n-1);
	x = 1, y = 3;
	while(rem){
		graph[x].pb(mp(y, INF));
		rem--;
		y++;
		if(y > n){
			x++;
			y = x+2;
		}
	}

	cout<<p<<" "<<p<<"\n";
	fori(1, n+1){
		int siz = graph[i].size();
		forn(j, 0, siz){
			cout<<i<<" "<<graph[i][j].fi<<" "<<graph[i][j].se<<"\n";
		}
	}

	return 0;
}