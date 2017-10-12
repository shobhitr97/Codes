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
	int n, s, t=0;
	ll sum=0, dp[67][67];
	vector<ll>output;
	while(1){
		cin>>n>>s;
		if(n<0&&s<0)	break;
		t++;
		forn(i, 0, s+1)	forn(j, 0, n+1)	dp[i][j]=0;
		fori(1, n+1)	dp[i][i]=1;
		sum=1, dp[0][1]=1, dp[0][0]=1;
		fori(2, n+1){
			dp[0][i]=dp[0][i-1]+dp[0][i-2];
		}
		forn(i, 1, s+1){
			sum=1;
			forn(j, i+1, n+1){
				dp[i][j]=dp[i-1][j-1]+sum-dp[i][j-1];
				sum+=dp[i][j];
			}
		}
		output.pb(dp[s][n]);
	}
	fori(0, t)	cout<<output[i]<<"\n";
	return 0;
}