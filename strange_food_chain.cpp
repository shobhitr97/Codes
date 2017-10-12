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
#define num 50005

int parent[num], val[num], n, siz[num], status, cnt;
vi output;

int findParent(int x){
	if(parent[x]!=x){
		parent[x]=findParent(parent[x]);
		status=(status+val[x])%3;
		val[x]=status;
	}
	return parent[x];
}

void setSame(int x, int y){
	int u, v, s1, s2;
	status=0;
	u=findParent(x);
	s1=status;
	status=0;
	v=findParent(y);
	s2=status;

	if(u==v){
		if(s1!=s2)	cnt++;
		return;
	}
	if(siz[u]<siz[v]){
		siz[v]+=siz[u];
		parent[u]=v;
		val[u]=(3+s2-s1)%3;
	}
	else{
		siz[u]+=siz[v];
		parent[v]=u;
		val[v]=(3+s1-s2)%3;
	}
}

void setPredator(int x, int y){
	int u, v, s1, s2;
	status=0;
	u=findParent(x);
	s1=status;
	status=0;
	v=findParent(y);
	s2=status;

	if(u==v){
		if((s1+1)%3!=s2)	cnt++;
		return;
	}
	if(siz[u]<siz[v]){
		siz[v]+=siz[u];
		parent[u]=v;
		val[u]=(3+s2-(s1+1)%3)%3;
	}
	else{
		siz[u]+=siz[v];
		parent[v]=u;
		val[v]=(3+(s1+1)%3-s2)%3;
	}
}

int main(){
	int c, x, y, t, k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		fori(1, n+1)	parent[i]=i, val[i]=0, siz[i]=1;
		cnt=0;
		fori(1, k+1){
			cin>>c>>x>>y;
			int temp=cnt;
			if(x>n||y>n)	cnt++;
			else{
				switch(c){
					case 1:	setSame(x, y);
							break;
					case 2:	setPredator(x, y);
							break;
				}
			}
			// if(cnt>temp)	cout<<i<<"th\n";
		}
		cout<<cnt<<"\n";
	}
	return 0;
}