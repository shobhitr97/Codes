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
#define num 9000
#define offset 9002

int main(){
	int dp[105][2*num+5], n, k, a[105], b[105];
	cin>>n>>k;
	fori(0, n)	cin>>a[i];
	fori(0, n)	cin>>b[i];
	fori(0, n)	b[i]*=k;
	forn(i, 0, n)	forn(j, 0, 2*offset)	dp[i][j]=0;
	dp[0][b[0]-a[0]+offset]=a[0];
	forn(i, 1, n){
		forn(j, 2, offset+9001){
			if(j+b[i]-a[i]<offset-num||j+b[i]-a[i]>offset+num)	continue;
			if(dp[i-1][j]){
				dp[i][j]=max(dp[i][j], dp[i-1][j]);
				dp[i][j+b[i]-a[i] ]=max(dp[i][j+b[i]-a[i] ], dp[i-1][j]+a[i]);
				// cout<<i-1<<" "<<j-offset<<"->"<<i<<" "<<j+b[i]-a[i]-offset<<"\n";
			}
		}
		dp[i][b[i]-a[i]+offset]=max(dp[i][b[i]-a[i]+offset], a[i]);
	}	
	if(dp[n-1][offset]==0)	cout<<"-1\n";
	else	cout<<dp[n-1][offset]<<"\n";
	return 0;
}