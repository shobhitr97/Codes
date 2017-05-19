#include<set>
#include<utility>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<functional>

using namespace std;

#define num 1005
#define INF 1000000000005


typedef long long int ll;
typedef vector <ll> vecl;
typedef vector < vector <ll> > vvecl;
typedef vector<int> vec;
typedef vector < vector<int> > vvec;
typedef vector <pair<int,int> > vecp;

ll adj[num][num], L;
int n, m, s, t, counter, p;
vvec rel;
vecp erased, edge;

ll val[num];
int vis[num], par[num];
bool erase[num][num];

class Compare{
	public:
		bool operator()(int a,int b){
			if(val[a] > val[b]){
				return true;
			}
			return false;
		}
};
typedef priority_queue<int, vec, Compare > pq;
pq lis;

int main(){

	cin >> n >> m >> L >> s >> t;
	
	vecp::iterator it;
	vec::iterator itt;
	ll l, r, mid;
	int parent = s, vertex;
	int i, u, v, j;
	ll w;


	for( i=0 ; i<n ; i++ ){
		for( j=0 ; j<n ; j++ ){
			adj[i][j] = -1;
			erase[i][j] = -1;
		}
		// vis[i] = -1;
		// par[i] = -1;
		// val[i] = 0;
	}

	rel.resize( n+2 );
	counter = 0;
	for( i=0 ; i<m ; i++ ){
		cin>> u >> v >> w;
		
		adj[u][v] = w;
		adj[v][u] = w;
		
		rel[u].push_back(v);
		rel[v].push_back(u);
		
		edge.push_back(make_pair(u,v));
		
		if( w == 0 ){
			erased.push_back( make_pair(u,v) );
			counter++;
			erase[i][j] = erase[j][i] = 1;
		}

	}

	//for checking if path exists
	// Check#1
	
	for( i=0 ; i<n ; i++ ){
		vis[i] = -1;
		val[i] = 0;
	}

	// for( it = erased.begin() ; it != erased.end() ; it++ ){
	// 	u = (*it).first;
	// 	v = (*it).second;

	// 	adj[u][v] = 1;
	// 	adj[v][u] = 1;

	// }



	adj[s][s] = 0;
	// val[s] = 0;
	// par[s] = s;
	lis.push(s);

	while( !lis.empty() ){
		
		vertex = lis.top();
		lis.pop();
		// cout<<vertex <<" "<< val[vertex]<<"\n";
		
		if( vis[vertex] != -1 ){
			continue;
		}
		vis[vertex] = 1;
		for( itt= rel[vertex].begin() ; itt!= rel[vertex].end() ; itt++ ){
			if( vis[ *itt ] != -1 || adj[vertex][*itt] == 0 ){
				continue;
			}
			if( val[ *itt ] == 0 ){
				// par[ *itt ] = vertex;
				val[ *itt ] = adj[vertex][*itt] + val[vertex];
				lis.push( *itt );
			}
			else{
				if( adj[*itt][vertex] + val[vertex] < val[ *itt ] ){
					val[ *itt ] = adj[*itt][vertex] + val[vertex];
					// par[ *itt ] = vertex;
					lis.push( *itt );
				}
			}
		}

	}

	if( val[t] && val[t] < L ){
		cout<<"NO\n";
		return 0;
	}

	// Check#2
	for( i=0 ; i<n ; i++ ){
		vis[i] = -1;
		val[i] = 0;
	}

	for( it = erased.begin() ; it != erased.end() ; it++ ){
		u = (*it).first;
		v = (*it).second;

		adj[u][v] = 1;
		adj[v][u] = 1;

	}



	adj[s][s] = 0;
	// val[s] = 0;
	// par[s] = s;
	lis.push(s);

	while( !lis.empty() ){
		
		vertex = lis.top();
		lis.pop();
		// cout<<vertex <<" "<< val[vertex]<<"\n";
		
		if( vis[vertex] != -1 ){
			continue;
		}
		vis[vertex] = 1;
		for( itt= rel[vertex].begin() ; itt!= rel[vertex].end() ; itt++ ){
			if( vis[ *itt ] != -1 ){
				continue;
			}
			if( val[ *itt ] == 0 ){
				// par[ *itt ] = vertex;
				val[ *itt ] = adj[vertex][*itt] + val[vertex];
				lis.push( *itt );
			}
			else{
				if( adj[*itt][vertex] + val[vertex] < val[ *itt ] ){
					val[ *itt ] = adj[*itt][vertex] + val[vertex];
					// par[ *itt ] = vertex;
					lis.push( *itt );
				}
			}
		}

	}

	if( val[t] > L || val[t] == 0 ){
		cout<<"NO\n";
		return 0;
	}

	if( val[t] == L ){
		
		cout<<"YES\n";
		for( it = edge.begin() ; it != edge.end() ; it++ ){
			u = (*it).first;
			v = (*it).second;
			cout<< u <<" "<< v <<" "<< adj[u][v]<<"\n";
		}
		return 0;		
	}

	//Given we have eliminated all the impossible conditions

	// p = counter ;

	l = -1;
	r = counter;

	while( l <= r ){
		
		mid = (l+r)/2;

		for( i=0 ; i<n ; i++ ){
			vis[i] = -1;
			val[i] = 0;
		}

		i=0;
		for( it = erased.begin() ; it != erased.end() ; it++ ){
			u = (*it).first;
			v = (*it).second;
			if( i <= mid ){
				adj[u][v] = 1;
				adj[v][u] = 1;
			}
			if( i > mid ){
				adj[u][v] = INF;
				adj[v][u] = INF;
			}

		}



		adj[s][s] = 0;
		// val[s] = 0;
		// par[s] = s;
		lis.push(s);

		while( !lis.empty() ){
			
			vertex = lis.top();
			lis.pop();
			// cout<<vertex <<" "<< val[vertex]<<"\n";
			
			if( vis[vertex] != -1 ){
				continue;
			}
			vis[vertex] = 1;
			for( itt= rel[vertex].begin() ; itt!= rel[vertex].end() ; itt++ ){
				if( vis[ *itt ] != -1 ){
					continue;
				}
				if( val[ *itt ] == 0 ){
					// par[ *itt ] = vertex;
					val[ *itt ] = adj[vertex][*itt] + val[vertex];
					lis.push( *itt );
				}
				else{
					if( adj[*itt][vertex] + val[vertex] < val[ *itt ] ){
						val[ *itt ] = adj[*itt][vertex] + val[vertex];
						// par[ *itt ] = vertex;
						lis.push( *itt );
					}
				}
			}

		}
		
		// cout<< l <<" "<< r <<" "<< mid <<"\n";
		// cout<< val[t]<<"\n";

		if( val[ t ] <= L ){
			p = mid;
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	if( p == -1 ){
		
		cout<<"YES\n";

		i=0;
		for( it = erased.begin() ; it != erased.end() ; it++ ){
			u = (*it).first;
			v = (*it).second;
	
			if( i > -1 ){
				adj[u][v] = INF;
				adj[v][u] = INF;
			}

		}

		for( it = edge.begin() ; it != edge.end() ; it++ ){
			u = (*it).first;
			v = (*it).second;
			cout<< u <<" "<< v <<" "<< adj[u][v]<<"\n";
		}
		return 0;		
	}
	// p can not be  counter because counter will result in a NO 

	l = 1;
	r = L;

	while( val[t] != L && l <= r ){
		
		mid = (l+r)/2;

		for( i=0 ; i<n ; i++ ){
			vis[i] = -1;
			val[i] = 0;
		}

		u = erased[p].first;
		v = erased[p].second;

		adj[u][v] = mid;
		adj[v][u] = mid;




		adj[s][s] = 0;
		// val[s] = 0;
		// par[s] = s;
		lis.push(s);

		while( !lis.empty() ){
			
			vertex = lis.top();
			lis.pop();
			// cout<<vertex <<" "<< val[vertex]<<"\n";
			
			if( vis[vertex] != -1 ){
				continue;
			}
			
			vis[vertex] = 1;

			for( itt= rel[vertex].begin() ; itt!= rel[vertex].end() ; itt++ ){
				if( vis[ *itt ] != -1 ){
					continue;
				}
				if( val[ *itt ] == 0 ){
					// par[ *itt ] = vertex;
					val[ *itt ] = adj[vertex][*itt] + val[vertex];
					lis.push( *itt );
				}
				else{
					if( adj[*itt][vertex] + val[vertex] < val[ *itt ] ){
						val[ *itt ] = adj[*itt][vertex] + val[vertex];
						// par[ *itt ] = vertex;
						lis.push( *itt );
					}
				}
			}

		}
		
		// cout<< l <<" "<< r <<" "<< mid <<"\n";
		// cout<< val[t]<<"\n";

		if( val[ t ] < L ){
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}
	// ll rem;
	// rem = L - val[t];
	// vertex = t;
	// int flag = 1;
	// while( par[vertex] != vertex ){            //only s satisfies this condition
	// 	if( erase[ par[vertex] ][vertex] == 1 ){
	// 		if( flag == 1 ){
	// 			adj[vertex][ par[vertex] ] = adj[ par[vertex] ][vertex] = rem+1;
	// 			flag = 0;
	// 		}
	// 		erase[vertex][ par[vertex] ] = erase[ par[vertex] ][vertex] = -1;
	// 	}
	// }

	// for( it = erased.begin() ; it != erased.end() ; it++ ){
	// 	u = (*it).first;
	// 	v = (*it).second;
	// 	if( erase[u][v] == 1 ){
	// 		adj[u][v] = adj[v][u] = L+1;
	// 	}
	// }

	cout<<"YES\n";
	for( it = edge.begin() ; it != edge.end() ; it++ ){
		u = (*it).first;
		v = (*it).second;
		cout<< u <<" "<< v <<" "<< adj[u][v]<<"\n";
	}

	return 0;
}