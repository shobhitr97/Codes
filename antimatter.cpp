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
#define num 2*100*100+5
#define zero 100*100+2

int main(){
	int n, a[1005], y;
	ll dp[2][num], sum;

	scanf("%d", &n);

	fori(0, n){
		scanf("%d", &a[i]);
	}

	y = 0;
	memset(dp[y], 0, sizeof(dp[y]));

	if(n > 0){
		dp[y][zero + a[0]] = 1;
		dp[y][zero - a[0]] = 1;
	}

	sum = dp[y][zero];
	fori(1, n){
		// forn(j, zero - 10000, zero + 10001)	dp[1-y][j] = 0;
		memset(dp[1-y], 0, sizeof(dp[1-y]));
		forn(j, zero - 10000, zero + 10001){
			if((dp[y][j] > 0)){
				if(j-a[i] >= zero-10000)	dp[1-y][j-a[i]] = (dp[1-y][j-a[i]] + dp[y][j])%INF;
				if(j+a[i] <= zero+10000)	dp[1-y][j+a[i]] = (dp[1-y][j+a[i]] + dp[y][j])%INF;
			}
		}	
		dp[1-y][zero + a[i]] += 1;
		dp[1-y][zero - a[i]] += 1;

		y = 1-y;
		// cout<<(i+1)<<" "<<dp[y][zero]<<"\n";
		sum = (sum+dp[y][zero])%INF;
	}

	cout<<sum<<"\n";

	return 0;
}