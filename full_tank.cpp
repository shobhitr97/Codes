#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair<int, int> ii;
typedef pair< ii, int > pi;
typedef vector<ii> vii;
typedef vector< vii > vvii;

#define fori(a, b) for( int i=a ; i<b ; i++ )
#define pb push_back
#define mp make_pair
#define A 1003
#define B 10003
#define C 103

int n, m, p[A], c, s, e, vis[A][C];
vvii roads;

class myComparison{
public:
	bool operator() (const pi& lhs, const pi& rhs) const
	{
		return ( lhs.second > rhs.second );
	}	
};
priority_queue< pi, vector<pi>, myComparison > pq;

int main(){

	int u, v, d, q, i, pos, fuel, cost;

	cin>>n>>m;

	fori(0, n){
		cin>>p[i];
	}

	roads.resize(n+3);

	fori(0, m){
		cin>>u>>v>>d;
		roads[u].pb( mp(v, d) );
		roads[v].pb( mp(u, d) );
	}

	cin>>q;

	vii::iterator it;

	while(q--){
		cin>>c>>s>>e;

		fori(0, 1001){
			for(int j=0 ; j<101; j++ ){
				vis[i][j] = 0;
			}
		}

		pq.push( mp( mp(s, 0), 0) );

		while( !pq.empty() ){
			pi x = pq.top();
			pq.pop();

			pos = x.first.first;
			fuel = x.first.second;
			cost = x.second;

			if( vis[pos][fuel] == 1 ){
				continue;
			}

			vis[pos][fuel] = 1;

			if( pos == e ){
				while(!pq.empty()){
					pq.pop();
				}
				cout<<cost<<"\n";
				break;
			}

			for( it = roads[pos].begin() ; it != roads[pos].end() ; it++ ){
				if( fuel >= (*it).second ){
					if( vis[ (*it).first ][ fuel-(*it).second ] == 0 ){
						pq.push( mp( mp( (*it).first, fuel - (*it).second ), cost ) );
					}
				}
			}

			if( fuel + 1 <= c ){
				pq.push(mp( mp( pos, fuel+1), cost+p[pos] ) );
			}
		}

		bool flag =0;
		fori(0, c+1){
			if( vis[e][i] == 1 ){
				flag = 1;
				break;
			}
		}
		if( flag == 0 ){
			cout<<"impossible\n";
		}

		
	}

	return 0;
}