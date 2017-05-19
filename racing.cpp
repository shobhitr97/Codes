#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector< ii > vii;
typedef vector< vector< ii > > vvii;

#define pb push_back
#define mp make_pair
#define num 10005
#define fori(a, b) for( int i=a ; i<b ; i++ )
#define forin(a, b) for( int i=a ; i>=b ; i-- )

vvii graph;
vector< pair<int, pair<int,int> > > edges;

int n, m, parent[num];

int findRoot(int x){
	if( parent[x] == x ){
		return x;
	}
	else{
		parent[x] = findRoot( parent[x] );
		return parent[x];
	}
}

bool isSameSet(int x, int y){
	int parx, pary;
	parx = findRoot(x);
	pary = findRoot(y);
	return (parx == pary);
}

void dsuAdd(int x, int y){

	parent[ parent[x] ] = parent[y];
	int parx = findRoot(x);
}

int main(){
	
	int c, x, y, w, weightMST, weightCam;

	cin>>c;

	while(c--){

		cin>>n>>m;

		graph.resize(n+2);

		fori(0, m){
			cin>>x>>y>>w;
			edges.pb( mp( w, mp(x,y) ) );
		}

		sort(edges.begin(), edges.end() );

		fori(1, n+1){
			parent[i] = i;
		}

		weightMST = 0;
		weightCam = 0;

		forin(m-1, 0){
			x = edges[i].second.first;
			y = edges[i].second.second;
			w = edges[i].first;
			if( !isSameSet(x, y) ){
				graph[x].pb( mp(y, w) );
				graph[y].pb( mp(x, w) );
				weightMST += w;
				// cout<<"MSTRoad:("<<x<<","<<y<<") Weight:"<<w<<"\n";
				dsuAdd(x, y);
			}
			else{
				// cout<<"CamRoad:("<<x<<","<<y<<") Weight:"<<w<<"\n";
				weightCam += w;
			}
		}

		cout<<weightCam<<"\n";

		edges.clear();
		graph.clear();

	}

}
