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
#define fornn(i, a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define INF 1000000007
#define num 200005

int f[num][20], lvl[num], n, q;
int logp[num];
vector<vi> rel;
bool vis[num];

int dfs(int vtx, int parent){
	vis[vtx]=true;
	f[vtx][0]=parent;
	lvl[vtx]=lvl[parent]+1;
	fori(0, rel[vtx].size()){
		if(vis[rel[vtx][i]]==true)	continue;
		dfs(rel[vtx][i], vtx);
	}
}

void fill(int limit){
	int cur=1, prev=1, val=0;
	logp[0]=0;
	while(cur<=limit){
		if(cur==prev*2){
			val++;
			prev=cur;
		}
		logp[cur]=val;
		cur++;
	}
}

int lca(int a, int b){
	int tmp, k;
	if(lvl[a]>lvl[b]){
		tmp=a;
		a=b;
		b=tmp;
	}

	k=logp[lvl[b]];
	while(lvl[b]>lvl[a]&&k>=0){
		if(lvl[f[b][k]]>=lvl[a])	b=f[b][k];
		k--;	
	}

	if(a==b)	return a;
	k=logp[lvl[a]];
	while(k>=0){
		if(f[a][k]!=f[b][k])	a=f[a][k], b=f[b][k];
		k--;
	}
	return f[a][0];
}

int main(){
	int x, maxLvl, a, b, c, r, s, t, ans, tmp, val;
	vi output;

	cin>>n>>q;

	rel.resize(n+2);
	fill(n);

	fori(1, n){
		cin>>x;
		rel[i].pb(x-1);
		rel[x-1].pb(i);
	}

	fori(0, n)	vis[i]=false;
	lvl[0]=0, f[0][0]=0;
	dfs(0, 0);

	maxLvl=(-1)*INF;
	fori(0, n)	maxLvl=max(maxLvl, lvl[i]);

	forn(j, 1, logp[maxLvl]+1){
		forin(n-1, 0)	f[i][j]=f[f[i][j-1]][j-1];
	}

	fori(0, q){
		ans=(-1)*INF;
		cin>>a>>b>>c;
		a--, b--, c--;
		r=lca(a, b);
		s=lca(b, c);
		t=lca(c, a);
		// a and b as s&t
		tmp=lca(r, c);
		if(tmp==c)	val=lvl[r]-lvl[c]+1;
		else{
			if(tmp==r){
				if(s==r){
					if(t==r)	val=lvl[c]-lvl[r]+1;
					else	val=abs(lvl[c]-lvl[t])+1;
				}
				else	val=abs(lvl[c]-lvl[s])+1;
			}
			else	val=lvl[r]-lvl[tmp]+lvl[c]-lvl[tmp]+1;
		}
		ans=max(ans, val);

		// b and c as s&t
		tmp=lca(s, a);
		if(tmp==a)	val=lvl[s]-lvl[a]+1;
		else{
			if(tmp==s){
				if(t==s){
					if(r==s)	val=lvl[a]-lvl[s]+1;
					else	val=abs(lvl[a]-lvl[r])+1;
				}
				else	val=abs(lvl[a]-lvl[t])+1;
			}
			else	val=lvl[s]-lvl[tmp]+lvl[a]-lvl[tmp]+1;
		}
		ans=max(ans, val);

		// c and a as s&t
		tmp=lca(t, b);
		if(tmp==b)	val=lvl[t]-lvl[b]+1;
		else{
			if(tmp==t){
				if(s==t){
					if(r==t)	val=lvl[b]-lvl[t]+1;
					else	val=abs(lvl[b]-lvl[r])+1;
				}
				else	val=abs(lvl[b]-lvl[s])+1;
			}
			else	val=lvl[t]-lvl[tmp]+lvl[b]-lvl[tmp]+1;
		}
		ans=max(ans, val);
		output.pb(ans);
	}
	fori(0, q)	cout<<output[i]<<"\n";
	return 0;
}