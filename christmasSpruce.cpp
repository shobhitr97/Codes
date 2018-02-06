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

vector<vi>graph;
bool flag = true;

int dfs(int vtx){
	int leaves = 0, siz = graph[vtx].size();
	if(siz == 0)	return 1;
	fori(0, siz){
		leaves += dfs(graph[vtx][i]);
	}
	// cout<<vtx+1<<" "<<leaves<<"\n";
	if(leaves < 3){
		flag = false;
	}
	return 0;
}

int main(){
	int n, x;
	cin>>n;
	graph.resize(n);
	fori(1, n){
		cin>>x;
		graph[x-1].pb(i);
	}
	x = dfs(0);

	if(flag == true)	cout<<"Yes\n";
	else	cout<<"No\n";

	return 0;
}