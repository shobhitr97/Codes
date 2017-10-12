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
#define num 300005

int visited[num], n, m, parent[num], siz[num], cntComp;
ll maxm, dia[num];
vector<vi> adjList;

ll max(ll a, ll b){
	if(a>b)	return a;
	return b;
}

ll dfs(int vertex, int par){
	visited[vertex]=1;
	parent[vertex]=par;
	cntComp++;
	vi::iterator it;
	ll max1, max2, temp;
	int cnt=0;
	max1=0;
	max2=0;
	for(it=adjList[vertex].begin();it!=adjList[vertex].end();it++){
		if(visited[(*it)])	continue;
		cnt++;
		temp=(dfs((*it), vertex)+1);
		if(temp>max1){
			max2=max1;
			max1=temp;
		}
		else{
			if(temp>max2)	max2=temp;	
		}
	}
	if(cnt>1)	maxm=max(maxm, max1+max2);
	maxm=max(max1, maxm);
	return max1;
}

int findParent(int x){
	if(parent[x]!=x)	parent[x]=findParent(parent[x]);
	return parent[x];
}

int main(){
	int u, v, q, action;
	cin>>n>>m>>q;
	adjList.resize(n+3);
	fori(0, m){
		cin>>u>>v;
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	fori(0, n)	visited[i]=0;
	fori(0, n)	dia[i]=0;
	fori(0, n)	siz[i]=1;
	fori(0, n){
		if(visited[i])	continue;
		maxm=0;
		cntComp=0;
		ll temp=dfs(i, i);
		dia[i]=max(maxm, temp);
		siz[i]=cntComp;
	}
	fori(0, q){
		cin>>action;
		if(action==1){
			cin>>v;
			u=findParent(v);
			cout<<dia[u]<<"\n";
			continue;
		}
		cin>>u>>v;
		u=findParent(u);
		v=findParent(v);
		if(u==v)	continue;
		ll temp, len;
		temp=max(dia[u], dia[v]);
		len=dia[u]/2+dia[v]/2+1;
		if(dia[u]&1)	len++;
		if(dia[v]&1)	len++;
		temp=max(temp, len);
		if(siz[u]<siz[v]){
			siz[v]+=siz[u];
			dia[v]=temp;
			parent[u]=v;
		}
		else{
			siz[u]+=siz[v];
			dia[u]=temp;
			parent[v]=u;
		}
	}
	// fori(0, n){
	// 	if(parent[i]==i)	cout<<i<<" - "<<dia[i]<<"\n";
	// }
	return 0;
}