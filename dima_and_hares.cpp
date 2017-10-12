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
#define num 3005

int main(){
	int n;
	ll a[num], b[num], c[num], d[2][num];

	cin>>n;
	fori(0, n)	cin>>a[i];
	fori(0, n)	cin>>b[i];
	fori(0, n)	cin>>c[i];

	d[0][n-1]=a[n-1];
	d[1][n-1]=b[n-1];

	forin(n-2, 0){
		d[0][i]=max(b[i]+d[0][i+1], a[i]+d[1][i+1]);
		d[1][i]=max(c[i]+d[0][i+1], b[i]+d[1][i+1]);
	}

	cout<<d[0][0]<<"\n";
	return 0;
}