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
#define limitM 100001

int parent[num];

int findRoot(int x){
	if(parent[x]!=x)	parent[x]=findRoot(parent[x]);
	return parent[x];
}

int main(){

	int a, b, u, v, cnt;

	fori(0, limitM)	parent[i]=i;
	cnt=0;
	while(cin>>a){
		if(a==-1){
			cout<<cnt<<"\n";
			fori(0, limitM)	parent[i]=i;
			cnt=0;
			continue;
		}
		cin>>b;
		u=findRoot(a);
		v=findRoot(b);
		if(u==v)	cnt++;
		else{
			parent[u]=v;
		}
	}

	return 0;
}