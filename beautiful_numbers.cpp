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

int n;
ll dp[1050][105][12];

ll backTrack(int mask, int m, int r){
	if(dp[mask][m][r]!=-1)	return dp[mask][m][r];
	if(m==1)	return 0;
	int cnt=0;
	fori(0, 10)	if(mask&(1<<i))	cnt++;
	if(cnt==0)	return 0;
	ll ans=0, temp1, temp2;
	for(int i=r-1;i<=(r+1);i+=2){
		if(i<0||i>=n)	continue;
		if(!(mask&(1<<i)))	continue;
		temp1=backTrack(mask, m-1, i);
		temp2=backTrack(mask&(~(1<<r)), m-1, i);
		ans=(ans+temp1)%INF;
		ans=(ans+temp2)%INF;
	}
	if(cnt>m)	ans=0;
	dp[mask][m][r]=ans;
	int p=mask&(1<<r);
	return ans;
}

int main(){
	int m, t;
	cin>>t;
	while(t--){
		ll ans=0;
		forn(i, 0, 1025){
			forn(j, 0, 101){
				forn(k, 0, 10)	dp[i][j][k]=-1;
			}
		}
		cin>>n>>m;
		dp[1][1][0]=0;
		fori(1, n)	dp[1<<i][1][i]=1;
		fori(0, n){
			ans=backTrack((1<<n)-1, m, i);
		}	
		ans=0;
		forn(i, 1, m+1){
			forn(j, 0, n){
				if(dp[(1<<n)-1][i][j]!=-1)	ans=(ans+dp[(1<<n)-1][i][j])%INF;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}