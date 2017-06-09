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
typedef vector<vi> vvi;

#define pb push_back
#define mp make_pair
#define fori(a, b) for(int i=a ; i<b ; i++ )
#define forn(i, a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second

vector<pair<double, double> >coordinates;
vector<double>pop;
vector<pair<double, pair<int , int> > >edges;
vector<vector<pair<int, double> > > adjList;

double averageTime, timeN[54];

int parent[54];

int findParent(int x){
	if(parent[x]!=x)	parent[x]=findParent(parent[x]);
	return parent[x];
}

double max(double x, double y){
	if(x>y)	return x;
	return y;
}

void dfs(int vertex, int par, double timeYet){
	timeN[vertex]=timeYet;
	for(vector<pair<int, double> >::iterator it=adjList[vertex].begin();it!=adjList[vertex].end();it++){
		if((*it).fi==par)	continue;
		dfs((*it).fi, vertex, max(timeYet, (*it).se));
	}
}

int main(){
	int n, cnt, u, v, z;
	double x, y, m, r;
	z=0;
	while(1){
		z++;
		cin>>n;
		// cout<<n<<"\n";
		if(n==0)	break;
		// if(z>1)	cout<<"\n";
		adjList.resize(n+3);
		fori(0, n){
			cin>>x>>y>>m;
			coordinates.pb(mp(x, y));
			pop.pb(m);
		}
		cnt=0;
		fori(0, n){
			forn(j, i+1, n){
				x=coordinates[i].fi - coordinates[j].fi;
				y=coordinates[i].se - coordinates[j].se;
				r=sqrt(x*x+y*y);
				edges.pb(mp(r, mp(i, j)));				
				cnt++;
			}
		}
		sort(edges.begin(), edges.end());
		fori(0, n)	parent[i]=i;
		fori(0, cnt){
			u=findParent(edges[i].se.fi);
			v=findParent(edges[i].se.se);
			r=edges[i].fi;
			// cout<<edges[i].se.fi<<","<<edges[i].se.se<<" - "<<r<<"\n";
			if(u!=v){
				parent[u]=v;
				adjList[edges[i].se.fi].pb(mp(edges[i].se.se, r));
				adjList[edges[i].se.se].pb(mp(edges[i].se.fi, r));
			}
		}
		averageTime=0.0000000;
		m=0;
		dfs(0, 0, 0);
		// fori(0, n)	cout<<timeN[i]<<"\n";
		fori(0, n){
			averageTime+=timeN[i]*pop[i];
			m+=pop[i];
		}
		averageTime/=m;
		// cout<<averageTime<<"\n";
		printf("Island Group: %d Average %.2f\n", z, averageTime);
		cout<<"\n";
		edges.clear();
		adjList.clear();
		pop.clear();
		coordinates.clear();
	}

	return 0;
}