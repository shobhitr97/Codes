#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define num 100005
#define pb push_back

typedef long long int ll;
typedef vector<int> vec;
typedef vector< vector<int> > vvec;

int sumc[num], total_sum, par[num];
int c[num], n, visited, ans;
vvec rel;
bool vis[num];

int dfs( int v ){

	vis[v] = 1;

	// cout<<v<<"\n";

	int temp, nm = 0;
	int color = 0;
	bool flag = 1;

	vec::iterator it;
	for( it = rel[v].begin() ; it != rel[v].end() ; it++ ){
		
		temp = visited;

		if( vis[ (*it) ]){
			continue;
		}
		par[(*it)] = v;
		sumc[ (*it) ] = dfs( *it );
		
		nm += (visited - temp);
		// cout<<visited-temp<<"\n";
		temp = visited - temp -1;
		// cout<<sumc[ (*it) ]<<" ";
		color += (c[ (*it) ] + sumc[ (*it) ]);

		if( (temp*c[ (*it) ]) != sumc[ (*it) ] ){
			// cout<<"->"<<temp<<" "<<c[(*it)]<<" "<<sumc[(*it)]<<"\n";
			flag = 0;
		}

	}
	// cout<<"flag:"<<flag<<"\n";
	if( flag ){
		if( v != par[v] ){
			if( (total_sum - (c[v] + color))%(n-nm-1) != 0 || (total_sum - (c[v] + color))/(n-nm-1) != c[par[v]] ){
				flag = 0;
			}
		}
	}
	if(flag){
		ans = v;
		// cout<<"->"<<ans<<"\n";
	}

	visited++;
	// cout<<v<<":"<<par[v]<<" "<<nm<<" "<<color<<"\n";
	return color;

}

int main(){
	
	int i, u, v;

	cin>>n;

	rel.resize(n+2);

	for( i=1 ; i<n ; i++ ){
		cin>>u>>v;
		rel[u].pb(v);
		rel[v].pb(u);
	}

	total_sum = 0;
	for( i=1 ; i<=n ; i++ ){
		cin>>c[i];
		total_sum += c[i];

		vis[i] = 0;

	}

	visited = 0;
	ans = -1;
	par[1] = 1;
	int cc = dfs(1);
	if( ans != -1	){
		cout<<"YES\n";
		cout<<ans<<"\n";
	}
	else{
		cout<<"NO\n";
	}

	return 0;
}