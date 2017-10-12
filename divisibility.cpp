#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>
#include<queue>

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

int dp[10005][103], n, k, arr[10005];

int main(){
	int m;
	cin>>m;
	vi output;
	forn(z, 0, m){
		cin>>n>>k;
		fori(0, n)	cin>>arr[i];
		forn(i, 0, n)	forn(j, 0, k)	dp[i][j]=-1;
		dp[0][ ( k + (arr[0]%k) )%k ]=1;
		forn(i, 1, n){
			forn(j, 0, k){
				if(dp[i-1][j]!=-1){
					dp[i][(k+(j+arr[i])%k)%k]=dp[i][(k+(j-arr[i])%k)%k]=1;
				}
			}
		}
		output.pb(dp[n-1][0]);
	}
	fori(0, m){
		if(output[i]==1)	cout<<"Divisible\n";
		else	cout<<"Not divisible\n";
	}
	return 0;
}