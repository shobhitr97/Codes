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
#define num 10004

int n, c[num], ans;
vector<vi> rel;
vector<bool> vis;

void dfs(int v, int clr){
	vis[v] = true;
	if(clr != c[v])	ans++;
	int siz = rel[v].size();
	fori(0, siz){
		if(vis[rel[v][i] ] == false)	dfs(rel[v][i], c[v]);
	}
}

int main(){

	int x;

	cin>>n;

	rel.resize(n);
	vis.resize(n);

	fori(2, n+1){
		cin>>x;
		rel[x-1].pb(i-1);
		rel[i-1].pb(x-1);
	}

	fori(0, n)	cin>>c[i];

	ans = 0;
	fori(0, n)	vis[i] = false;
	dfs(1, -1);

	cout<<ans<<"\n";

	return 0;
}