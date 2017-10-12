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
int n, m, parent[num];

int findParent(int x){
	if( parent[x] != x )	parent[x] = findParent(parent[x]);
	return parent[x];
}

int main(){
	
	int t, a, b, edgeCount, u, v;
	double x, y, r, weight;
	char ch;

	cin>>t;
	int z=0;
	while(t--){
		if(z>0)	cout<<"\n";
		if(z==0)	z++;
		cin>>n;
		fori(0, n){
			cin>>x>>y;
			coordinates.pb( mp(x, y) );
		}
		fori(1, n+1)	parent[i] = i;
		cin>>m;
		fori(0, m){
			cin>>a>>b;
			u=findParent(a);
			v=findParent(b);
			if(u!=v)	parent[u]=v;
		}

		edgeCount = 0;
		fori(0, n-1){
			for( int j=i+1 ; j<n ; j++ ){
				x = coordinates[i].first - coordinates[j].first;
				y = coordinates[i].second - coordinates[j].second;
				r = sqrt( x*x + y*y );
				edges.pb( mp( r, mp(i+1,j+1) ) );
				edgeCount++;
			}
		}
		sort( edges.begin(), edges.end() );

		int cnt = 0;
		fori(0, edgeCount){
			a = edges[i].second.first;
			b = edges[i].second.second;
			u=findParent(a);
			v=findParent(b);
			if(u!=v){
				cnt++;
				parent[u]=v;
				new_edges.pb( mp(a, b) );
			}
		}

		if( cnt>0 ){
			fori(0, cnt)	cout<<new_edges[i].first<<" "<<new_edges[i].second<<"\n";
		}
		else	cout<<"No new highways need\n";

		edges.clear();
		new_edges.clear();
		coordinates.clear();
	}
}