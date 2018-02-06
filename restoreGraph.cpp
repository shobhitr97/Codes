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
#define num 100005

int main(){

	int n, k, d[num], maxDist=0, deg[num];
	vi val[num];
	vii edges;

	scanf("%d %d", &n, &k);

	fori(0, n){
		scanf("%d", &d[i]);
	}

	fori(0, n){
		val[ d[i] ].pb(i);
		maxDist = max(maxDist, d[i]);
	}

	fori(0, n)	deg[i] = 0;

	// fori(0, maxDist+1){
	// 	forn(j, 0, val[i].size()){
	// 		cout<<val[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	bool flag = true;

	if(val[0].size() > 1){
		flag = false;
	}
	else{
		fori(1, maxDist+1){
			int sizSource = val[i-1].size();
			int sizDest = val[i].size();

			// cout<<sizDest<<" "<<sizSource<<"\n";
			if(sizSource == 0 || sizDest == 0){
				flag = false;
				break;
			}

			int q = sizDest/sizSource;
			int s = 0;

			forn(j, 0, sizSource){
				forn(k, 0, q){
					edges.pb(mp(val[i-1][j], val[i][s]));
					deg[val[i-1][j]]++;
					deg[val[i][s]]++;
					// cout<<"-->"<<val[i-1][j]<<" "<<val[i][s]<<"\n";
					s++;
				}
			}

			forn(j, s, sizDest){
				edges.pb(mp(val[i-1][j-s], val[i][j]));
				deg[val[i-1][j-s]]++;
				deg[val[i][j]]++;
				// cout<<"**>"<<val[i-1][j-s]<<" "<<val[i][j]<<"\n";
			}

		}
	}

	fori(0, n){
		if(deg[i] > k || deg[i] == 0		)	flag = false;
	}

	if(flag == false)	cout<<"-1\n";
	else{
		cout<<edges.size()<<"\n";
		fori(0, edges.size()){
			cout<<edges[i].fi+1<<" "<<edges[i].se+1<<"\n";
		}
	}

	return 0;
}