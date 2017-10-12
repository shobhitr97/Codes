#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>

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
#define num 20005
// Find out outEdges and inEdges for every connected component
// for every component there is going to be one inEdge and 1 outEdge to connect to the whole graph
int visited[num], parent[num], inDegree[num], outDegree[num], siz[num], inEdges[num], outEdges[num];
vector<vi> adjList;
vii edges;

int findParent(int x){
	if(parent[x]!=x)	parent[x]=findParent(parent[x]);
	return parent[x];
}

void dfs(int vrtx){
	visited[vrtx]=1;
	int u, v;
	u=findParent(vrtx);
	vi::iterator it;
	for(it=adjList[vrtx].begin();it!=adjList[vrtx].end();it++){
		v=findParent((*it));
		if(u!=v){
			if(siz[u]<siz[v]){
				parent[u]=v;
				siz[v]+=siz[u];
				siz[u]=0;
			}
			else{
				parent[v]=u;
				siz[u]+=siz[v];
				siz[v]=0;
			}
		}
		inDegree[(*it)]++;
		outDegree[vrtx]++;
		if(visited[(*it)])	continue;
		dfs((*it));
	}
}

int main(){
	int t, n, m, s1, s2, u, cnt;
	cin>>t;
	while(t--){
		cin>>n>>m;
		fori(1, n+1)	parent[i]=i, siz[i]=1, inDegree[i]=0, outDegree[i]=0, visited[i]=0, inEdges[i]=0, outEdges[i]=0;
		adjList.resize(n+2);
		fori(0, m){
			cin>>s1>>s2;
			adjList[s1].pb(s2);
		}
		fori(1, n+1){
			if(visited[i])	continue;
			dfs(i);
		}
		fori(1, n+1){
			u=findParent(i);
			if(inDegree[i]==0)	inEdges[u]++;
			if(outDegree[i]==0)	outEdges[u]++;
		}
		cnt=0;
		fori(1, n+1){
			if(parent[i]==i){
				cnt+=max(inEdges[i], outEdges[i]);
				if(max(inEdges[i], outEdges[i])==0)	cnt++;
			}
		}
		cout<<cnt<<"\n";
		adjList.clear();
	}
	return 0;
}