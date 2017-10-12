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
#define num 1005

int main(){
	int n, m, a[12], b[12], c[12], d[12], maxm, dp[12][num];
	cin>>n>>m>>c[0]>>d[0];
	fori(1, m+1)	cin>>a[i]>>b[i]>>c[i]>>d[i];
	fori(0, m+1)	forn(j, 0, n+1)	dp[i][j]=-1;
	dp[0][0]=0;
	fori(1, n+1){
		if(c[0]*i>n)	break;
		dp[0][i*c[0] ]=i*d[0];
	}
	fori(1, m+1){
		forn(j, 0, n+1){
			if(dp[i-1][j]!=-1){
				int k=0;
				while(j+k*c[i]<=n&&k*b[i]<=a[i]){
					dp[i][j+k*c[i] ]=max(dp[i-1][j]+k*d[i], dp[i][j+k*c[i] ]);
					k++;
				}
			}
		}
	}
	// fori(0, m+1){
	// 	forn(j, 0, n+1)	cout<<dp[i][j]<<" ";
	// 	cout<<"\n";
	// }
	maxm=0;
	fori(0, n+1)	maxm=max(maxm, dp[m][i]);
	cout<<maxm<<"\n";
	return 0;
}