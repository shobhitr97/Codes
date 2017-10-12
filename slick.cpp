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

int a[252][252], n, m;
bool vis[252][252];

ii dir[4]={mp(0, -1), mp(0, 1), mp(1, 0), mp(-1, 0)};

int dfs(int i, int j){
	stack<ii>st;
	st.push(mp(i, j));
	vis[i][j]=true;
	int x, y, ans=0;
	while(!st.empty()){
		ii tmp=st.top();
		st.pop();
		ans++;
		forn(k, 0, 4){
			x=tmp.fi+dir[k].fi;
			y=tmp.se+dir[k].se;
			if(x<0||x>=n||y<0||y>=m)	continue;
			if(a[x][y]==0||vis[x][y]==true)	continue;
			vis[x][y]=true;
			st.push(mp(x, y));
		}
	}
	return ans;
}

int main(){
	int siz, val, cnt, pp;
	vector<int>sol;
	while(1){
		pp=0;
		cin>>n>>m;
		if(n==0&&m==0)	break;
		fori(0, n)	forn(j, 0, m)	cin>>a[i][j];
		fori(0, n)	forn(j, 0, m)	vis[i][j]=false;
		fori(0, n){
			forn(j, 0, m){
				if(vis[i][j]==true)	continue;
				if(a[i][j]==0){
					vis[i][j]=true;
					continue;
				}
				// cout<<"\n";
				siz=dfs(i, j);
				// cout<<siz<<"\n";
				sol.pb(siz);
				pp++;
			}
		}
		sort(sol.begin(), sol.end());
		siz=sol.size();
		int i=1;
		cnt=0;
		if(siz>0)	val=sol[0], cnt=1;
		cout<<pp<<"\n";
		while(i<siz){
			if(sol[i]==val)	cnt++;
			else{
				cout<<val<<" "<<cnt<<"\n";
				val=sol[i], cnt=1;
			}	
			i++;
		}
		if(cnt>0)	cout<<val<<" "<<cnt<<"\n";
		sol.clear();
	}
	return 0;
}