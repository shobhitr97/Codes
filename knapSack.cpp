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
#define N 1005

int main(){
	// States : Determined by Weight and the index of the item checked
	// State (i, j)	:	The maximum value that a knapsack can possess while having a weight of j kg and the items upto i-th index.
	int knapsack[N][N], val[N], weight[N];
	forn(i, 0, n){
		forn(j, 0, MaxVal)	knapsack[i][j]=-1;
	}
	knapsack[0][ weight[0] ]=val[0];
	knapsack[0][0]=0;
	forn(i, 1, n){
		forn(j, 0, MaxVal){
			if(knapsack[i-1][j]==-1)	continue;
			knapsack[i][ j+weight[i] ]=max(knapsack[i-1][ j+weight[i] ], knapsack[i-1][j]+val[i]);
		}
	}

	return 0;
}