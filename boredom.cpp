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
#define num 100005

int main(){

	int n;
	ll dp[num], ans, cnt[num];
	vi a;

	cin>>n;

	fori(0, num)	cnt[i]=0;

	a.resize(n);
	fori(0, n){
		cin>>a[i];
		cnt[a[i]]++;
	}

	dp[0] = 0;
	dp[1] = (cnt[1]>0?cnt[1]:0);

	ans = 1;

	fori(2, num-4){
		dp[i] = max(dp[i-2] + cnt[i]*i, dp[i-1]);
		ans = max(ans, dp[i]);
	}

	cout<<ans<<"\n";

	return 0;
}