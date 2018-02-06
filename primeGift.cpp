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
#define num 1e18

vll d0, d1;
int n, k;
ll p[16], ans;

void createSpace0(int index, ll product){
	int div = p[index];
	while(1){
		if( num/product < p[index] )	return;
		if(index + 2 < n)	createSpace0(index+2, product);
		product *= p[index];
		d0.pb(product);
	}
}

void createSpace1(int index, ll product){
	int div = p[index];
	while(1){
		if( num/product < p[index] )	return;
		if(index + 2 < n)	createSpace1(index+2, product);
		product *= p[index];
		d1.pb(product);
	}
}

ll cal(ll limit){
	
	int ptr0, ptr1;
	ll rank, product;

	ptr0 = 0;
	ptr1 = d1.size()-1;
	rank = 0;

	while(ptr0 < d0.size() && ptr1 >= 0){
		if( d1[ptr1] <= limit/d0[ptr0]){
			product = d0[ptr0]*d1[ptr1];
			rank += (ptr1+1);
			ans = max(ans, product);
			// cout<<d0[ptr0]<<" "<<ptr1+1<<" : "<<product<<"\n";
			ptr0++;
		}
		else{
			ptr1--;
		}
	}

	return rank;

}

int main(){

	scanf("%d", &n);
	
	fori(0, n)	scanf("%d", &p[i]);

	scanf("%d", &k);

	if(n == 1){
		ans = 1;
		fori(1, k)	ans = ans*p[0];
	}
	else{

		// Create two spaces for a set of size atmost 8
		// Odd indices and even indices

		d0.pb(1);
		d1.pb(1);

		createSpace0(0, 1);
		createSpace1(1, 1);

		sort(d0.begin(), d0.end());
		sort(d1.begin(), d1.end());

		int siz0 = d0.size();
		int siz1 = d1.size();

		// printf("%d %d %lld %lld\n", siz0, siz1, d0[siz0-1], d1[siz1-1]);

		// fori(0, d0.size())	printf("%lld ", d0[i]);
		// cout<<"\n";
		// fori(0, d1.size())	printf("%lld ", d1[i]);
		// cout<<"\n";

		ll l, r, mid;
		ll rank;

		l = 1;
		r = num;

		while( l<=r ){
			mid = (l+r)/2;
			ans = 1;
			rank = cal(mid);

			// printf("%lld : %lld %lld\n", mid, ans, rank);

			if(rank == k){ break; }
			if(rank < k){ l = mid+1; }
			if(rank > k){ r = mid-1; }
		}
	}
	
	cout<<ans<<"\n";

	return 0;
}