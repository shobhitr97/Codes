#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>

using namespace std;

typedef long long int ll;
typedef vector< vector <int> > vvec;
typedef vector< int > vec;

#define num 200005

ll w[num],p[num],sum[num],sum_node[num];
int parent[num],child[num],n,flag;

bool vis[num];

vvec rel;

ll max( ll a, ll b){
	if(a>b){
		return a;
	}
	return b;
}

ll min( ll a, ll b){
	if(a<b){
		return a;
	}
	return b;
}

// in rel the edge index is pushed
// sum is also maintained for edges
ll fill_sum(int node){
	vec::iterator it;
	ll wsum=0;
	for( it = rel[node].begin() ; it != rel[node].end() ; it++ ){
		
		sum[ *it ] = fill_sum( child[ *it ] );
		wsum += sum[ *it ];
		wsum += w[ *it ];
		
	}
	sum_node[node] = wsum ;
	return wsum;
}

void printt(ll arr[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

ll carry_dfs(int node,ll carry){
	if(flag==-1){
		return 0;
	}
	ll needed,kk,subtract;

	vec::iterator it;

	// needed = max( needed , p[])

	needed = carry;

	kk=0;  //for the new sum of weights in the subtree

	for( it = rel[node].begin() ; it != rel[node].end() ; it++ ){
		
		if( sum[ *it ] - p[ *it ] > 0 ){
			needed = max( needed , sum[ *it ]-p[ *it ] );
		}
		
		needed = carry_dfs( child[ *it ] , needed );

		if( sum_node[ child[ *it ] ] - p[ *it ] > 0 ){
			flag=-1;
			return 0;
		}
		else{
			subtract=min(needed,( p[*it] - sum_node[ child[*it] ] ));
			subtract=min( subtract , w[*it]-1 );
			p[*it]-=subtract;
			w[*it]-=subtract;
			needed-=subtract;
			// sum_node[node]-=subtract;
		}
		
		sum[ *it ] = sum_node[ child[ *it ] ];
		kk += w[*it];
		kk += sum_node[ child[ *it ] ];
	
	}

	sum_node[node] = kk; 

	return needed ;

}

int main(){

	int i,x,y;
	ll ww,pp,total_init,carry;

	cin>>n;

	rel.resize(n+2);

	for( i=0 ; i < n-1 ; i++ ){
		
		cin>>x>>y>>ww>>pp;
		
		p[i] = pp ;
		w[i] = ww ;
		parent[i] = x ;
		child[i] = y ;
		
		rel[ x ].push_back( i );

	}

	sum_node[1] = fill_sum(1);

	// printt(sum,n-1);
	// printt(sum_node,n+1);

	for( i=0 ; i < n-1 ; i++ ){
		vis[i] = 0 ;
	}

	flag=1;

	carry = carry_dfs( 1 , 0 );

	if(flag==-1){
		cout<<"-1\n";
		return 0;
	}
	cout<<n<<"\n";
	for( i=0 ; i < n-1 ; i++ ){
		cout<<parent[i]<<" "<<child[i]<<" "<<w[i]<<" "<< p[i]<<"\n";
	}

	return 0;
}