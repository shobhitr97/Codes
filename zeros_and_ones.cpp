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

int main(){
	int t, N, K;
	vector<ll> output;
	ll dp[33][33][101];

	cin>>t;
	forn(z, 0, t){
		cin>>N>>K;
		if(N%2){
			output.pb(0);
			continue;
		}
		fori(0, N/2+1)	forn(j, 0, N/2+1)	forn(k, 0, K)	dp[i][j][k]=0;
		dp[0][0][0]=1;
		fori(0, N/2+1){
			forn(j, 0, N/2){
				// if(i==(N/2-1)&&j==(N/2))	continue;
				forn(k, 0, K){
					if(i<N/2)	dp[i+1][j][k]+=dp[i][j][k];
					if(j<N/2)	dp[i][j+1][(int)((k+(ll)(1<<(i+j))%K)%K)]+=dp[i][j][k];
				}
			}
		}
		// fori(0, K)	dp[N/2][N/2][(i+(int)(1<<N)%K)%K]+=dp[N/2][N/2-1][i];	
		forn(i, 0, N/2+1){
			forn(j, 0, N/2+1){
				// forn(k, 0, K)	cout<<dp[i][j][k]<<",";
				cout<<dp[i][j][0]<<" ";
			}
			cout<<"\n";
		}
		output.pb(dp[N/2][N/2][0]);
	}

	fori(0, t)	cout<<"Case "<<(i+1)<<": "<<output[i]<<"\n";
	return 0;
}