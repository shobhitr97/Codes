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
#define forn(i, a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second

viii edges;
int parent[100005], n, m;

int findRoot(int x){
	if(parent[x]!=x)	parent[x] = findRoot(parent[x]);
	return parent[x];
}

int main(){

	int u, v, w, countEdges, cost;

	while(1){
		cin>>n>>m;
		if(!n&&!m)	break;
		fori(0, m){
			cin>>u>>v>>w;
			edges.pb(mp(w, mp(u, v)));
		}
		fori(0, n)	parent[i]=i;
		sort(edges.begin(), edges.end());
		countEdges=0;
		cost=0;
		for(viii::iterator it=edges.begin();it!=edges.end();it++){
			u=findRoot((*it).se.fi);
			v=findRoot((*it).se.se);
			w=(*it).fi;
			if(u!=v){
				countEdges++;
				cost=max(cost, w);
				parent[u]=v;
				if(countEdges==n-1)	break;
			}
		}
		if(countEdges!=n-1)	cout<<"IMPOSSIBLE\n";
		else	cout<<cost<<"\n";
		edges.clear();
	}


	return 0;
}