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
#define num 200005

bool vis[2][num];
ll dp[2][num];
int n, a[num];
ii par[2][num];

ll dfs(int loc, int dir, int parLoc, int parDir){
	if(loc<=0||loc>n)	return 0;
	if(loc==1){
		vis[dir][loc]=true;
		par[dir][loc]=mp(parLoc, parDir);
		dp[dir][loc]=-1;
		return -1;
	}
	vis[dir][loc]=true;
	par[dir][loc]=mp(parLoc, parDir);
	int temp=(dir==0)?loc+a[loc]:loc-a[loc];
	if(temp<=0||temp>n)	dp[dir][loc]=a[loc];
	else{
		if(vis[1-dir][temp]==false){
			if(dfs(temp, 1-dir, parLoc, parDir)==-1)	dp[dir][loc]=-1;
			else	dp[dir][loc]=(ll)a[loc]+dp[1-dir][temp];
		}
		else{
			if(par[dir][loc]==par[1-dir][temp]||dp[1-dir][temp]==-1)	dp[dir][loc]=-1;
			else	dp[dir][loc]=a[loc]+dp[1-dir][temp];
		}
	}
	// cout<<loc<<" "<<((dir==0)?2:3)<<" "<<dp[dir][loc]<<	"\n";
	return dp[dir][loc];
}

int main(){
	ll t, y;
	int x;
	cin>>n;
	vector<ll>output;
	fori(2, n+1)	cin>>a[i];
	fori(0, n+1)	vis[0][i]=vis[1][i]=false, par[0][i]=mp(i, 0), par[1][i]=mp(i, 1);
	// 0 - addition 
	// 1 - subtraction
	fori(2, n+1){
		if(vis[0][i]==false)	t=dfs(i, 0, i, 0);
		if(vis[1][i]==false)	t=dfs(i, 1, i, 1);
	}
	// vis[1]

	// cout<<"\n";
	// fori(1, n+1)	cout<<dp[0][i]<<" ";
	// cout<<"\n";
	// fori(1, n+1)	cout<<dp[1][i]<<" ";
	// cout<<"\n";
	fori(1, n){
		x=i+1;
		// if(x<=0||x>n){
		// 	output.pb(y);
		// 	continue;
		// }
		// y+=a[x];
		// x-=a[x];
		// // cout<<x<<" "<<y<<"\n";
		// if(x<=0||x>n){
		// 	output.pb(y);
		// 	continue;
		// }
		if(dp[1][i+1]==-1){
			output.pb(-1);
			continue;
		}
		output.pb(i+dp[1][x]);
	}
	fori(0, n-1)	cout<<output[i]<<"\n";
	return 0;
}