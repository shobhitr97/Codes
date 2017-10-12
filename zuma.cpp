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
#define num 504

int main(){
	int dp[num][num], n, c[num], k;
	cin>>n;
	forn(i, 0, n)	cin>>c[i];

	forn(i, 0, n+1)	forn(j, 0, n+1)	dp[i][j]=(i>j)?0:(j-i+1);

	forn(i, 0, n-1)	if(c[i]==c[i+1])	dp[i][i+1]=1;
	forn(diff, 2, n){
		forn(index, 0, n){
			if(index+diff>=n)	break;
			int t=dp[index][index+diff];
			k=index+1;
			while(k<=index+diff){
				if(c[k]==c[index]){
					if(k==(index+1))	t=min(t, 1+dp[index+2][index+diff]);
					else	if(k==index+diff)	t=min(t, dp[index+1][index+diff-1]);
					else	t=min(t, dp[index+1][k-1]+dp[k+1][index+diff]);
					t=min(t, dp[index][k]+dp[k+1][index+diff]);
				}
				k++;
			}
			dp[index][index+diff]=min(t, 1+dp[index+1][index+diff]);
		}
	}
	// cout<<"\n";
	// forn(i, 0, n){
	// 	forn(j, 0, n)	cout<<dp[i][j]<<" ";
	// 	cout<<"\n";
	// }
	cout<<dp[0][n-1]<<"\n";
	return 0;
}