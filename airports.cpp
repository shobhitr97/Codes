#include<iostream>
#include<vector>
#include<stdio.h>
#include<utility>
#include<algorithm>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;

#define num 100005
#define mp make_pair
#define pb push_back
#define fori(a, b) for( int i=a ; i<b ; i++ )
#define fi first
#define se second

int n, m, a, parent[num], vis[num], z;
viii edges;
ll cost;

int findParent(int x){
	if(parent[x] == x){
		return x;
	}
	parent[x] = findParent(parent[x]);
	return parent[x];
}
bool isSameSet(int x, int y){
	int parx = findParent(x);
	int pary = findParent(y);
	return (parx == pary);
}
void dsuJoin(int x, int y){
	parent[ parent[x] ] = parent[y];
}

int main(){	

	int t ,x, y, c;
	cin>>t;

	for(int k=1 ; k<=t ; k++ ){
		cin>>n>>m>>a;
		fori(1, n+1){
			parent[i] = i;
			vis[i] = 0;
		}
		cost = 0;
		z = n;
		fori(0, m){
			cin>>x>>y>>c;
			edges.pb( mp(c, mp(x,y) ) );
		}
		sort(edges.begin(), edges.end() );
		fori(0, m){
			x = edges[i].se.fi;
			y = edges[i].se.se;
			c = edges[i].fi;
			if( c >= a ){
				break;
			}
			if( isSameSet(x, y) == 0 ){
				z--;
				cost += c;
				dsuJoin(x, y);
			}
		}
		cost = cost + a*z;
		cout<<"Case #"<<k<<": "<<cost<<" "<<z<<"\n";
		edges.clear();
	}
	return 0;	
}