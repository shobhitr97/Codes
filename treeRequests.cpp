#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <functional>

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
#define num 500*1000+5

vector<vi> graph;
vi bitVal;
int n, m;
bool flag;
int pre[num], post[num];
vector < vii > H;
int tim, hmax;

// int dfs(int vtx, int height){
// 	if(height == ht[vtx]){
// 		// flag = true;
// 		return bitVal[vtx];
// 	}
// 	int siz, val = 0;
// 	siz = graph[vtx].size();
// 	fori(0, siz){
// 		val = val^dfs(graph[vtx][i], height);
// 	}
// 	return val;
// }


void printbits(int val){
	fori(0,26){
		if(val&(1<<i))	cout<<"1";
		else	cout<<"0";
	}
	cout<<"\n";
}

void dfsT(int vertex, int height){

	pre[vertex] = tim++;
	H[height].pb(mp(pre[vertex], bitVal[vertex]));

	int siz = graph[vertex].size();
	fori(0, siz){
		dfsT(graph[vertex][i], height+1);
	}

	post[vertex] = tim++;

}

int binSearch(int h, int val){
	int l, r, mid, ans = 0;
	l = 0;
	r = H[h].size()-1;
	while(l<=r){
		mid = (l+r)/2;
		if(H[h][mid].fi <= val){
			ans = H[h][mid].se;
			l=mid+1;
		}
		else	r = mid-1;
	}
	return ans;
}

int solve(int h, int v){
	int x, y;
	x = binSearch(h, pre[v]-1);
	y = binSearch(h, post[v]);

	// cout<<"\t"<<x<<" "<<y<<"\n";

	return (x^y);
}

int main(){

	int x, t, cnt;
	char ch;

	cin>>n>>m;

	// cout<<n<<" "<<m<<"\n";

	graph.resize(n+1);
	fori(2, n+1){
		scanf("%d", &x);
		graph[x].pb(i);
	}

	bitVal.resize(n+1);
	fori(1, n+1){
		cin>>ch;
		bitVal[i] = (1<<(ch - 'a'));
		// printbits(bitVal[i]);
	}

	H.resize(n+1);
	tim = 0;

	dfsT(1, 1);

	hmax = 1;
	fori(1, n+1){
		if(H[i].size() > 0){
			int siz = H[i].size();
			sort(H[i].begin(), H[i].end());
			hmax = max(hmax, i);
			// cout<<i<<"\n";
			// cout<<H[i][0].se<<" ";
			forn(j, 1, siz){
				// cout<<H[i][j].se<<" ";
				H[i][j].se = H[i][j].se^H[i][j-1].se;
			}
			// cout<<"\n";
		}
	}

	fori(0, m){
		int v, h;
		scanf("%d %d", &v, &h);

		// flag = false;
		// t = dfs(v, h);

		t = solve(h, v);
		cnt = 0;
		forn(j, 0, 26){
			if( (t&(1<<j)) > 0 ){
				ch = 'a'+(j);
				// cout<<ch<<"\n";
				cnt++;
			}
		}

		if(cnt < 2)	cout<<"Yes\n";
		else	cout<<"No\n";

	}

	return 0;
}