#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<utility>
#include<queue>

using namespace std;

typedef long long int ll;
typedef vector<int> vec;
typedef vector<vector<int> > vvec;
typedef vector< pair<int, ll> > vecp;
typedef vector< vector< pair<int, ll> > > vvecp;

#define Num 100005
#define num 400005
#define numl 905000
#define inf 1000000007
#define fori(a,b) for( int i=a ; i<b ; i++ )
#define forj(a,b) for( int j=a ; j<b ; j++ )
#define pb push_back
#define mp make_pair
#define forit(p) for( vector<int>::iterator it = p.begin() ; it != p.end() ; it++ )

int max(int a, int b){
	if(a>b){
		return a;
	}
	return b;
}

ll min( ll a, ll b){
	if( a<b ){
		return a;
	}
	return b;
}

int n, q, s, maxm1, maxm2;
ll seg_tree[numl], w[num], val[numl];
vvecp rel;
bool vis[numl];

// class compare{
// public:
// 	bool operator() (const int& a, const int& b) const
// 	{
// 		return val[a]<val[b];
// 	}
// }

struct CustomCompare
{
    bool operator()(const int& lhs, const int& rhs)
    {
        return val[lhs] > val[rhs];
    }
};

// bool compare(int a, int b){
// 	return (val[a]<val[b]);
// }

priority_queue< int, vec, CustomCompare > pq;

// 1 -> 4n would contain the seg_tree that has edges from nodes to the ranges
// 4n+1 -> 8n would contain the seg_tree that has edges from the ranges to the nodes
// 8n+1 -> 9n would contain the the actual nodes that we were supposed to have

void print_queue(){

	while( !pq.empty() ){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<"\n";

}

void printp( vvecp pp ,int N){

	vecp::iterator it;

	fori(1, N+1){
		cout<<i<<" -> ";
		for( it = pp[i].begin() ; it != pp[i].end() ; it++ ){
			cout<<"("<<(*it).first<<","<<(*it).second<<")   ";
		}
		cout<<"\n";
	}

}

void create_seg1(int index, int l, int r){

	if( l>r || l < 1 || r > n ){
		return;
	}

	// cout<<index<<":";

	if( r == l ){
		rel[index].pb(mp(8*n + l, 0) );
		maxm1 = max( maxm1, index);
		// cout<<index<<" -> "<<(4*n+l);
	}
	else{

		int mid = (l+r)/2;

		rel[index].pb( mp(2*index, 0) );
		rel[index].pb( mp(2*index + 1, 0) );
		
		create_seg1(2*index, l, mid);
		create_seg1(2*index+1, mid+1, r);

	}
	// cout<<"\n";

}
void create_seg2(int index, int l, int r){

	if( l>r || l < 1 || r > n ){
		return ;
	}

	// cout<<index<<":";

	if( r==l ){
		rel[8*n + l].pb( mp( 4*n + index, 0) );
		// cout<<(4*n+l)<<" -> "<<(2*n+index);
		maxm2 = max( 4*n + index, maxm2);
	}
	else{

		int mid = (l+r)/2;

		rel[2*index + 4*n].pb( mp( 4*n + index, 0) );
		rel[2*index + 1 + 4*n].pb( mp( 4*n + index, 0) );

		create_seg2(2*index, l ,mid);
		create_seg2(2*index + 1, mid+1, r);
																				  
	}
	// cout<<"\n";

}


// l, r  is the range which represents the forthcoming node and x, y represents the range we are looking for
void find_seg1(int index, int l, int r, int x, int y, int u, ll weight){

	if( l>r || l < 1 || r > n ){
		return;
	}

	if( y < l || x > r ){
		return;
	}

	int mid = (l+r)/2;

	// rel[]

	if( ( x <= l && l <= y) && ( x <= r && r <= y ) ){
		rel[u].pb( mp(index, weight) );
		// cout<<u<<" -> "<<l<<":"<<r<<" -- "<<index<<" "<<weight<<"\n";
		return ;
	}

	find_seg1(2*index, l, mid, x, y, u, weight);
	find_seg1(2*index + 1, mid + 1, r, x, y, u, weight);

}

void find_seg2(int index, int l, int r, int x, int y, int u, ll weight){

	if( l>r || l < 1 || r > n ){
		return;
	}

	if( y < l || x > r ){
		return;
	}

	int mid = (l+r)/2;

	// rel[]

	if( ( x <= l && l <= y) && ( x <= r && r <= y ) ){
		rel[index].pb( mp(u, weight) );
		// cout<<u<<" -> "<<l<<":"<<r<<" -- "<<index<<" "<<weight<<"\n";
		return ;
	}

	find_seg2(2*(index - 4*n ) + 4*n , l, mid, x, y, u, weight);
	find_seg2(2*(index - 4*n ) + 1 + 4*n , mid + 1, r, x, y, u, weight);	

}

void djikstra(){

	
	int index;
	int u;
	ll weight;
	vecp::iterator it;

	val[8*n + s] = 0;
	pq.push(8*n + s);

	while( !pq.empty() ){

		index = pq.top();

		// cout<<index<<"\n";

		pq.pop();

		if( vis[index] ){
			continue;
		}

		vis[index] = 1;


		for( it = rel[index].begin() ; it != rel[index].end() ; it++ ){

			u = (*it).first;
			weight = (*it).second;

			// cout<<u<<" ";
			if( val[u] == -1 ){
				val[u] = val[index] + weight;
			}
			else{
				val[u] = min(val[u], val[index] + weight);
			}

			pq.push(u);

		}
		// cout<<"\n";

		// cout<<(pq.empty())<<"\n";
	}

}

int main(){


	int k, v, u, l, r;
	ll weight;

	cin>>n>>q>>s;

	rel.resize( 9*n + 100 );

	maxm1 = 0;
	maxm2 = 0;

	create_seg1(1, 1, n);
	create_seg2(1, 1, n);

	fori(0,q){
		cin>>k;
		switch(k){
			case 1:
			cin>>v>>u>>weight;
			rel[8*n + v].pb( mp(8*n + u, weight) );
			break;
			case 2:
			cin>>v>>l>>r>>weight;
			find_seg1(1, 1, n, l, r, 8*n + v, weight);
			break;
			case 3:
			cin>>v>>l>>r>>weight;
			find_seg2(4*n + 1, 1, n, l, r, 8*n + v, weight);
			break;
		}
	}

	// printp(rel, 5*n);


	// val[1] = 23;
	// val[2] = 34;
	// pq.push(1);
	// pq.push(2);

	fori(1,9*n +1){
		val[i] = -1;
		vis[i] = 0;
		// cout<<i<<" "<<val[i]<<"\n";
	}

	djikstra();

	// fori(4*n+1, 5*n + 1){
	// 	cout<<val[i]<<"\n";
	// }

	// fori(1, maxm1+1){
	// 	cout<<"("<<i<<","<<val[i]<<")"<<"   ";
	// }

	// fori(2*n+1, maxm2+1){
	// 	cout<<"("<<i<<","<<val[i]<<")"<<"   ";
	// }

	fori(8*n+1, 9*n+1){
		cout<<val[i]<<" ";
	}
	cout<<"\n";

	return 0;
}