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
#define fornn(i, a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second

vector<pair<double, pair<double, double> > > dims;
vector<vi> adjList;
int n, counter, visited[105];

void dfs(int vertex){
	visited[vertex]=1;
	counter++;
	vi::iterator it;
	for(it=adjList[vertex].begin();it!=adjList[vertex].end();it++){
		if(visited[(*it)])	continue;
		dfs((*it));
	}
}

int main(){

	double x, y, r, r1, r2;
	int maxm;

	while(1){
		cin>>n;
		if(n==-1)	break;
		if(n==0){
			cout<<"The largest component contains 0 rings.\n";
			continue;
		}
		forn(i, 0, n){
			cin>>x>>y>>r;
			dims.pb(mp(r, mp(x, y)));
		}
		adjList.resize(n+2);
		forn(i, 0, n){
			forn(j, i+1, n){
				x=dims[i].se.fi-dims[j].se.fi;
				y=dims[i].se.se-dims[j].se.se;
				r=(x*x+y*y);
				r1=(dims[i].fi-dims[j].fi)*(dims[i].fi-dims[j].fi);
				r2=(dims[i].fi+dims[j].fi)*(dims[i].fi+dims[j].fi);
				// cout<<"("<<i+1<<","<<j+1<<") ->"<<r<<", "<<r1<<", "<<r2<<"\n";
				if(r>r1 && r<r2){
					adjList[i].pb(j);
					adjList[j].pb(i);
				}
			}
		}
		fori(0, n)	visited[i]=0;
		maxm=0;
		fori(0, n){
			if(visited[i])	continue;
			counter=0;
			dfs(i);
			maxm=max(maxm, counter);
		}
		if(maxm>1)	cout<<"The largest component contains "<<maxm<<" rings.\n";
		else	cout<<"The largest component contains 1 ring.\n";
		adjList.clear();
		dims.clear();
	}


	return 0;
}