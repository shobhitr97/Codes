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
#define fi first
#define se second
#define INF 1000000007
#define num 10000007

int main(){
	ll dp[num], x, y;
	int n;
	cin>>n>>x>>y;
	dp[1]=x;
	fori(2, n+1){
		if(i&1)	dp[i]=min(dp[i-1]+x, dp[(i+1)/2]+y+x);
		else	dp[i]=min(dp[i-1]+x, dp[i/2]+y);
	}
	cout<<dp[n]<<"\n";
	return 0;
}