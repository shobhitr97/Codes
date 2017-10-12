#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>

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
#define pq priority_queue

ii aliens[104];
int parent[104];

int findParent(int x){
	if(parent[x]!=x)	parent[x]=findParent(parent[x]);
	return parent[x];
}

int main(){
	int n, x, y, maze[54][54], cnt, px, py, u, v, w, a, b, visited[54][54], explored[104], cntEdges;
	string str;
	ll cost;	
	char ch;
	queue<iii>bfsQueue;
	// vector<vector<ii> > adjList;
	viii edges;
	
	cin>>n;
	while(n--){
		cin>>x>>y;
		cnt=1;
		// cout<<x<<y<<"\n";
		fori(0, y){
			forn(j, 0, x)	maze[i][j]=0;
		}
		cnt=1;
		int j=-1;
		while(getline(cin, str)){
			if(j==-1){
				j++;
				continue;
			}
			fori(0, x){
				switch(str[i]){
					case '#':	maze[j][i]=-1;
								break;
					case 'A':	maze[j][i]=cnt;
								aliens[cnt++]=mp(j, i);
								break;
					case 'S':	px=j, py=i;
								break;
				}
			}
			j++;
			if(j==y)	break;
		}	
		// fori(0, y){
		// 	forn(j, 0, x)	cout<<maze[i][j]<<" ";
		// 	cout<<"\n";
		// }
		maze[px][py]=cnt;
		aliens[cnt]=mp(px, py);
		// cnt--;
		// fori(1, cnt+1)	cout<<"("<<aliens[i].fi<<","<<aliens[i].se<<")\n";
		// cout<<cnt<<"\n";
		// adjList.resize(cnt+2);
		forn(j, 0, y){
			forn(k, 0, x)	visited[j][k]=0;
		}
		fori(1, cnt+1){
			bfsQueue.push(mp(0,aliens[i]));
			a=aliens[i].fi;
			b=aliens[i].se;
			// cout<<a<<","<<b<<"\n";
			while(!bfsQueue.empty()){
				u=bfsQueue.front().se.fi;
				v=bfsQueue.front().se.se;
				w=bfsQueue.front().fi;
				// cout<<"("<<u<<","<<v<<") - "<<w<<"\n";
				visited[u][v]++;
				bfsQueue.pop();
				// if( maze[u][v]>=1 && (u!=a||v!=b) )	adjList[ maze[a][b] ].pb(mp(maze[u][v], w));
				if( maze[u][v]>=1 && (u!=a||v!=b) )	edges.pb(mp(w, mp(maze[a][b], maze[u][v])));
				if(u+1<x&&maze[u+1][v]!=-1&&visited[u+1][v]<i)	bfsQueue.push(mp(w+1, mp(u+1, v)));
				if(u-1>=0&&maze[u-1][v]!=-1&&visited[u-1][v]<i)	bfsQueue.push(mp(w+1, mp(u-1, v)));
				if(v+1<y&&maze[u][v+1]!=-1&&visited[u][v+1]<i)	bfsQueue.push(mp(w+1, mp(u, v+1)));
				if(v-1>=0&&maze[u][v-1]!=-1&&visited[u][v-1]<i)	bfsQueue.push(mp(w+1, mp(u, v-1)));
			}
		}
		vii::iterator it;
		// fori(1, cnt+1){
		// 	cout<<i<<"\n";
		// 	for(it=adjList[i].begin();it!=adjList[i].end();it++){
		// 		cout<<(*it).fi<<" "<<(*it).se<<"\n";
		// 	}
		// }
		// fori(1, 101)	explored[i]=0;
		cost=0;
		// pq<ii, vector<ii>, greater<ii> > primQueue;
		// primQueue.push(mp(0, cnt));        //	To be solved
		// while(!primQueue.empty()){
		// 	u=primQueue.top().se;
		// 	w=primQueue.top().fi;
		// 	primQueue.pop();
		// 	if(explored[u])	continue;
		// 	// cout<<u<<" "<<w<<"\n";
		// 	cost+=w;
		// 	explored[u]=1;
		// 	for(it=adjList[u].begin();it!=adjList[u].end();it++){
		// 		if(!explored[(*it).fi])	primQueue.push(mp((*it).se, (*it).fi));
		// 	}	
		// }
		fori(1, cnt+1)	parent[i]=i;
		cntEdges=0;
		sort(edges.begin(), edges.end());
		for(viii::iterator it=edges.begin();it!=edges.end();it++){
			u=findParent((*it).se.fi);
			v=findParent((*it).se.se);
			w=(*it).fi;
			if(u!=v){
				cntEdges++;
				cost+=w;
				parent[u]=v;
				if(cntEdges==cnt-1)	break;
			}
		}
		cout<<cost<<"\n";
		// adjList.clear();
		edges.clear();
	}	

	return 0;
}