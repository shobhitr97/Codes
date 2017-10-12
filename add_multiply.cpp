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
#define num 100005

int main(){
	ll dp[num], arr[num], sum, proSum, cnt[num], cntSum;
	int n, t;
	vector<ll>output;
	cin>>t;
	forn(z, 0, t){
		cin>>n;
		fori(0, n)	cin>>arr[i+1];
		dp[n]=arr[n];
		sum=proSum=arr[n];
		cnt[n]=cntSum=1;
		forin(n-1, 1){
			cnt[i]=cntSum+1;
			proSum=(((proSum+cnt[i+1])%INF)*arr[i])%INF;
			dp[i]=(proSum+sum)%INF;
			sum=(sum+dp[i])%INF;
			cntSum+=cnt[i];
		}
		// fori(1, n+1)	cout<<dp[i]<<" ";
		// cout<<"\n";
		output.pb(dp[1]);
	}
	forn(i, 0, t)	cout<<output[i]<<"\n";
	return 0;
}