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
#define num 200*1000+5

int main(){
	int r, g, last;
	ll sum, prevSum, dp[num];

	scanf("%d %d", &r, &g);

	int hmax = (int)sqrt((double)(2*(r+g))) + 2;

	// cout<<"\t"<<hmax<<"\n";

	memset(dp, 0, sizeof(dp));

	if(r>0)	dp[1] = 1;
	if(g>0)	dp[0] = 1;
	prevSum = dp[0]+dp[1];

	forn(h, 2, hmax+5){
	// cout<<"-\n";
		sum = 0;
		last = min(r, (h*(h+1))/2);
		// cout<<h<<"\n";
		forin(last, 0){
			if((h*(h+1))/2 - i > g)	dp[i] = 0;
			if(r >= i && i>=h){ dp[i] = (dp[i]+dp[i-h])%INF; }
			sum = (sum+dp[i])%INF;
		}
		if(sum == 0){
			sum = prevSum;
			break;
		}
		else	prevSum = sum;
		// fori(0, last+1)	cout<<dp[i]<<" ";
		// cout<<"\n";
	}

	cout<<sum<<"\n";

	return 0;
}