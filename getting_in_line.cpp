#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>

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
#define co coordinates

double dist[10][10];
double dp[10][1<<9+2], successor[10][1<<9+2];
int n;

double tsp(int pos, int mask){
	double minm=INF, temp;
	int index;
	fori(0, n){
		if(mask&(1<<i))	continue;
		if(dp[i][mask|(1<<i)]!=(-1))	temp=dist[pos][i]+dp[i][mask|(1<<i)];
		else temp=dist[pos][i]+tsp(i, mask|(1<<i));
		if(temp<minm)	minm=temp, index=i;
	}
	dp[pos][mask]=minm;
	successor[pos][mask]=index;
	return minm;
}

double min(double a, double b){
	if(a<b) return a;
	return b;
}

int main(){
	int t=0, mask, z, pos, k, parent, index;
	double ans, x, y, r, minm, temp;
	vector<pair<double, double> >co;
	vi p;
	z=1;
	while(1){
		cin>>n;
		if(!n)	break;
		fori(0, n){
			cin>>x>>y;
			co.pb(mp(x, y));
		}
		forn(i, 0, n){
			forn(j, i, n){
				x=co[i].fi - co[j].fi;
				y=co[i].se - co[j].se;
				r=sqrt(x*x+y*y);
				dist[i][j]=dist[j][i]=r+16.00;
			}
		}
		forn(i, 0, 1<<n)	forn(j, 0, n)	dp[j][i]=-1;
		fori(0, n)	dp[i][(1<<n)-1]=0;
		ans=INF;
		fori(0, n){
			temp=tsp(i, 1<<i);
			if(temp<ans)	ans=temp, index=i;
		}
		parent=index;
		p.pb(parent);
		mask=1<<parent;
		fori(1, n){
			parent=successor[parent][mask];
			p.pb(parent);
			mask|=(1<<parent);
		}
		cout<<"**********************************************************\n";
		cout<<"Network #"<<z++<<"\n";
		fori(1, n)	printf("Cable requirement to connect (%.0f,%.0f) to (%.0f,%.0f) is %.2f feet.\n", co[ p[i-1] ].fi, co[ p[i-1] ].se, co[ p[i] ].fi, co[ p[i] ].se, dist[ p[i-1] ][ p[i] ]);
		printf("Number of feet of cable required is %.2f.\n", ans);
		co.clear();
		p.clear();
	}
	return 0;
}