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
#define fi first
#define se second
#define INF 1000000007

int main(){
	int n, m, minm, pos, cnt;
	string s, t;
	cin>>n>>m;
	cin>>s>>t;
	minm=INF;
	fori(0, m-n+1){
		cnt=0;
		forn(j, 0, n){
			if(t[i+j]!=s[j])	cnt++;
		}
		if(cnt<minm)	minm=cnt, pos=i;
	}
	cout<<minm<<"\n";
	fori(0, n)	if(t[pos+i]!=s[i])	cout<<(i+1)<<" ";
	cout<<"\n";
	return 0;
}