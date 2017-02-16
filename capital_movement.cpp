#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>

using namespace std;

typedef long long int ll;
typedef vector< vector<int> > vv;
typedef vector<int> vec;

#define num 50004

int n,mark[num],val[num];

ll p[num];

bool vis[num];

vv rel;

vec sop;

bool myfunction(int i,int j){
	return ( p[i] < p[j] );
}

// void dfs(int i,int par){
// 	vis[i]=1;
// 	parent[i] = par;
// 	vec::iterator it;
// 	for( it = rel[i].begin() ; it != rel[i].end() ; it++ ){
// 		if( vis[ *it ] ){
// 			continue;
// 		}
// 		dfs( *it , par ) ;
// 	}
// }



int main(){
	int t,i,u,v,j;
	
	cin>>t;
	
	while(t--){
	
		sop.clear();
		rel.clear();

		cin>>n;
	
		rel.resize(n+2);
	
		for( i=1 ; i<=n ; i++ ){
			cin>>p[i];
		}

		for( i=1 ; i<=n-1 ; i++ ){
			cin>>u>>v;
			
			rel[u].push_back(v);
			rel[v].push_back(u);
		
		}

		for( i=1 ; i<=n ; i++ ){
			vis[i]=0;
			mark[i]=0;
			sop.push_back(i);
		}

		sort( sop.begin() , sop.end() , myfunction );
		
		// for( i=0 ; i<n ; i++ ){
		// 	cout<<sop[i]<<" ";
		// }
		// cout<<"\n";
			
		vec::iterator it;

		for( i=1 ; i<=n ; i++ ){

			mark[i]=1;
			for( it = rel[i].begin() ; it != rel[i].end() ; it++ ){
				mark[ *it ]=1;
			}
					
			j=n-1;
			while( mark[ sop[ j ] ] ){
				j--;
			}

			mark[i]=0;
			for( it = rel[i].begin() ; it != rel[i].end() ; it++ ){
				mark[ *it ]=0;
			}			

			val[ i ] = sop[ j ];

		}
		for( i=1 ; i<=n ; i++ ){
			cout<<val[ i ]<<" ";
		}
		cout<<"\n";

	}
	return 0;
}
