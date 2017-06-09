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
#define INF 1000000007

vii dr, co;
int dist[13][13], dp[13][1<<12], n;

int tsp(int pos, int mask){
	int minm=INF, temp;
	if(dp[pos][mask]!=-1)	return dp[pos][mask];
	fori(1, n+1){
		if(mask&(1<<(i-1)))	continue;
		if(dp[i][mask|(1<<(i-1))]!=-1)	temp=dist[pos][i]+dp[i][mask|(1<<(i-1))];
		else	temp=dist[pos][i]+tsp(i, mask|(1<<(i-1)));
		minm=min(minm, temp);	
	}
	dp[pos][mask]=minm;
	return minm;
}

int main(){
	int t, l, r, x, y, mask, ans;
	vi output;
	dr.pb(ii(0, 1));
	dr.pb(ii(0, -1));
	dr.pb(ii(1, 0));
	dr.pb(ii(-1, 0));
	cin>>t;
	forn(k, 0, t){
		cin>>l>>r;
		cin>>x>>y;
		co.pb(mp(x, y));
		cin>>n;
		fori(0, n){
			cin>>x>>y;
			co.pb(mp(x, y));
		}
		fori(0, n+1){
			forn(j, i, n+1){
				x=co[i].fi - co[j].fi;
				y=co[i].se - co[j].se;
				dist[i][j]=dist[j][i]=(int)(abs(x)+abs(y));
			}
		}
		// forn(i, 0, n+1){
		// 	forn(j, 0, n+1)	cout<<dist[i][j]<<" ";
		// 	cout<<"\n";
		// }
		mask=0, ans=INF;
		forn(i, 1, n+1)	forn(j, 0, 1<<n)	dp[i][j]=-1;
		fori(1, n+1)	dp[i][(1<<n)-1]=dist[i][0];
		fori(1, n+1)	ans=min(ans, dist[0][i]+tsp(i, 1<<(i-1)));
		// cout<<"The shortest path has length "<<ans<<"\n";
		output.pb(ans);
		co.clear();
	}
	fori(0, t)	cout<<"The shortest path has length "<<output[i]<<"\n";
	return 0;
}