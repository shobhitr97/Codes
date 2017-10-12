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
#define li 0
#define ri 1

vector<pair<ll, ll> >input;
int n, reachL[num], max_hit[num];

class Compare{
public:
	bool operator() (ii a, ii b){
		if(a.fi<b.fi)	return false;
		if(a.fi>b.fi)	return true;
		return (a.se<b.se);
	}
};

// // binary search
// int bin(ll location){
// 	int l=0, r=n-1, mid;
// 	if(location<=input[0].fi)	return (-1);
// 	if(location>input[n-1].fi)	return (n-1);
// 	while(l<=r){
// 		mid=(l+r)/2;
// 		if(input[mid].fi<location)	l=mid+1;
// 		else	r=mid-1;
// 	}
// 	return l-1;
// }

int main(){
	int cnt=0;
	ll x, y;
	// priority_queue<ii, vector<ii>, Compare >pq;
	stack<pair<ll, int> >st;
	cin>>n;
	fori(0, n){
		cin>>x>>y;
		if(y>0){
			cnt++;
			input.pb(mp(x, y));
		}
	}	

	n=cnt;
	sort(input.begin(), input.end());

	// Pre-processing wrong test case : 4 5 0 0 1 0 1 1 1 -> Answer=1, Output=2

	st.push(mp(input[0].fi, 0));
	reachL[0]=0;
	fori(1, n){
		ll temp, limit=input[i].fi-input[i].se;
		int ind=i;
		// cout<<i<<"\n";
		while(!st.empty()){
			pair<ll, int> t;
			t=st.top();
			if(t.fi<limit)	break;
			else{
				st.pop();
				// cout<<"   "<<t.se<<"\n";
				temp=input[t.se].fi-input[t.se].se;
				limit=min(limit, temp);
				ind=min(ind, t.se);
			}
		}
		reachL[i]=ind;
		st.push(mp(input[i].fi, ind));
	}
	// fori(0, n)	cout<<reachL[i]<<" ";
	// cout<<"\n";

	while(!st.empty())	st.pop();

	st.push(mp(input[0].fi+input[0].se, 0));
	max_hit[0]=0;
	fori(1, n){
		ll limit=input[i].fi+input[i].se;
		int ind=i, flag=1;
		while(!st.empty()){
			pair<ll, int> t;
			t=st.top();
			st.pop();
			if(t.fi<input[i].fi)	break;
			else{
				limit=max(limit, t.fi);
				ind=t.se;
			}
		}
		st.push(mp(limit, ind));
		max_hit[i]=ind;
	}
	// fori(0, n)	cout<<max_hit[i]<<" ";
	// cout<<"\n";

	ll dp[num][2];	
	fori(0, n)	dp[i][li]=dp[i][ri]=INF;
	dp[0][li]=1;
	dp[0][ri]=1;
	fori(1, n){
		// dp[i][ri]=1+min(dp[i-1][li], dp[i-1][ri]);
		if(max_hit[i]>0)	dp[i][ri]=min(dp[i][ri], 1+min(dp[max_hit[i]-1][ri], dp[max_hit[i]-1][li]));
		else	dp[i][ri]=1;
		if(reachL[i]>0)	dp[i][li]=min(dp[i][li], 1+min(dp[reachL[i]-1][li], dp[reachL[i]-1][ri]));
		else	dp[i][li]=1;
	}
	cout<<min(dp[n-1][li], dp[n-1][ri])<<"\n";
	return 0;
}