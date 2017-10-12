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

vector<iii>edges, includedEdges, excludedEdges;
int parent[20];

int findParent(int x){
	if(parent[x]!=x)	parent[x]=findParent(parent[x]);
	return parent[x];
}

int main(){
	int n, m, z, u, v, c, cost, cntEdges, marked[30], cntExcEdges, k;
	bool flag;
	z=0;
	while(1){
		z++;
		cin>>n>>m;
		if(!n&&!m)	break;
		fori(0, m){
			cin>>u>>v>>c;
			edges.pb(mp(c, mp(u, v)));
		}
		sort(edges.begin(), edges.end());
		cost=0;
		cntEdges=0;
		cntExcEdges=0;
		fori(1, n+1)	parent[i]=i;
		fori(0, m){
			u=findParent(edges[i].se.fi);
			v=findParent(edges[i].se.se);
			c=edges[i].fi;
			if(u==v){
				excludedEdges.pb(edges[i]);
				cntExcEdges++;
			}
			else{
				parent[u]=v;
				cost+=c;
				includedEdges.pb(edges[i]);
				cntEdges++;
			}
		}
		forn(j, 0, cntExcEdges)	cout<<excludedEdges[j].se.fi<<","<<excludedEdges[j].se.se<<" - "<<excludedEdges[j].fi<<"\n";
		fori(0, cntEdges)	cout<<includedEdges[i].se.fi<<","<<includedEdges[i].se.se<<" - "<<includedEdges[i].fi<<"\n";
		fori(0, cntExcEdges)	marked[i]=0;
		fori(0, cntEdges){
			cout<<"Considering:"<<includedEdges[i].se.fi<<","<<includedEdges[i].se.se<<" - "<<includedEdges[i].fi<<"\n";
			forn(j, 1, n+1)	parent[j]=j;
			forn(j, 0, cntEdges){
				if(j==i){
					cout<<"Missed:"<<includedEdges[i].se.fi<<","<<includedEdges[i].se.se<<" - "<<includedEdges[i].fi<<"\n";
					continue;
				}
				u=findParent(includedEdges[j].se.fi);
				v=findParent(includedEdges[j].se.se);
				if(u!=v)	parent[u]=v;
			}
			flag=false;
			forn(j, 0, cntExcEdges){
				u=findParent(excludedEdges[j].se.fi);
				v=findParent(excludedEdges[j].se.se);
				cout<<u<<","<<v<<"\n";
				if(u!=v){
					cout<<"Included:"<<excludedEdges[j].se.fi<<","<<excludedEdges[j].se.se<<" - "<<excludedEdges[j].fi<<"\n";
					flag=true;
					if(marked[j])	continue;
					marked[j]=1;
					cost+=excludedEdges[j].fi;
					break;
				}
			}
			if(flag==false){
				break;
			}
		}
		if(flag==false)	printf("There is no reliable net possible for test case %d.\n", z);
		else	printf("The minimal cost for test case %d is %d.\n", z, cost);
		edges.clear();
		excludedEdges.clear();
		includedEdges.clear();
	}
	return 0;
}