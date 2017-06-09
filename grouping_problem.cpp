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

int main(){
	int n, t=0;
	ll m, dp[1005][1005], arr[1005], maxm;
	vi output;
	while(1){
		cin>>n>>m;
		if(!n&&!m)	break;
		t++;
		fori(1, n+1)	cin>>arr[i];
		forn(i, 0, n+1)	forn(j, 0, n+1)	dp[i][j]=0;
		dp[1][1]=arr[1];
		forn(i, 1, n+1)	dp[i][0]=1;
		forn(i, 2, n+1){
			forn(j, 1, i+1){
				dp[i][j]=(((arr[i]%m)*dp[i-1][j-1])%m+dp[i-1][j])%m;
			}
		}
		maxm=dp[n][0]%m;
		forn(j, 1, n+1)	maxm=max(maxm, dp[n][j]);
		output.pb(maxm);
	}
	fori(0, t)	cout<<output[i]<<"\n";
	return 0;
}