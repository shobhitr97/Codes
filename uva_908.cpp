#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>

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
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define num 105
#define INF 1000000007

int n, m ,parent[num];// visit[num], maxm;
viii edges;

int findRoot(int x){
	if( parent[x] != x )	parent[x] = findRoot(parent[x]);
	return parent[x];
}

bool isSameSet(int x, int y){
	int parx = findRoot(x);
	int pary = findRoot(y);
	return (parx == pary); 
}

void dsuAdd(int x, int y){
	parent[ parent[x] ] = parent[y];
}

int main(){

	int u, v, w, origCost, cost, k, flag=0;

	while(cin>>n){
		if(flag)	cout<<"\n";
		if(flag==0)	flag=1;
		fori(1, n+1)	parent[i]=i;
		origCost=0;
		fori(0, n-1){
			cin>>u>>v>>w;
			origCost+=w;
		}
		cin>>k;
		fori(0, k){
			cin>>u>>v>>w;
			edges.pb(mp(w, mp(u, v)));
		}
		cin>>m;
		fori(0, m){
			cin>>u>>v>>w;
			edges.pb(mp(w, mp(u, v)));
		}
		sort(edges.begin(), edges.end());
		cost=0;
		fori(0, m){
			w=edges[i].fi;
			u=edges[i].se.fi;
			v=edges[i].se.se;
			if(!isSameSet(u, v)){
				cost+=w;
				// cout<<w<<":("<<u<<","<<v<<")\n";
				dsuAdd(u, v);
			}
		}
		cout<<origCost<<"\n";
		cout<<cost<<"\n";
		// cout<<"\n";
		edges.clear();
	}

	return 0;
}