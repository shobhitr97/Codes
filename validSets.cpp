#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef vector<int>::iterator itt;

#define pb push_back
#define mp make_pair
#define fori(a, b) for(int i=a ; i<b ; i++ )
#define forn(i, a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fornn(i, a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define INF 1000000007
#define num 2005

vector<vi> rel;
vector<bool> vis, GlobVis;
int n, d, val[num];

ll dfs(int index, int root, bool flag){
	vis[index] = true;

	// cout<<"\t"<<index<<" "<<flag<<"\n";

	int siz = rel[index].size();
	ll ans=1,temp;
	fori(0, siz){
		if(vis[ rel[index][i] ] == true) continue;

		// cout<<"\t \t 1 "<<rel[index][i]<<"\n";

		if(/*flag == true && */val[ rel[index][i] ] == val[root] && GlobVis[ rel[index][i] ] == true)	continue;

		// cout<<"\t \t 2 "<<rel[index][i]<<"\n";

		if(val[ rel[index][i] ] >= val[root] && val[ rel[index][i] ] <= val[root] + d){
			temp = dfs(rel[index][i], root, ( flag == false ? false : (val[ rel[index][i] ] == val[root] ) ) );
			// if(index == root)	cout<<"\t"<<rel[index][i]<<" "<<temp<<"\n";
			ans = ( ans * ( temp + 1 )%INF )%INF;
		}
	}
	return ans;
}

int main(){

	int u, v;
	ll ans=0;

	cin>>d>>n;

	rel.resize(n);
	vis.resize(n);
	GlobVis.resize(n);

	fori(0, n)	cin>>val[i];

	fori(0, n-1){
		cin>>u>>v;
		rel[u-1].pb(v-1);
		rel[v-1].pb(u-1);
	}

	fori(0, n)	GlobVis[i]=false;

	fori(0, n){
		forn(j, 0, n)	vis[j] = false;
		// cout<<i<<"->\n";
		ll temp = dfs(i, i, true);
		// cout<<"\n\t"<<temp<<"\n";
		ans = ( ans + temp )%INF; 
		GlobVis[i]=true;
	}

	cout<<ans<<"\n";

	return 0;
}