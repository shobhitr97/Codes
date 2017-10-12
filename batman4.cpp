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
#define N 25
#define N2 405

ii min(ii a, ii b){
	if(a.fi<b.fi)	return a;
	if(a.fi>b.fi)	return b;
	if(a.fi==b.fi)	return ((a.se<b.se)?a:b);
}

int main(){
	int t, n, T, h[N][N];
	ii dp[N2][N2];
	ii nul=mp(-1, -1);
	fori(0, 401)	forn(j, 0, 401)	dp[i][j]=nul;
	cin>>t;
	forn(z, 0, t){
		cin>>n>>T;
		fori(0, n){
			forn(j, 0, n)	cin>>h[i][j];
		}
		fori(0, n*n)	dp[i][i]=mp(0, 0);
		fori(0, n){
			forn(j, 0, n){
				if(j<n-1)	dp[i*n+j][i*n+j+1]=mp(((h[i][j]>=h[i][j+1])?0:h[i][j+1]-h[i][j]), (int)abs(h[i][j]-h[i][j+1]));
				if(j)	dp[i*n+j][i*n+j-1]=mp(((h[i][j]>=h[i][j-1])?0:h[i][j-1]-h[i][j]), (int)abs(h[i][j]-h[i][j-1]));
				if(i)	dp[i*n+j][(i-1)*n+j]=mp(((h[i][j]>=h[i-1][j])?0:h[i-1][j]-h[i][j]), (int)abs(h[i][j]-h[i-1][j]));
				if(i<n-1)	dp[i*n+j][(i+1)*n+j]=mp(((h[i][j]>=h[i+1][j])?0:h[i+1][j]-h[i][j]), (int)abs(h[i][j]-h[i+1][j]));
			}
		}
		// fori(0, n*n){
		// 	forn(j, 0, n*n)	cout<<dp[i][j].fi<<" "<<dp[i][j].se<<"\n";
		// 	cout<<"\n";
		// }
		fori(0, n*n){
			forn(j, 0, n*n){
				forn(k, 0, n*n){
					if(dp[j][i]!=nul&&dp[i][k]!=nul){
						if(dp[j][k]==nul)	dp[j][k]=mp(max(dp[j][i].fi, dp[i][k].fi), dp[j][i].se+dp[i][k].se);
						else	dp[j][k]=min(dp[j][k], mp(max(dp[j][i].fi, dp[i][k].fi), dp[j][i].se+dp[i][k].se));
					}
				}
			}
		}
		// fori(0, n*n){
		// 	forn(j, 0, n*n)	cout<<dp[i][j].fi<<" "<<dp[i][j].se<<"\n";
		// 	cout<<"\n";
		// }
		if(dp[0][n*n-1]==nul||(h[0][0]+dp[0][n*n-1].se)>=T)	cout<<"NO\n";
		else	cout<<"YES : "<<max(h[0][0], dp[0][n*n-1].fi)<<" "<<T-(dp[0][n*n-1].se+h[0][0])<<"\n";
	}
	return 0;
}