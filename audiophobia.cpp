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

int mtrix[104][104];

int main(){
	int c, s, q, t, u, v, d;
	t=0;
	while(1){
		cin>>c>>s>>q;
		if(!c&&!s&&!q)	break;
		if(t>0)	cout<<"\n";
		t++;
		forn(i, 1, c+1){
			forn(j, 1, c+1)	mtrix[i][j]=INF;
		}
		fori(0, s){
			cin>>u>>v>>d;
			mtrix[u][v]=d;
			mtrix[v][u]=d;
		}
		forn(i, 1, c+1){
			forn(j, 1, c+1){
				forn(k, 1, c+1){
					if(mtrix[j][i]!=INF&&mtrix[i][k]!=INF)	mtrix[j][k]=min(mtrix[j][k], max(mtrix[j][i], mtrix[i][k]));
				}
			}
		}
		cout<<"Case #"<<t<<"\n";
		fori(0, q){
			cin>>u>>v;
			if(mtrix[u][v]==INF)	cout<<"no path\n";
			else	cout<<mtrix[u][v]<<"\n";
		}
	}

	return 0;
}