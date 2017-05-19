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
#define num 100005
#define mod 1000000000

viii edges;
int n, m, parent[num], size[num];

int findParent(int x){
	if(parent[x]==x)	return x;
	parent[x]=findParent(parent[x]);
	return parent[x];
}

int isSameSet(int a, int b){
	int para, parb;
	para=findParent(a);
	parb=findParent(b);
	return (para==parb);
}

void dsu(int a, int b){
	if(size[ parent[a] ]<size[ parent[b] ]){
		size[ parent[b] ]+=size[ parent[a] ];
		// size[ parent[a] ]=0;
		parent[ parent[a] ]=parent[b];
	}
	else{
		size[ parent[a] ]+=size[ parent[b] ];
		// size[ parent[b] ]=0;
		parent[ parent[b] ]=parent[a];
	}
	parent[a]=parent[b];
	size[parent[a]]
}

int main(){
	
	int u, v, w, weight[num];
	ll k, total;
	cin>>n>>m;

	fori(1, n+1){
		parent[i]=i;
		size[i]=1;
	}

	fori(0, 100001){
		weight[i]=0;
	}

	fori(0, m){
		cin>>u>>v>>w;
		weight[w]=w;
		edges.pb(mp(w, mp(u, v)));
	}

	sort(edges.begin(), edges.end());
	reverse(edges.begin(), edges.end());

	fori(1, 100001){
		weight[i]+=weight[i-1];
	}

	total=0;
	fori(0, m){
		u=edges[i].se.fi;
		v=edges[i].se.se;
		w=edges[i].fi;
		if(!isSameSet(u, v)){
			k=(size[ parent[u] ]*size[ parent[v] ]);
			total=(total+(k*weight[w])%mod)%mod;
			ll siz = size[ parent[u] ]+size[ parent[v] ];
			// size[ parent[u] ]=siz;
			// size[ parent[v] ]=siz;
			// parent[u]=parent[v];
			dsu(u, v);
		}
	}

	cout<<total<<"\n";

	return 0;
}