#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>

using namespace std;

typedef pair<int, int> ii;
typedef pair<double, double> dd; 
typedef vector< ii > vii;
typedef vector< dd > vdd;
typedef vector< pair< double, ii > > vdii;
typedef vector< vector< pair< int, double> > > vvid;

#define num 752
#define N 1003
#define fori(a, b) for( int i=a ; i<b ; i++ )
#define forin(a, b) for( int i=a ; i>=b ; i-- )
#define pb push_back
#define mp make_pair

int n, m, parent[num];

int findRoot(int x){
	if( parent[x] == x ){
		return x;
	}
	else{
		parent[x] = findRoot(parent[x]);
		return parent[x];
	}
}

bool isSameSet(int x, int y){
	int parx = findRoot(x);
	int pary = findRoot(y);

	return (parx == pary); 
}

void dsuAdd(int x, int y){
	parent[ parent[x] ] = parent[y];
}

int main(){
	int k, u, v;
	cin>>n>>m>>k;
	fori(0, n){
		parent[i]=i;
	}
	fori(0, m){
		cin>>u>>v;
		if(!isSameSet(u, v)){
			dsuAdd(u, v);
		}
	}
	fori(0, k){
		cin>>u>>v;
		if(!isSameSet(u, v))	cout<<"NO\n";
		else	cout<<"YES\n";
	}
	return 0;
}
