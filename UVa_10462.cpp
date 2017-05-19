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
// vector<vector<ii> > mstAdjMat;

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

	int t, u, v, w, cost, countEdges, taken[num], minm, j;

	cin>>t;
	for(int x=1; x<=t ; x++ ){
		cin>>n>>m;
		fori(1, n+1)	parent[i]=i;
		fori(0, m){
			cin>>u>>v>>w;
			edges.pb(mp(w, mp(u, v)));
		}
		sort(edges.begin(), edges.end());
		cost=0;
		countEdges=0;
		j=0;
		fori(0, m){
			w=edges[i].fi;
			u=edges[i].se.fi;
			v=edges[i].se.se;
			if(!isSameSet(u, v)){
				cost+=w;
				// cout<<w<<":("<<u<<","<<v<<")\n";
				taken[j++]=i;
				dsuAdd(u, v);
				countEdges++;
				if(countEdges==n-1)	break;
			}
		}
		// cout<<"-------\n";
		if(countEdges!=(n-1))	cout<<"Case #"<<x<<" : No way\n";
		else{
			// cout<<"!!!!\n";
			minm=INF;
			fori(0, j){
				// cout<<i+1<<"\n";
				countEdges=0;
				cost=0;
				for(int k=1; k<n+1 ; k++ )	parent[k]=k;
				for(int k=0; k<m ; k++ ){
					if(k==taken[i])	continue;
					w=edges[k].fi;
					u=edges[k].se.fi;
					v=edges[k].se.se;
					if(!isSameSet(u, v)){
						cost+=w;
						// cout<<w<<":("<<u<<","<<v<<")\n";
						dsuAdd(u, v);
						countEdges++;
						if(countEdges==n-1)	break;
					}
				}
				if( countEdges==n-1 && cost<minm ){minm=cost;	}
				// cout<<cost<<"\n";
				// for(int k=1 ; k<n+1 ; k++ ){cout<<parent[k]<<" ";}
				// cout<<"\n";
			}
			if(minm==INF)	cout<<"Case #"<<x<<" : No second way\n";
			else	cout<<"Case #"<<x<<" : "<<minm<<"\n"; 
		}
		edges.clear();
	}

	return 0;
}