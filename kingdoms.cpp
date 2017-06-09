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

int maxm;
int pop[20], K;

int main(){
	int t, n, m, u, v, c;
	cin>>t;
	while(t--){
		cin>>n>>m>>K;
		fori(1, n+1)	cin>>pop[i];	
		fori(0, m){
			cin>>u>>v>>c;
		}
	}
	return 0;
}