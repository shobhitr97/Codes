#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
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

int main(){

	int T, n, t;
	vector<vi> out;
	vi l, r;

	cin>>T;
	out.resize(T);
	forn(k, 0, T){
		cin>>n;
		l.resize(n);
		r.resize(n);
		fori(0, n)	cin>>l[i]>>r[i];
		t = 1;
		fori(0, n){
			if(t <= l[i]){
				out[k].pb(l[i]);
				t = l[i]+1;
			}
			else{
				if(t > r[i])	out[k].pb(0);
				else{
					out[k].pb(t);
					t++;
				}
			}
		}
		l.clear();
		r.clear();
	}

	fori(0, T){
		int siz = out[i].size();
		forn(j, 0, siz)	cout<<out[i][j]<<" ";
		cout<<"\n";
	}

	return 0;
}