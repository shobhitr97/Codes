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
#define num 100

int main(){
	int n, capacity, dp[num][num], weight[num], price[num];
	cin>>n>>capacity;
	fori(1, n+1)	cin>>weight[i]>>price[i];
	fori(0, n+1)	forn(j, 0, capacity+1)	dp[i][j]=-1;
	dp[0][0]=0;
	fori(1, n+1){
		forn(j, 0, capacity+1){
			dp[i][j]=dp[i-1][j];
			if(j>=weight[i]&&dp[i-1][j-weight[i] ]!=-1)	dp[i][j]=max(dp[i][j], dp[i-1][j-weight[i] ]+price[i]);
		}
	}
	fori(0, n+1){
		forn(j, 0, capacity+1)	cout<<dp[i][j]<<" ";
		cout<<"\n";
	}
	cout<<dp[n][capacity]<<"\n";
	return 0;
}		