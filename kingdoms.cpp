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

int maxm;
int pop[20], K;

int main(){
	int t, n, m, u, v, c;
	vi output;
	int dp[1<<16+4];
	bool vis[20];
	vector<vii>rel;
	cin>>t;
	int TT=t;
	while(t--){
		cin>>n>>m>>K;
		rel.resize(n+2);
		fori(0, n)	cin>>pop[i];	
		fori(0, 1<<16)	dp[i]=INF;
		fori(0, m){
			cin>>u>>v>>c;
			rel[u-1].pb(mp(c, v-1));
			rel[v-1].pb(mp(c, u-1));
		}

		fori(0, n)	sort(rel[i].begin(), rel[i].end());
		fori(0, n)	vis[i]=false;
		dp[1]=0;
		queue<int>qu;
		qu.push(0);
		while(!qu.empty()){
			int temp=qu.front();
			qu.pop();
			if(vis[temp]==true){
				continue;
			}
			// cout<<temp+1<<"->";
			vis[temp]=true;
			int siz=rel[temp].size();
			forn(j, 0, siz){
				forn(k, 0, 1<<16){
					if(k&(1<<temp)&&dp[k]!=INF){
						dp[k|(1<<rel[temp][j].se)]=min(dp[k|(1<<rel[temp][j].se)], dp[k]+rel[temp][j].fi);
						qu.push(rel[temp][j].se);
					}
				}
			}
		}
		// cout<<"\n";
		int ans=0, ansMask;
		fori(0, 1<<16){
			if(i&1){
				if(dp[i]>K)	continue;
				int sum=0;
				forn(j, 0, n){
					if((1<<j)&i)	sum+=pop[j];
				}
				// ans=max(ans, sum);
				if(ans<sum){
					ans=sum;
					ansMask=i;
				}
			}
		}
		// cout<<ans<<"\n";
		output.pb(ans);
		// fori(0, n){
		// 	if(ansMask&(1<<i))	cout<<(i+1)<<" ";
		// }
		// cout<<"\n";
		cout<<dp[1<<0 + 1<<2 + 1<<4 + 1<<5 + 1<<7 + 1<<11]<<"\n";
		rel.clear();
	}
	fori(0, TT)	cout<<output[i]<<"\n";
	cin>>t;
	while(t--){
		cin>>n>>m>>K;
		fori(1, n+1)	cin>>pop[i];	
		fori(0, m){
			cin>>u>>v>>c;
		}
	}
	return 0;
}