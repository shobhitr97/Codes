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
typedef pair<double, double>pdd;

#define pb push_back
#define mp make_pair
#define fori(a, b) for(int i=a ; i<b ; i++ )
#define forn(i, a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fornn(i, a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define INF 1000000007
#define num 3003

double dp[num][num];
int n;
vector<pdd>pos;

double modulo(int x, int y){
	return sqrt((pos[x].fi-pos[y].fi)*(pos[x].fi-pos[y].fi)+(pos[x].se-pos[y].se)*(pos[x].se-pos[y].se));
}

double calc(int x, int y){
	if(dp[x][y]<INF)	return dp[x][y];
	// cout<<x<<","<<y<<"\n";
	if(x==(n-1)&&y==(n-1))	return 0.0;
	if(y<x-1)	dp[x][y]=min(dp[x][y], modulo(y, y+1)+calc(x, y+1));
	else{
		fori(x+1, n)	dp[x][y]=min(dp[x][y], modulo(x+1, y)+modulo(i, x)+calc(i, x+1));
		fori(x, n){
			if(i==x&&x==y)	continue;
			dp[x][y]=min(dp[x][y], modulo(y, i)+ calc(i, x));
		}
	}
	return dp[x][y];
}

int main(){
	int t=0;
	double x, y;
	vector<double>output;
	while(cin>>n){
		t++;
		fori(0, n){
			cin>>x>>y;
			pos.pb(mp(x, y));
		}
		sort(pos.begin(), pos.end());
		fori(0, n)	forn(j, 0, n)	dp[i][j]=INF;
		output.pb(calc(0, 0));
		pos.clear();
	}
	fori(0, t)	printf("%.2f\n", output[i]);
	return 0;
}