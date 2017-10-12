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

#define pb push_back
#define mp make_pair
#define fori(a, b) for(int i=a ; i<b ; i++ )
#define forn(i, a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define INF 1000000007
#define num 100005

int n, m, d, p[num], dist_down[num], par[num], dist_up[num];
bool mark[num], vis[num];
ii maxm[num];
vector<vi>rel;

int dfs_down(int vertex){
	vis[vertex]=true;
	int temp, maxm1=-1, maxm2=-1;
	if(mark[vertex]==true)	maxm1=0;
	for(vi::iterator it=rel[vertex].begin();it!=rel[vertex].end();it++){
		temp=-1;
		if(vis[(*it)]==false){
			temp=dfs_down((*it));
			par[(*it)]=vertex;
		}			
		if(temp>maxm1){
			maxm2=maxm1;
			maxm1=temp;
		}
		else	maxm2=max(temp, maxm2);
	}
	maxm[vertex]=mp(maxm1, maxm2);
	dist_down[vertex]=maxm1;
	if(maxm1==-1)	return -1;
	return maxm1+1;
}

int main(){
	int u, v, cnt;
	cin>>n>>m>>d;
	rel.resize(n+2);
	fori(0, n+1)	mark[i]=false, vis[i]=false;
	fori(0, m){
		cin>>p[i];
		mark[p[i] ]=true;
	}

	fori(1, n){
		cin>>u>>v;
		rel[u].pb(v);
		rel[v].pb(u);
	}

	par[1]=1;
	int temp=dfs_down(1);

	// cout<<"Dist_down:\n";
	// fori(1, n+1)	cout<<dist_down[i]<<" ";
	// cout<<"\n";

	fori(0, n+1)	vis[i]=false;
	queue<int>bfs_up;
	vis[1]=true;
	dist_up[1]=-1;
	for(vi::iterator it=rel[1].begin();it!=rel[1].end();it++)	bfs_up.push((*it));
	while(!bfs_up.empty()){
		int ind=bfs_up.front();
		bfs_up.pop();
		vis[ind]=true;
		temp=-1;
		ii t=maxm[par[ind] ];
		if(t.fi==-1)	temp=-1;
		else{
			if(dist_down[ind]!=-1&&dist_down[ind]+1==t.fi){
				if(t.se==-1)	temp=-1;
				else	temp=t.se+1;
			}
			else	temp=t.fi+1;
		}
		if(dist_up[par[ind] ]!=-1)	temp=max(temp, dist_up[par[ind] ]+1);
		dist_up[ind]=temp;
		for(vi::iterator it=rel[ind].begin();it!=rel[ind].end();it++)	if(vis[(*it)]==false)	bfs_up.push((*it));
	}

	// cout<<"Dist_up:\n";
	// fori(1, n+1)	cout<<dist_up[i]<<" ";
	// cout<<"\n";

	cnt=0;
	fori(1, n+1)	if(dist_up[i]<=d&&dist_down[i]<=d)	cnt++;
	cout<<cnt<<"\n";
	return 0;
}