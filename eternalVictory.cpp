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
#define num 100005

int n;
ll dp[num], dpLast[num];
vector<vii> graph;
bool vis[num];

void dfs(int vertex){
	vis[vertex] = true;
	int siz = graph[vertex].size(), child = -1;
	ll val = 0;
	ii p;
	fori(0, siz){
		p = graph[vertex][i];
		if(vis[p.fi] == true)	continue;
		dfs(p.fi);
		if(dp[p.fi] - dpLast[p.fi] + p.se >= val){
			val = dp[p.fi] - dpLast[p.fi] + p.se;
			child = i;
		}
		dp[vertex] += ( 2*p.se + dp[p.fi] );
	}
	if(child != -1){
		p = graph[vertex][child];
		dpLast[vertex] = dp[vertex] - (dp[p.fi] - dpLast[p.fi] + p.se);
	}
}

int main(){

	int u, v, w, maxW, siz, vtx;
	ll ans = 0;

	cin>>n;
	graph.resize(n);
	fori(0, n-1){
		scanf("%d %d %d", &u, &v, &w);
		graph[u-1].pb( mp(v-1, w) );
		graph[v-1].pb( mp(u-1, w) );
	}

	fori(0, n){
		vis[i] = false;
		dp[i] = 0;
		dpLast[i] = 0;
	}

	dfs(0);

	// fori(0, n){cout<<(i+1)<<": "<<dist[i]<<"\n";}

	// fori(0, n)	vis[i] = false;

	// int children = graph[vtx].size(), child = 0;
	// vtx = 0;
	// ll temp;
	// while(children > 0 && children == 1){
	// 	vtx = child;
	// 	children = 0;
	// 	temp = 0;
	// 	vis[vtx] = true;
	// 	fori(0, graph[vtx].size()){
	// 		if(vis[graph[vtx][i].fi] == false){
	// 			children++;
	// 			child = graph[vtx][i].fi;
	// 			temp += graph[vtx][i].se;
	// 		}
	// 	}
	// 	cout<<vtx<<":"<<children<<"\n";
	// 	if(children == 1){
	// 		cout<<child<<"\n";
	// 		ans += temp;
	// 	}
	// }

	// if(children > 0){
	// 	siz = graph[vtx].size();
	// 	maxW = 0;
	// 	fori(0, siz){
	// 		maxW = max(maxW, graph[vtx][i].se);
	// 	}
	// 	ans += (dist[vtx] - maxW);
	// }

	cout<<dpLast[0]<<"\n";

	return 0;
}