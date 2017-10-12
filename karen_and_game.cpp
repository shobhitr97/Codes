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
#define num 105

int main(){
	viii consider;
	iii temp;
	vector<pair<string, int> >output;
	priority_queue<iii, vector<iii>, greater<iii> >pq;
	int n, m, g[num][num], minm, row, col, pos, val, difrow[num], difcol[num], t=0, p;
	bool vis[2][num];
	cin>>n>>m;
	p=(m>=n)?1:0;
	fori(1, max(n, m)+1)	vis[0][i]=vis[1][i]=false;
	fori(1, n+1){
		forn(j, 1, m+1)	cin>>g[i][j];
	}
	fori(1, n+1){
		minm=INF;
		forn(j, 1, m+1)	minm=min(minm, g[i][j]);
		// consider.pb(mp(minm, mp(0, i)));
		difrow[i]=minm;
		if(minm>0)	pq.push(mp(minm, mp(1-p, i)));
	}
	fori(1, m+1){
		minm=INF;
		forn(j, 1, n+1)	minm=min(minm, g[j][i]);
		// consider.pb(mp(minm, mp(1, i)));
		difcol[i]=minm;
		if(minm>0)	pq.push(mp(minm, mp(p, i)));
	}
	while(!pq.empty()){
		temp=pq.top();
		pq.pop();
		val=temp.fi;
		pos=temp.se.fi;
		if(vis[pos][temp.se.se]==true)	continue;
		vis[pos][temp.se.se]=true;
		if(pos==p)	col=temp.se.se;
		else	row=temp.se.se;
		if(pos==p){
			// cout<<"col "<<col<<" "<<val<<"\n";
			fori(0, val){
				output.pb(mp("col", col));
				t++;
			}
			fori(1, n+1){
				g[i][col]-=val;
				if(difrow[i]>g[i][col]){
					difrow[i]=g[i][col];
					if(difrow[i]>0)	pq.push(mp(g[i][col], mp(1-p	, i)));
					else	vis[1-p][i]=true;
				}
			}
		}
		else{
			// cout<<"row "<<row<<" "<<val<<"	\n";
			fori(0, val){
				output.pb(mp("row", row));
				t++;
			}
			fori(1, m+1){
				g[row][i]-=val;
				if(difcol[i]>g[row][i]){
					difcol[i]=g[row][i];
					if(difcol[i]>0)	pq.push(mp(g[row][i], mp(p, i)));
					else	vis[p][i]=true;
				}
			}
		}
	}
	fori(1, n+1){
		forn(j, 1, m+1){
			if(g[i][j]){
				// cout<<i<<","<<j<<"\n";
				cout<<"-1\n";
				return 0;
			}
		}
	}
	cout<<t<<"\n";
	for(vector<pair<string, int> >::iterator it=output.begin();it!=output.end();it++)	cout<<(*it).fi<<" "<<(*it).se<<"\n";
	return 0;
}