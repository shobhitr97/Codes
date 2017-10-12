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
	int dp[102][102], x, y, m, n;
	cin>>n>>m;
	fori(0, n)	forn(j, 0, n)	dp[i][j]=INF;
	fori(0, m){
		cin>>x>>y;
		dp[x][y]=-INF;
	}
	dp[0][0]=0;
	fori(0, n){
		forn(j, 0, n){
			if(dp[i][j]!=-INF){
				dp[i][j+1]=min(dp[i][j]+1, dp[i][j+1]);
				dp[i+1][j]=min(dp[i+1][j], dp[i][j]+1);
			}
		}
	}
	forn(i, 0, n){
		forn(j, 0, n)	cout<<dp[i][j]<<" ";
		cout<<"\n";
	}
	// cout<<dp[n-1][n-1];
	return 0;
}