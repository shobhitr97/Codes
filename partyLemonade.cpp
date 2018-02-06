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
#define INF 1000000000000000007
// 44981600797903355

int main(){
	int n, L;
	ll c[32], dp[70], ans, exp[64];

	fori(0, 69)	dp[i] = INF;

	exp[0] = 1;
	fori(1, 64)	exp[i] = exp[i-1]*2;

	cin>>n>>L;
	fori(0, n)	cin>>c[i];

	fori(0, n){
		dp[i] = min(dp[i], c[i]);
	}

	fori(1, 40){
		dp[i] = min(dp[i], dp[i-1]*2);
	}

	// fori(0, 40)	cout<<dp[i]<<" ";
	// cout<<"\n";

	ll coef=INF, temp = 0;
	ans = INF;
	// cout<<(1<<30)<<"\n";
	forin(40, 0){
		coef = min(coef, dp[i]);
		cout<<exp[i]<<"\n";	
		cout<<"\t"<<dp[i]<<"\n";
		if( (L&exp[i]) > 0 ){
			temp += coef;
			cout<<"\t"<<coef<<"\n";
			cout<<"\t-->> "<<temp<<"\n";
			if(coef != dp[i]){
				break;
			}
		}
		// 	coef = min(coef, dp[i]);
		// 	// cout<<(L&(1<<i))<<"\n";
		// 	if( (L&(1<<i)) > 0){
		// 		ans += coef;
		// 	}
	}
	ans = min(ans, temp);

	cout<<ans<<"\n";

	return 0;	
}