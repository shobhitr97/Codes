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
	int k, n, t, p, dp[72][72];
	vi output;
	cin>>k;
	forn(z, 0, k){
		cin>>n>>t>>p;
		fori(0, n+1)	forn(j, 0, t+1)	dp[i][j]=0;
		fori(p, t+1)	dp[1][i]=1;
		forn(i, 2, n+1){
			forn(j, p, t+1){
				int r, ways=0;
				r=(i-1)*p;
				// cout<<"For ("<<i<<","<<j<<") : "<<(i-1)*p<<" to "<<j-p<<"\n";
				while(r<=j-p)	ways+=dp[i-1][r++];
				dp[i][j]=ways;
			}
		}
		// forn(i, 1, n+1){
		// 	forn(j, 1, t+1)	cout<<dp[i][j]<<" ";
		// 	cout<<"\n";
		// }
		output.pb(dp[n][t]);
	}
	fori(0, k)	cout<<output[i]<<"\n";
	return 0;
}