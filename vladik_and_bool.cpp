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
#define num 10003

int p[num], n;

int main(){
	int m, l, r, x;
	cin>>n>>m;
	fori(1, n+1){
		cin>>p[i];
	}
	fori(0, m){
		cin>>l>>r>>x;
		int cnt=0;
		forn(j, l, r+1){
			if(p[j]>p[x])	cnt++;
		}
		if(cnt==r-x)	cout<<"Yes\n";
		else	cout<<"No\n";
	}
	return 0;
}