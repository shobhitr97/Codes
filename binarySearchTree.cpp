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
#define num 10005

int le[num], ri[num], n, nodes[num];

int buildTree(int index, int par, int l, int r){
	int val;
	if(nodes[index]>l&&nodes[index]<nodes[par]){
		le[par]=index;
		if(index==n-1)	return -1;
		val=buildTree(index+1, index, l, nodes[par]);
		if(val==-1)	return -1;
	}
	else	val=index;

	if(nodes[val]>nodes[par]&&nodes[val]<r){
		ri[par]=val;
		if(index==n-1)	return -1;
		val=buildTree(val+1, val, nodes[par], r);
	}

	return val;
}

void dfs(int index){
	if(le[index]!=n)	dfs(le[index]);
	if(ri[index]!=n)	dfs(ri[index]);
	cout<<nodes[index]<<"\n";
}

int main(){
	int x;
	n=0;
	while(cin>>x){
		nodes[n]=x;
		n++;
	}
	fori(0, n)	le[i]=ri[i]=n;
	nodes[n]=-1;
	int val=buildTree(1, 0, 0, 1000000);
	// fori(0, n)	cout<<"("<<nodes[i]<<") : "<<nodes[le[i]]<<" "<<nodes[ri[i]]<<"\n";
	dfs(0);
	return 0;
}