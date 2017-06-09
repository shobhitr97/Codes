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
#define num 504

int parent[num];

int findParent(int x){
	if(parent[x]!=x)	parent[x]=findParent(parent[x]);
	return parent[x];
}

int extractDigit(int number, int digit){
	switch(digit){
		case 4:	return number%10;
		case 3:	return (number/10)%10;
		case 2:	return (number/100)%10;
		case 1:	return (number)/1000;
	}
}

int main(){

	int t, n, m, u, v, ans, w, cntEdges, diff, x, minStartEdge;
	ll cost;
	vi numbers;
	viii edges;

	cin>>t;
	while(t--){
		cin>>n;
		numbers.pb(0);
		fori(0, n){
			cin>>x;
			numbers.pb(x);
		}
		n++;
		cntEdges=0;
		minStartEdge=100;
		forn(i, 0, n){
			forn(j, i+1, n){
				w=0;
				forn(k, 1, 5){
					u=extractDigit(numbers[i], k);
					v=extractDigit(numbers[j], k);
					diff=((u<v)?(v-u):(u-v));
					// cout<<diff<<" ";
					w+=min(diff, 10-diff);
				}
				// cout<<"\n";
				// cout<<i<<","<<j<<" - "<<w<<"\n";
				if(i==0)	minStartEdge=min(minStartEdge, w);
				else{
					edges.pb(mp(w, mp(i, j)));
					cntEdges++;
				}
			}
		}
		fori(0, n)	parent[i]=i;
		sort(edges.begin(), edges.end());
		cost=0;
		// cout<<"MST:\n";
		fori(0, cntEdges){
			u=findParent(edges[i].se.fi);
			v=findParent(edges[i].se.se);
			w=edges[i].fi;
			if(u!=v){
				cost+=w;
				// cout<<edges[i].se.fi<<","<<edges[i].se.se<<" - "<<w<<"\n";
				parent[u]=v;
			}
		}
		cout<<cost+minStartEdge<<"\n";
		edges.clear();
		numbers.clear();
	}

	return 0;
}