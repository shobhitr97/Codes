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

int req[num][num];

int calc(ii x, ii y){
	if(x.fi==0||x.se==0){
		if(x.fi==0&&x.se>0)	return req[y.fi][y.se]-req[y.fi][x.se];
		if(x.fi>0&&x.se==0)	return req[y.fi][y.se]-req[x.fi-1][y.se];
		else	return req[y.fi][y.se];
	}
	else	return req[y.fi][y.se]-req[x.fi-1][y.se]-req[y.fi][x.se-1]+req[x.fi-1][x.se-1];
}

int main(){
	int n, m, arr[num][num], temp, ms, x, u, v;
	ii dp[num][num], nul=mp(-1, -1), lt, br;
	cin>>n>>m>>x;
	fori(0, n)	forn(j, 0, m)	arr[i][j]=0;
	fori(0, x){
		cin>>u>>v;
		arr[u][v]=1;
	}
	if(x==m*n){
		cout<<"0\n";
		return 0;
	}
	// Preprocessing
	req[0][0]=1*(arr[0][0]==1);
	fori(1, m)	req[0][i]=arr[0][i]+req[0][i-1];
	fori(1, n)	req[i][0]=arr[i][0]+req[i-1][0];
	fori(1, n){
		forn(j, 1, m)	req[i][j]=arr[i][j]+req[i-1][j]+req[i][j-1]-req[i-1][j-1];
	}

	// cout<<"\n";
	// fori(0, n){
	// 	forn(j, 0, m)	cout<<arr[i][j]<<" ";
	// 	cout<<"\n";
	// }

	// cout<<"\n";
	// fori(0, n){
	// 	forn(j, 0, m)	cout<<req[i][j]<<" ";
	// 	cout<<"\n";
	// }

	// DP
	lt=br=mp(INF, INF);
	ms=0;
	fori(0, n)	((arr[i][0]==1)?dp[i][0]=nul:dp[i][0]=mp(i, 0));
	fori(0, m)	((arr[0][i]==1)?dp[0][i]=nul:dp[0][i]=mp(0, i));
	fori(1, n){
		forn(j, 1, m){
			if(arr[i][j]==1)	dp[i][j]=nul;
			else{
				ii t=dp[i-1][j-1];
				ii it=mp(i, j);
				if(t==nul)	dp[i][j]=it;
				else{
					temp=calc(t, it);
					while(temp>0&&t!=it){
						t.fi++;
						t.se++;
						temp=calc(t, it);
					}
					dp[i][j]=t;
				}	
			}
		}
	}
	fori(0, n){
		forn(j, 0, m){
			ii it=mp(i, j);
			if(dp[i][j]==nul)	continue;
			temp=i-dp[i][j].fi+1;
			if(temp>=ms){
				if(temp==ms){
					if(dp[i][j].fi<lt.fi)	lt=dp[i][j], br=it;
					else	if(dp[i][j].fi==lt.fi&&dp[i][j].se<lt.se)	lt=dp[i][j], br=it;
				}
				if(temp>ms)	lt=dp[i][j], br=it, ms=temp;
			}
		}
	}
	// cout<<"\n";
	// fori(0, n){
	// 	forn(j, 0, m)	cout<<"("<<dp[i][j].fi<<","<<dp[i][j].se<<"):("<<i<<","<<j<<")	";
	// 	cout<<"\n";
	// }
	cout<<lt.fi<<" "<<lt.se<<" "<<br.fi<<" "<<br.se<<"\n";
	return 0;
}