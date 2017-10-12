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
#define num 100005

int parent[num];

int findParent(int x){
	if(parent[x]!=x)	parent[x]=findParent(parent[x]);
	return parent[x];
}

int main(){

	int t, p, r, u, v, ans;
	cin>>t;
	while(t--){
		cin>>p>>r;
		fori(1, p+1)	parent[i]=i;
		ans=0;
		while(r--){
			cin>>u>>v;
			u=findParent(u);
			v=findParent(v);
			if(u==v)	ans++;
			else	parent[u]=v;
		}
		cout<<ans<<"\n";
	}

	return 0;
}