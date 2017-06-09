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

viii edges;
int parent[100005], n, r;

int findRoot(int x){
	if(parent[x]!=x)	parent[x] = findRoot(parent[x]);
	return parent[x];
}

int main(){

	int t, u, v, w, x;
	char ch;
	ch='A';

	cin>>t;
	forn(z, 0, t){
		cin>>n;
		fori(0, n){
			forn(j, 0, n-1){
				scanf("%d, ", &x);
				if(i==j)	continue;
				if(x)	edges.pb(mp(x, mp(i, j)));
			}
			cin>>x;
			if(i!=n-1 && x!=0)	edges.pb(mp(x, mp(i, n-1)));
		}
		fori(0, n)	parent[i]=i;
		sort(edges.begin(), edges.end());
		cout<<"Case "<<(z+1)<<":\n";
		for(viii::iterator it=edges.begin();it!=edges.end();it++){
			u=findRoot((*it).se.fi);
			v=findRoot((*it).se.se);
			w=(*it).fi;
			if(u!=v){
				cout<<(char)(ch+(*it).se.fi)<<"-"<<(char)(ch+(*it).se.se)<<" "<<w<<"\n";
				parent[u]=v;
			}
		}
		edges.clear();
	}


	return 0;
}