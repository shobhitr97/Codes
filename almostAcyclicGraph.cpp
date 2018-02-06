#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>

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
#define NUM 100005

vii edges, query;
vector<vi> graph;
bool explored[NUM], visited[NUM];
int n, m, index, par[NUM], pre[NUM], post[NUM];

void dfs(int u){
	pre[u] = index;
	index++;
	explored[u] = true;

	int v, siz = graph[u].size();

	fori(0, siz){
		v = graph[u][i];
		if(visited[v] == true)	continue;
		if(explored[v] == true)	query.pb(mp(u, v));
		else{
			par[v] = u;
			dfs(v);
		}
	}

	visited[u] = true;
}

int main(){

	int u, v, siz;
	bool flag = true;

	cin>>n>>m;

	graph.pb(n);

	fori(0, m){
		scanf("%d %d", &u, &v);
		edges.pb(mp(u-1, v-1));
		graph[u-1].pb(v-1);
	}

	memset(visited, false, sizeof(visited));
	memset(explored, false, sizeof(explored));

	index = 0;
	fori(0, n){
		if(visited[i] == false){
			par[i] = i;
			dfs(i);
		}
	}

	siz = query.size();
	if(siz > 1){
		memset(visited, false, sizeof(visited));
		
		u = query[0].fi;
		v = query[0].se;

		visited[v] = true;

		while(u != v){
			visited[u] = true;
			u = par[u];
		}

		
	}

	if(flag == true)	cout<<"YES\n";
	else	cout<<"NO\n";

	return 0;
}