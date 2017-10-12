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

int main(){
	int m, x, arr[200005];
	vi a;
	vii b;
	cin>>m;
	fori(0, m){
		cin>>x;
		a.pb(x);
	}
	fori(0, m){
		cin>>x;
		b.pb(mp(x, i));
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	fori(0, m){
		arr[b[i].se]=a[m-1-i];
	}
	fori(0, m)	cout<<arr[i]<<" ";
	cout<<"\n";
	return 0;
}