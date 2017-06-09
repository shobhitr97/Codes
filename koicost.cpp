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
#define num 100005
#define mod 1000000000

viii edges;
int n, m, parent[num];
ll size[num];

int findParent(int x){
	if(parent[x]!=x)	parent[x]=findParent(parent[x]);
	return parent[x];
}

int main(){
	
	int u, v, w;
	ll k, total, weight[num];
	cin>>n>>m;

	fori(0, 100001)	weight[i]=0;
	fori(0, m){
		cin>>u>>v>>w;
		weight[w]=w;
		edges.pb(mp(w, mp(u, v)));
	}
	fori(1, 100001)	weight[i]=(weight[i]+weight[i-1])%mod;

	sort(edges.begin(), edges.end(), greater<iii>());
	// reverse(edges.begin(), edges.end());
	total=0;
	fori(1, n+1)	parent[i]=i, size[i]=1;
	fori(0, m){
		u=findParent(edges[i].se.fi);
		v=findParent(edges[i].se.se);
		w=edges[i].fi;
		if(u!=v){
			k=(size[u]*size[v])%mod;
			total=(total+(k*weight[w])%mod)%mod;
			if(size[u]>size[v]){
				parent[v]=u;
				size[u]+=size[v];
			}
			else{
				parent[u]=v;
				size[v]+=size[u];
			}
		}
	}
	cout<<total<<"\n";
	edges.clear();
	return 0;
}