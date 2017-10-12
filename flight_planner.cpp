#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>
#include<queue>

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
	int n, x, dp[1005][11], wind[1005][11]	, minm, p;
	vi output;
	cin>>n;
	forn(z, 0, n){
		cin>>x;
		x/=100;
		forin(9, 0){
			forn(j, 0, x){
				cin>>wind[j][i];
			}
		}
		forn(i, 0, x+1)	forn(j, 0, 10)	dp[i][j]=INF;
		dp[0][0]=0;
		dp[1][1]=60-wind[0][0];
		forn(i, 1, x){
			forn(j, 0, 10){
				dp[i][j]=min(dp[i][j], dp[i-1][j]+30-wind[i-1][j]);
				if(j<9)	dp[i][j]=min(dp[i][j], dp[i-1][j+1]+20-wind[i-1][j+1]);
				if(j>0)	dp[i][j]=min(dp[i][j], dp[i-1][j-1]+60-wind[i-1][j-1]);
			}
		}
		// forin(9, 0){
		// 	forn(j, 0, x)	cout<<dp[j][i]<<" ";
		// 	cout<<"\n";
		// }
		// cout<<dp[x-1][1]<<" "<<wind[x-1][1]<<"\n";
		output.pb(min(dp[x-1][1]+20-wind[x-1][1], dp[x-1][0]+30-wind[x-1][0]));
	}
	fori(0, n){
		cout<<output[i]<<"\n";
		cout<<"\n";
	}
	return 0;
}