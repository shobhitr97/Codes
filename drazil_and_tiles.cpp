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
#define num 2005

int main(){
	queue<int>degQ;
	int n, m, deg;
	int x, y, i=0;
	char a[num][num];
	ii dir[]={mp(0, 1), mp(1, 0), mp(0, -1), mp(-1, 0)};
	vector<vi>adjList;
	bool vis[num][num];
	cin>>n>>m;
	// forn(k, 0, n){
	// 	forn(j, 0, m){
	// 		cin>>a[k][j];
	// 	}
	// }
	forn(k, 0, n)	forn(j, 0, m)	vis[i][j]=false;
	adjList.resize(n*m+2);
	// while(i<n*m){
	// 	x=i/m, y=i%m;
	// 	if(a[x][y]=='*'){
	// 		i++;
	// 		continue;
	// 	}
	// 	vis[x][y]=true;
	// 	deg=0;
	// 	forn(j, 0, 4){
	// 		if(x+dir[j].fi>=0&&x+dir[j].fi<n&&y+dir[j].se>=0&&y+dir[j].se<m&&a[x+dir[j].fi][y+dir[j].se]=='.'){
	// 			if(vis[x+dir[j].fi][y+dir[j].se]==true){
	// 				deg++;
	// 				continue;
	// 			}
	// 			else{
	// 				adjList[i].pb((x+dir[j].fi)*m+y+dir[j].se);
	// 				deg++;
	// 			}
	// 		}
	// 	}
	// 	if(deg==1)	degQ.push(i);
	// 	i++;
	// }
	// forn(j, 0, n*m){
	// 	cout<<j/m<<" "<<j%m<<" : "<<deg[j]<<"\n";
	// }
	// forn(j, 0, n*m){
	// 	if(deg[j]==1)	degQ.push(j);
	// }
	// while(!degQ.empty()){
	// 	i=degQ.front();
	// 	degQ.pop();
	// 	x=i/m, y=i%m;
	// 	if(abs(adjList[i][0]-i)>1){
	// 		if(adjList[i][0]>i)	a[x][y]='^', a[x+1][y]='v';
	// 		else	a[x][y]='v', a[x-1][y]='^';
	// 	}
	// 	else{
	// 		if(adjList[i][0]>i)	a[x][y]='<', a[x][y+1]='>';
	// 		else	a[x][y]='>', a[x][y-1]='<';
	// 	}
	// 	i=adjList[i][0];
	// 	forn(j, 0, deg[i]){
	// 		deg[ adjList[i][j] ]--;
	// 		deg[i]--;
	// 		if(deg[ adjList[i][j] ]==1)	degQ.push(adjList[i][j]);
	// 	}
	// }
	// bool flag=true;
	// forn(j, 0, n*m){
	// 	if(deg[j]){
	// 		flag=false;
	// 		break;
	// 	}	
	// }
	// if(flag==false)	cout<<"Not unique\n";
	// else{
	// 	for(i=0;i<n;i++){
	// 		forn(j, 0, m)	cout<<a[i][j]<<" ";
	// 		cout<<"\n";
	// 	}
	// }
	return 0;
}