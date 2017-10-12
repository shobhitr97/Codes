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
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define pb push_back
#define mp make_pair
#define fori(a, b) for(int i=a ; i<b ; i++ )
#define forn(i, a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define INF 1000000007
#define num 100005
#define li 0
#define ri 1

int main(){
	stack<ii>st;
	vector<pll>input;
	int n, cnt=0, reachL[num], maxR[num];
	ll x, y, dp[num][2];
	cin>>n;
	fori(0, n){
		cin>>x>>y;
		if(y>0){
			input.pb(mp(x, y));
			cnt++;
		}
	}
	n=cnt;

	st.push(mp(0, 0));
	reachL[0]=0;
	fori(1, n){
		ll temp=input[i].fi-input[i].se;
		int index=i;
		while(!st.empty()){
			ii t=st.top();
			if(temp>input[t.se].fi)	break;
			st.pop();
			index=min(index, t.fi);
			temp=min(temp, input[t.fi].fi-input[t.fi].se);
		}
		st.push(mp(index, i));
		reachL[i]=index;
	}
	while(!st.empty())	st.pop();
	st.push(mp(0, 0));
	maxR[0]=0;
	fori(1, n){
		ii t;
		int index=i;
		while(!st.empty()){
			t=st.top();
			st.pop();
			if(input[index].fi>input[t.se].fi+input[t.se].se)	break;
			index=min(index, t.fi);
		}
		st.push(mp(index, i));
		maxR[i]=index;
	}
	// cout<<"\n";
	// fori(0, n)	cout<<reachL[i]<<" ";
	// cout<<"\n";
	// fori(0, n)	cout<<maxR[i]<<" ";
	// cout<<"\n";

	fori(0, n)	dp[i][li]=dp[i][ri]=INF;

	dp[0][0]=dp[0][1]=1;
	fori(1, n){
		dp[i][ri]=1+min(dp[i-1][li], dp[i-1][ri]);
		if(maxR[i]<i)	dp[i][ri]=min(dp[i][ri], dp[maxR[i] ][ri]);
		if(!reachL[i])	dp[i][li]=1;
		else{
			dp[i][li]=min(dp[i][li], 1+dp[reachL[i]-1][li]);
			dp[i][li]=min(dp[i][li], 1+dp[reachL[i]-1][ri]);
		}
	}
	cout<<min(dp[n-1][li], dp[n-1][ri])<<"\n";
	return 0;
}