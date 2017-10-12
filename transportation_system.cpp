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
typedef vector<pair<double, pair<int, int> > > vdii;

#define pb push_back
#define mp make_pair
#define fori(a, b) for(int i=a ; i<b ; i++ )
#define forn(i, a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define num 1005

int parent[num], n;
vector<pair<double, double> >dims;

int findRoot(int x){
	if(parent[x]!=x)	parent[x] = findRoot(parent[x]);
	return parent[x];
}

int main(){

	int t, u, v, cost1, cost2, cnt, visited[1005];
	double r, x, y, cost_rail, cost_roads, d, s;
	vdii roads, railroads;

	cin>>t;
	forn(z, 0, t){
		
		cin>>n>>r;

		fori(0, n){
			cin>>x>>y;
			dims.pb(mp(x, y));
		}

		cost_roads=0;
		cost_rail=0;
		r=(r*r);

		fori(0, n){
			forn(j, i+1, n){
				d=(dims[i].fi-dims[j].fi)*(dims[i].fi-dims[j].fi)+(dims[i].se-dims[j].se)*(dims[i].se-dims[j].se);
				s=sqrt(d);
				if(d<=r)	roads.pb(mp(s, mp(i, j)));
				else	railroads.pb(mp(s, mp(i, j)));
			}
		}		

		sort(roads.begin(), roads.end());
		sort(railroads.begin(), railroads.end());

		fori(0, n)	parent[i]=i;
		fori(0, n)	visited[i]=0;

		for(vdii::iterator it=roads.begin();it!=roads.end();it++){
			u=findRoot((*it).se.fi);
			v=findRoot((*it).se.se);
			s=(*it).fi;
			if(u!=v){
				cost_roads+=s;
				parent[u]=v;
			}
		}

		cnt=0;
		for(vdii::iterator it=railroads.begin();it!=railroads.end();it++){
			u=findRoot((*it).se.fi);
			v=findRoot((*it).se.se);
			s=(*it).fi;
			if(u!=v){
				if(!visited[u]){
					visited[u]=1;
					cnt++;
				}
				if(!visited[v]){
					visited[v]=1;
					cnt++;
				}
				cost_rail+=s;
				parent[u]=v;
			}
			else{
				if(!visited[u]){
					visited[u]=1;
					cnt++;
				}
			}
		}	

		cost1=(int)floor(cost_roads);
		if((cost_roads-floor(cost_roads))>0.5)	cost1++;
		cost2=(int)floor(cost_rail);
		if((cost_rail-floor(cost_rail))>0.5)	cost2++;

		if(!cnt)	cnt++;

		cout<<"Case #"<<z+1<<": "<<cnt<<" "<<cost1<<" "<<cost2<<"\n";
		
		railroads.clear();
		roads.clear();
		dims.clear();
		
	}

	return 0;
}