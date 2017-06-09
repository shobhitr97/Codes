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
	int n, k, m, limit;
	ll dp[52][52], sum;
	vector<ll>output;
	while(cin>>n){
		cin>>k>>m;
		if(k==1){
			if(n<=m)	output.pb(1);
			else	output.pb(0);
			continue;
		}
		forn(i, 0, k+1)	forn(j, 0, n+1)	dp[i][j]=0;
		fori(1, n+1)	dp[1][i]=1;
		forn(i, 2, k+1){
			forn(j, i, n+1){
				sum=0;
				limit=max(i-1, j-m);
				forn(z, max(i-1, j-m), min(m*(i-1), j-1)+1)	sum+=dp[i-1][z];
				dp[i][j]=sum;
			}
		}
		output.pb(dp[k][n]);
	}
	for(vector<ll>::iterator it=output.begin();it!=output.end();it++)	cout<<(*it)<<"\n";
	return 0;
}