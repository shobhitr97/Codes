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
typedef pair<ll, ll> pll;
typedef vector<pll>vpll;

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
	ll a[num];
	vector<pair<ll, int> > na;
	bool vis[num];
	int n, pos[num];
	cin>>n;
	fori(0, n)	cin>>a[i];
	fori(0, n)	na.pb(mp(a[i], i));
	sort(na.begin(), na.end());
	fori(0, n)	pos[na[i].se]=i;

	fori(0, n)	vis[i]=false;

	vector<vi>ans;
	fori(0, n){
		if(vis[i]==true)	continue;
		int cur=pos[i];
		vi pp;
		pp.pb(i);
		while(cur!=i){
			vis[cur]=true;
			pp.pb(cur);
			cur=pos[cur];
		}
		ans.pb(pp);
	}

	int cnt=ans.size(), cnt1;
	cout<<cnt<<"\n";
	fori(0, cnt){
		cnt1=ans[i].size();
		cout<<cnt1;
		forn(j, 0, cnt1)	cout<<" "<<ans[i][j]+1;
		cout<<"\n";
	}

	return 0;
}