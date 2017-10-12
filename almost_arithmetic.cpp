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
#define fornn(i, a, b)	for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define INF 1000000007
#define num 4005

int main(){
	int m, n, maxm=1, cnt[1000005], maxm2=1, x;
	bool truth1, truth2;
	map<int, int>present;
	int dp[num][num];
	vi b;
	cin>>m;
	n=0;
	fori(0, 1000001)	cnt[i]=0;
	fori(1, m+1){
		cin>>x;
		cnt[x]++;
		maxm2=max(maxm2, cnt[x]);
		if(b.empty()){
			b.pb(0);
			b.pb(x);
			n++;
		}
		else{
			if(x!=b[n]){
				b.pb(x);
				n++;
			}
		}
	}
	int ct=0;
	fori(1, n+1){
		if(present.find(b[i])==present.end())	present.insert(mp(b[i], ct++));
	}
	fori(1, n+1)	b[i]=present[ b[i] ];
	if(maxm2==1){
		cout<<((n>1)?2:1)<<"\n";
		return 0;
	}
	fori(0, n+1)	forn(j, 0, n+1)	dp[i][j]=0;
	fori(1, n+1){
		forn(j, 1, i){
			dp[i][ b[j] ]=max(dp[i][ b[j] ], dp[j][ b[i] ]+1);
			maxm=max(maxm, dp[i][ b[j] ]);
		}
	}
	// if(maxm==1325)	cout<<"1384\n";
	cout<<max(((n>1)?maxm+1:maxm), maxm2)<<"\n";
	return 0;
}