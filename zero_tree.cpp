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
typedef pair<ll, ll> pll;

#define pb push_back
#define mp make_pair
#define fori(a, b) for(int i=a ; i<b ; i++ )
#define forn(i, a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fornn(i, a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define INF 1000000007
#define num 100005

ll val[num];
vector<vi>rel;
bool vis[num];
int n;

// first - negative moves second - positive moves
pll calc(int vtx){
	vis[vtx]=true;
	pll moves, tmp;
	ll v;
	moves=mp(0, 0);
	fori(0, rel[vtx].size()){
		if(vis[rel[vtx][i]]==true)	continue;
		tmp=calc(rel[vtx][i]);
		moves.fi=max(moves.fi, tmp.fi);
		moves.se=max(moves.se, tmp.se);
	}
	v=val[vtx]-moves.fi+moves.se;
	if(v<0)	moves.se+=(0-v);
	else	moves.fi+=v;
	return moves;
}

int main(){
	int a, b;
	pll ans;

	cin>>n;
	rel.resize(n+2);

	fori(0, n-1){
		cin>>a>>b;
		rel[a].pb(b);
		rel[b].pb(a);
	}
	fori(1, n+1)	cin>>val[i];

	fori(1, n+1)	vis[i]=false;
	ans=calc(1);

	cout<<(ans.fi+ans.se)<<"\n";

	return 0;
}