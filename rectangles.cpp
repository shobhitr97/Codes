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

ll powr(int x){
	ll ans=1;
	ll y=2;
	while(x){
		if(x%2==1)	ans*=y;
		x/=2;
		y=y*y;
	}
	return ans;
}

int main(){
	int n, m, a[52][52];
	int cntR[52], cntC[52];
	ll ans;
	cin>>n>>m;
	forn(i, 0, n){
		forn(j, 0, m)	cin>>a[i][j];
	}
	ans=n*m;
	fori(0, n)	cntR[i]=0;
	fori(0, m)	cntC[i]=0;
	forn(i, 0, n){
		forn(j, 0, m){
			if(a[i][j]==0){
				cntR[i]++;
				cntC[j]++;
			}
		}
	}
	fori(0, n)	ans+=(powr(cntR[i])-cntR[i]-1);
	fori(0, m)	ans+=(powr(cntC[i])-cntC[i]-1);

	fori(0, n)	cntR[i]=0;
	fori(0, m)	cntC[i]=0;
	forn(i, 0, n){
		forn(j, 0, m){
			if(a[i][j]==1){
				cntR[i]++;
				cntC[j]++;
			}
		}
	}
	fori(0, n)	ans+=(powr(cntR[i])-cntR[i]-1);
	fori(0, m)	ans+=(powr(cntC[i])-cntC[i]-1);

	cout<<ans<<"\n";

	return 0;
}