#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>
#include<queue>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef pair<double, int> di;

#define pb push_back
#define mp make_pair
#define fori(a, b) for(int i=a ; i<b ; i++ )
#define forn(i, a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define INF 1000000007
#define num 54

int n, m, p, pos[14];
priority_queue<di, vector<di>, greater<di> > pq;
vector<vector<pair<int, double> > >adjList;
double s[14], dist[num][num], dp[14][1<<13];

void djikstra(int index){
	int visited[num];
	di temp;
	fori(0, n+1)	visited[i]=0;
	pq.push(mp(0.00, index));
	while(!pq.empty()){
		temp=pq.top();
		pq.pop();
		if(visited[temp.se])	continue;
		visited[temp.se]=1;
		dist[index][temp.se]=dist[temp.se][index]=temp.fi;
		vector<pair<int, double> >::iterator it;
		for(it=adjList[temp.se].begin();it!=adjList[temp.se].end();it++){
			if(visited[(*it).fi])	continue;
			pq.push(mp((*it).se+temp.fi, (*it).fi));
		}
	}
}

double tsp(int index, int mask){
	if(dp[index][mask]!=-1)	return dp[index][mask];
	double temp, maxm;
	maxm=(-1.0)*dist[ pos[index] ][0];
	fori(0, p){
		if(mask&(1<<i))	continue;
		temp=s[i]-dist[ pos[index] ][ pos[i] ];
		if(dp[i][mask|(1<<i)]!=-1)	temp+=dp[i][mask|(1<<i)];
		else	temp+=tsp(i, mask|(1<<i));
		maxm=max(temp, maxm);
	}
	dp[index][mask]=maxm;
	return maxm;
}

int main(){
	int t, u, v;
	double w, ans;
	vector<double>output;
	cin>>t;
	forn(z, 0, t){
		cin>>n>>m;
		adjList.resize(n+2);
		// forn(i, 0, n+1)	forn(j, 0, n+1)	dist[i][j]=INF;
		fori(0, m){
			cin>>u>>v>>w;
			adjList[u].pb(mp(v, w));
			adjList[v].pb(mp(u, w));
			// ans=min(dist[u][v], dist[v][u]);
			// dist[u][v]=dist[v][u]=min(w, ans);
		}
		cin>>p;
		fori(0, p){
			cin>>pos[i]>>s[i];
		}
		fori(0, p){
			djikstra(pos[i]);
		}
		// forn(i, 0, n+1){
		// 	forn(j, 0, n+1){
		// 		forn(k, 0, n+1){
		// 			if(dist[j][i]!=INF&&dist[i][k]!=INF)	dist[j][k]=min(dist[j][i]+dist[i][k], dist[j][k]);
		// 		}
		// 	}
		// }
		ans=0.0;
		forn(i, 0, p)	forn(j, 0, 1<<p)	dp[i][j]=-1;
		fori(0, p)	dp[i][(1<<p)-1]=(-1.0)*dist[ pos[i] ][0];
		fori(0, p)	ans=max(ans, tsp(i, 1<<i)+s[i]-dist[0][ pos[i] ]);
		output.pb(ans);
		adjList.clear();
	}
	fori(0, t){
			if(output[i]==0.00)	cout<<"Don't leave the house\n";
			else	printf("Daniel can save $%.2lf\n", output[i]);
	}
	return 0;
}