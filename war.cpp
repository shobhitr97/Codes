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

int parent[num], val[num], n, siz[num], status;
vi output;

int findParent(int x){
	if(parent[x]!=x){
		parent[x]=findParent(parent[x]);
		status=(status+val[x])%2;
		val[x]=status;
	}
	return parent[x];
}

void setFriends(int x, int y){
	int u, v, isE1, isE2;
	status=0;
	u=findParent(x);
	isE1=status;
	status=0;
	v=findParent(y);
	isE2=status;
	if(u==v){
		if(isE1^isE2==0)	return;
		cout<<"-1\n";
		// output.pb(-1);
		return;
	}
	if(siz[u]>siz[v]){
		int temp=u;
		u=v;
		v=temp;
	}
	// size of u < size of v
	parent[u]=v;
	siz[v]+=siz[u];
	if(isE1^isE2)	val[u]=1;
	else	val[u]=0;
}

void setEnemies(int x, int y){
	int u, v, isE1, isE2;
	status=0;
	u=findParent(x);
	isE1=status;
	status=0;
	v=findParent(y);
	isE2=status;
	if(u==v){
		if(isE1^isE2)	return;
		cout<<"-1\n";
		// output.pb(-1);
		return;
	}
	if(siz[u]>siz[v]){
		int temp=u;
		u=v;
		v=temp;
	}
	// size of u < size of v
	parent[u]=v;
	siz[v]+=siz[u];
	if(isE1^isE2)	val[u]=0;
	else	val[u]=1;
}

int areFriends(int x, int y){
	int u, v, isE1, isE2;
	status=0;
	u=findParent(x);
	isE1=status;
	status=0;
	v=findParent(y);
	isE2=status;
	if(u!=v)	return 0;
	return (!(isE1^isE2));
}

int areEnemies(int x, int y){
	int u, v, isE1, isE2;
	status=0;
	u=findParent(x);
	isE1=status;
	status=0;
	v=findParent(y);
	isE2=status;
	if(u!=v)	return 0;
	return (isE1^isE2);
}

int main(){
	int c, x, y;
	cin>>n;
	fori(0, n)	parent[i]=i, val[i]=0, siz[i]=1;
	while(1){
		cin>>c>>x>>y;
		if(!x&&!y&&!c)	break;
		switch(c){
			case 1:	setFriends(x, y);
					break;
			case 2:	setEnemies(x, y);
					break;
			case 3:	cout<<areFriends(x, y)<<"\n";
					break;
			case 4:	cout<<areEnemies(x, y)<<"\n";
					break;
		}
	}
	// fori(0, n)	cout<<val[i]<<" ";
	// cout<<"\n";
	// for(vi::iterator it=output.begin();it!=output.end();it++)	cout<<(*it)<<"\n";
	// output.clear();
	return 0;
}