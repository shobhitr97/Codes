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
	int n, d, l, r, mid;
	ll L, x[num], v[num];
	vector<pair<double, int> >a;

	cin>>n>>d;
	cin>>L;
	fori(0, n)	cin>>x[i];
	fori(0, n)	cin>>v[i];

	l=0, r=0;
	fori(0, n){
		a.pb(mp((double)(x[i]*v[i])/(double)d, 1));
		a.pb(mp((double)((x[i]-L)*v[i])/(double)d, 0));
		// cout<<(double)(x[i]*v[i])/(double)d<<" "<<(double)((x[i]-L)*v[i])/(double)d<<"\n";
	}
	sort(a.begin(), a.end());

	int tmp, mx;
	tmp=0, mx=0;
	// Overlooking equality - actually 0 will take care of it as 0 < 1
	fori(0, 2*n){
		if(a[i].se==0)	tmp++;
		else	tmp--;
		mx=max(mx, tmp);
	}

	cout<<mx<<"\n";

	return 0;
}