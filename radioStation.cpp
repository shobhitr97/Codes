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
	map <string, string> mp;
	int n, m;
	string x, y, z;

	cin>>n>>m;

	fori(0, n){
		cin>>x>>y;
		y.append(";");
		mp.insert(pair<string, string>(y, x));
		// cout<<x<<"->"<<y<<"\n";
	}

	fori(0, m){
		cin>>x>>y;
		z = mp[y];
		cout<<x<<" "<<y<<" #"<<z<<"\n";
	}

	return 0;
}