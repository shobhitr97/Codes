#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>

using namespace std;

typedef pair<int, int> ii;
typedef pair<double, double> dd; 
typedef vector< ii > vii;
typedef vector< dd > vdd;
typedef vector< pair< double, ii > > vdii;
typedef vector< vector< pair< int, double> > > vvid;

#define num 752
#define N 1003
#define fori(a, b) for( int i=a ; i<b ; i++ )
#define forin(a, b) for( int i=a ; i>=b ; i-- )
#define pb push_back
#define mp make_pair

vdd coordinates;
vdii edges;
vii new_edges;
vvid graph;
int n, m, parent[num];
bool adjMatrix[num][num];

int findRoot(int x){
	if( parent[x] == x ){
		return x;
	}
	else{
		parent[x] = findRoot(parent[x]);
		return parent[x];
	}
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
	
	int t, a, b, edgeCount;
	double x, y, r, weight;
	char ch;

	cin>>t;
	// cin>>ch;
	// cin>>ch;

	while(t--){

		cin>>n;
		// cout<<n<<"\n";
		fori(0, n){
			cin>>x>>y;
			coordinates.pb( mp(x, y) );
		}

		fori(0, n+1){
			for( int j=0 ; j<n+1 ; j++ ){
				adjMatrix[i][j] = 0;
			}
		}

		fori(1, n+1){
			parent[i] = i;
		}

		graph.resize(n+3);

		cin>>m;

		fori(0, m){
			cin>>a>>b;
			adjMatrix[a][b] = 1;
			if( !isSameSet(a, b) ){
				dsuAdd(a, b);
			}
		}

		weight = 0;
		edgeCount = 0;
		fori(0, n-1){
			for( int j=i+1 ; j<n ; j++ ){
				x = coordinates[i].first - coordinates[j].first;
				y = coordinates[i].second - coordinates[j].second;
				r = sqrt( x*x + y*y );
				if( !adjMatrix[i+1][j+1] ){
					edges.pb( mp( r, mp(i+1,j+1) ) );
					edgeCount++;
				}
				else{
					graph[i+1].pb( mp(j+1, r) );
					graph[j+1].pb( mp(i+1, r) );
					weight += r;
				}
			}
		}

		sort( edges.begin(), edges.end() );

		int count = 0;

		fori(0, edgeCount){
			a = edges[i].second.first;
			b = edges[i].second.second;
			if( !isSameSet(a, b) ){
				count++;
				dsuAdd(a, b);
				new_edges.pb( mp(a, b) );
				graph[a].pb( mp(b, edges[i].first) );
				graph[b].pb( mp(a, edges[i].first) );
				weight += edges[i].first;
			}
		}

		if( count>0 ){
			fori(0, count){
				cout<<new_edges[i].first<<" "<<new_edges[i].second<<"\n";
			}
		}
		else{
			cout<<"No new highways need\n";
		}

		graph.clear();
		edges.clear();
		new_edges.clear();
		coordinates.clear();

	}

}