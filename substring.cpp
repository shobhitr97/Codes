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

vector <vi> graph;
vi ts, deg;
vi cnt[26];
vector <bool> vis;
string s;
int maxm;

void fillDeg(int n){
	fori(0, n)	deg[i] = 0;
	fori(0, n){
		int siz = graph[i].size();
		forn(j, 0, siz)	deg[graph[i][j]]++;
	}
}

bool topSort(int n){
	queue <int> q;
	fillDeg(n);
	fori(0, n){
		if(deg[i] == 0)	q.push(i);
	}
	while(!q.empty()){
		int t = q.front();
		q.pop();
		ts.pb(t);
		forn(j, 0, graph[t].size()){
			deg[graph[t][j]]--;
			if(deg[graph[t][j]] == 0)	q.push(graph[t][j]);
		}
		n--;
	}

	if(n > 0)	return true;
	else	return false;
}

void dfsFill(int v){
	vis[v] = true;
	int siz = graph[v].size();
	fori(0, siz){
		if(vis[graph[v][i]] == false)	dfsFill(graph[v][i]);
	}
	fori(0, 26)	cnt[i][v] = 0;
	cnt[s[v]-'a'][v] = 1;
	fori(0, siz){
		int it = graph[v][i];
		forn(j, 0, 26){
			if(j == s[v]-'a')	cnt[j][v] = max(cnt[j][v], 1 + cnt[j][it]);
			else	cnt[j][v] = max(cnt[j][v], cnt[j][it]);
		}
	}
}

int main(){

	int n, m, u, v;

	cin>>n>>m;
	cin>>s;

	graph.resize(n);
	fori(0, m){
		scanf("%d %d", &u, &v);
		graph[u-1].pb(v-1);
	}

	deg.resize(n);
	if(topSort(n) == true){
		printf("-1\n");
		return 0;
	}

	// fori(0, n)	cout<<ts[i]<<" ";
	// cout<<"\n";

	vis.resize(n);
	fori(0, n)	vis[i] = false;
	fori(0, 26)	cnt[i].resize(n);
	fori(0, n){
		if(vis[ts[i]] == false)	dfsFill(ts[i]);
	}

	maxm = 0;
	fori(0, 26)	forn(j, 0, n)	maxm = max(maxm, cnt[i][j]);

	cout<<maxm<<"\n";

	return 0;
}