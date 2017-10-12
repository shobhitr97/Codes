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
	int n, m, t, dp[100005], maxm;
	while(cin>>m){
		cin>>n>>t;
		fori(0, t+1)	dp[i]=0;
		maxm=0;
		dp[n]=1;
		dp[m]=1;
		fori(0, t+1){
			dp[i]=max(dp[i], max(((i>m&&dp[i-m])?dp[i-m]+1:0), ((i>n&&dp[i-n])?dp[i-n]+1:0)));
			maxm=max(maxm, dp[i]);
		}
		// forn(i, 0, t+1)	cout<<dp[i]<<" ";
		// cout<<"\n";
		if(dp[t])	cout<<dp[t]<<"\n";
		else{
			int k=t-1;
			while(k>=0&&dp[k]==0)	k--;
			if(k==-1)	cout<<"0 "<<t<<"\n";
			else	cout<<dp[k]<<" "<<t-k<<"\n";
		}
	}
	return 0;
}