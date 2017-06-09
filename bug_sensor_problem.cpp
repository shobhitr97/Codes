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
typedef vector<pair<double, ii > > vdii;

#define pb push_back
#define mp make_pair
#define fori(a, b) for(int i=a ; i<b ; i++ )
#define forn(i, a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second

vdii edges, minEdges;
vector<double> maxEdge;
vector<pair<double, double> >coordinates;
vi parent;

int findParent(int x){
	if(parent[x]!=x)	parent[x]=findParent(parent[x]);
	return parent[x];
}

int main(){
	int t, cntSenRec, cnt, n, m, u, v;
	vector<double>maxm;
	double x, y, r;
	cin>>t;
	while(t--){
		cin>>cntSenRec;
		n=0;
		m=0;
		while(1){
			cin>>x;
			if(x==-1)	break;
			cin>>y;
			coordinates.pb(mp(x, y));
			n++;
		}
		// cout<<"Number: "<<n<<"\n";
		forn(i, 0, n){
			forn(j, i+1, n){
				x=coordinates[i].fi - coordinates[j].fi;
				y=coordinates[i].se - coordinates[j].se;
				r=sqrt(x*x+y*y);
				edges.pb(mp(r, mp(i, j)));
				m++;
			}
		}
		sort(edges.begin(), edges.end());
		fori(0, n)	parent.pb(i);
		cnt=0;
		// fori(0, m)	cout<<edges[i].se.fi<<","<<edges[i].se.se<<" : "<<edges[i].fi<<"\n";
		fori(0, m){
			u=findParent(edges[i].se.fi);
			v=findParent(edges[i].se.se);
			if(u!=v){
				// cout<<edges[i].se.fi<<","<<edges[i].se.se<<" : "<<edges[i].fi<<"\n";
				minEdges.pb(edges[i]);
				parent[u]=v;
				cnt++;
			}
		}
		// cout<<"Number of edges in MST: "<<cnt<<"\n";
		if(cnt>(cntSenRec-1)){
			// fori(0, n)	parent[i]=i;
			// fori(0, n)	maxm.pb(0);
			// fori(0, cnt-cntSenRec){
			// 	u=findParent(minEdges[i].se.fi);
			// 	v=findParent(minEdges[i].se.se);
			// 	r=edges[i].fi;
			// 	if(u!=v){

			// 		parent[u]=v;
			// 	}
			// }
			cout<<((int)ceil(minEdges[cnt-(cntSenRec-1)-1].fi))<<"\n";
		}
		else{
			cout<<"0\n";
		}
		minEdges.clear();
		edges.clear();
		parent.clear();
		coordinates.clear();
	}
	return 0;
}