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
#include<stdlib.h>
#include<tr1/functional>
#include<string>

using namespace std;
using namespace std::tr1;

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
#define num 100005

bool vis[num];
int n1, n2;
vector<vi> adj1, adj2;
vector<ll> has1, has2, vec1;

void dfs2(int v){
	vis[v]=true;
	hash<string> hash_fn;
	has1[v]=stoll(hash_fn(to_string(has1[v])));

	int siz=adj1[v].size();

	if(siz==0)	vec1.pb(has1[v]);
	forn(i, 0, siz){
		has1[adj1[v][i]]+=has1[v];
	}

}

ll dfsHash1(int v){
	vis[v]=true;
	int siz=adj1[v].size();
	ll has=0;

	forn(i, 0, siz){
		has+=dfsHash1(adj1[v][i]);
	}

	hash<string> hash_fn;
	string str;
	str = hash_fn(to_string(has));
	has = std::stoll(str);
	has1[v]=has;

	return has;
}

ll dfsHash2(int v){
	vis[v]=true;
	int siz=adj2[v].size();
	ll has=0;

	forn(i, 0, siz){
		has+=dfsHash2(adj2[v][i]);
	}

	hash<string> hash_fn;
	string str;
	str = hash_fn(to_string(has));
	has = std::stoll(str);
	has2[v]=has;

	return has;
}

int main(){
	int t, x;
	ll cnt1, cnt2;
	cin>>t;

	while(t--){
		cin>>n1>>n2;

		adj1.resize(n1+5);
		has1.resize(n1+5);
		adj2.resize(n2+5);
		has2.resize(n2+5);

		forn(i, 2, n1+1){
			cin>>x;
			adj1[x].pb(i);
		}

		forn(i, 2, n2+1){
			cin>>x;
			adj2[x].pb(i);
		}

		fori(1, n1+1)	vis[i]=false;
		ll temp = dfsHash1(1);

		fori(1, n2+1)	vis[i]=false;
		temp = dfsHash2(1);

		forn(i, 1, n1+1)	vis[i]=false;
		dfs2(1);

		sort(vec1.begin(), vec1.end());
		sort(has2.begin(), has2.end());

		cnt1=1, cnt2=1;
		int siz=vec1.size();
		fori(1, siz){
			if(vec1[i]>vec1[i-1])	cnt1++;
		}

		siz=has2.size();
		forn(i, 1, siz){
			if(has2[i]>has2[i-1])	cnt2++;
		}

		cout<<cnt1*cnt2<<"\n";

		adj1.clear();
		adj2.clear();
		has1.clear();
		has2.clear();

	}

	return 0;
}