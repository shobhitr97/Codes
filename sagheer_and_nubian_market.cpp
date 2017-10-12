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

ii lr[17];
int M[17][105], m, n;

int tsp(int indx, int flr){
	if(flr==n-1)	return 0;
	int temp, nxt;
	nxt=flr+1;
	// cout<<flr<<": "<<indx<<"\n";
	while(nxt<n&&lr[nxt].se==0)	nxt++;
	if(nxt==n)	return 0;
	return (nxt-flr+min(indx+lr[nxt].se+tsp(lr[nxt].se, nxt), m+1-indx+m+1-lr[nxt].fi+tsp(lr[nxt].fi, nxt)) );
}

int main(){
	int left, right, k, ans;
	string s;
	cin>>n>>m;
	// Mind it
	forin(n-1, 0){
		cin>>s;
		forn(j, 0, m+2){
			if(s[j]=='0')	M[i][j]=0;
			else	M[i][j]=1;
		}
	}
	forn(i, 0, n){
		left=m+1, right=0;
		forn(j, 0, m+2){
			if(M[i][j])	left=min(left, j), right=max(right, j);
		}
		lr[i].fi=left, lr[i].se=right;
		// cout<<left<<", "<<right<<"\n";
	}
	k=0;
	while(k<n&&(lr[k].se==0))	k++;
	if(k==n){
		cout<<"0\n";
		return 0;
	}
	ans=k+lr[k].se;
	cout<<(ans+tsp(lr[k].se, k))<<"\n";
	return 0;
}