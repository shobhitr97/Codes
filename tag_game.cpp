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

int dist[num], parent[num], branch[num], n, x;
vector<vi>adjList;

int dfs(int vrtx, int par, int l){
	parent[vrtx]=par;
	dist[vrtx]=l;
	int maxBranch=0;
	for(vi::iterator it=adjList[vrtx].begin();it!=adjList[vrtx].end();it++){
		if((*it)==par)	continue;
		maxBranch=max(maxBranch, dfs((*it), vrtx, l+1)); 
	}
	branch[vrtx]=maxBranch;
	return maxBranch+1;
}

int main(){
	int u, v, cnt, ans;
	cin>>n>>x;
	adjList.resize(n+2);
	fori(1, n){
		cin>>u>>v;
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	branch[0]=dfs(1, 1, 0);
	// fori(1, n+1)	cout<<parent[i]<<" ";
	// cout<<"\n";
	// fori(1, n+1)	cout<<dist[i]<<" ";
	// cout<<"\n";
	// fori(1, n+1)	cout<<branch[i]<<" ";
	// cout<<"\n";
	u=x, cnt=(dist[x]+1)/2-1;
	ans=dist[x]+branch[x];
	while(cnt > 0){
		u=parent[u];
		ans=max(ans, dist[u]+branch[u]);
		cnt--;
	}
	cout<<2*ans<<"\n";
	return 0;
}